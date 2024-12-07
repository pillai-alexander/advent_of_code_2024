cmake_minimum_required(VERSION 3.21)

# Only set the cxx_standard if it is not set by someone else
if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the project name and language
project(
  advent_of_code_2024
  VERSION 0.0.1
  DESCRIPTION "ANP Advent of Code 2024 repo"
  LANGUAGES CXX
)

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE
      RelWithDebInfo
      CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui, ccmake
  set_property(
    CACHE CMAKE_BUILD_TYPE
    PROPERTY STRINGS
             "Debug"
             "Release"
             "MinSizeRel"
             "RelWithDebInfo")
endif()
# Generate compile_commands.json to make it easier to work with clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Project-level options
option(AOC24_WARNINGS_AS_ERRORS "Build with warnings treated as errors" OFF)
option(AOC24_PEDANTIC_WARNINGS  "Build with as many reasonable warnings enabled" OFF)
option(AOC24_ENABLE_CLANG_TIDY  "Enable clang-tidy support" OFF)

if(PROJECT_IS_TOP_LEVEL)
  set(AOC24_WARNINGS_AS_ERRORS ON)
  set(AOC24_PEDANTIC_WARNINGS ON)
  set(AOC24_ENABLE_CLANG_TIDY ON)
endif()

# If the environment has these set, pull them into proper variables.
set(CLANG_WARNINGS ${CLANG_COMPILE_FLAGS})
set(GCC_WARNINGS   ${GCC_COMPILE_FLAGS})

if(AOC24_WARNINGS_AS_ERRORS)
  list(APPEND CLANG_WARNINGS -Werror)
  list(APPEND GCC_WARNINGS -Werror)
endif()

if(AOC24_PEDANTIC_WARNINGS)
  list(APPEND CLANG_WARNINGS
    -Wall
    -Wextra # reasonable and standard
    -Wshadow # warn the user if a variable declaration shadows one from a parent context
    -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor. This helps catch hard to track down memory errors
    -Wold-style-cast # warn for c-style casts
    -Wcast-align # warn for potential performance problem casts
    -Wunused # warn on anything being unused
    -Woverloaded-virtual # warn if you overload (not override) a virtual function
    -Wpedantic # warn if non-standard C++ is used
    -Wconversion # warn on type conversions that may lose data
    -Wsign-conversion # warn on sign conversions
    -Wnull-dereference # warn if a null dereference is detected
    -Wdouble-promotion # warn if float is implicit promoted to double
    -Wformat=2 # warn on security issues around functions that format output (ie printf)
    -Wimplicit-fallthrough # warn on statements that fallthrough without an explicit annotation
  )

  list(APPEND GCC_WARNINGS
    ${CLANG_WARNINGS}
    -Wmisleading-indentation # warn if indentation implies blocks where blocks do not exist
    -Wduplicated-cond # warn if if / else chain has duplicated conditions
    -Wduplicated-branches # warn if if / else branches have duplicated code
    -Wlogical-op # warn about logical operations being used where bitwise were probably wanted
    -Wuseless-cast # warn if you perform a cast to the same type
    -Wsuggest-override # warn if an overridden member function is not marked 'override' or 'final'
  )
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:${CLANG_WARNINGS}>")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:${GCC_WARNINGS}>")
endif()

if(AOC24_ENABLE_CLANG_TIDY)
  find_program(CLANGTIDY clang-tidy)
  if(CLANGTIDY)
    # construct the clang-tidy command line
    set(CLANG_TIDY_OPTIONS
      ${CLANGTIDY}
      -extra-arg=-Wno-unknown-warning-option
      -extra-arg=-Wno-ignored-optimization-argument
      -extra-arg=-Wno-unused-command-line-argument
      -p
      -extra-arg=-std=c++${CMAKE_CXX_STANDARD}
    )

    # set warnings as errors
    if(AOC24_WARNINGS_AS_ERRORS)
      list(APPEND CLANG_TIDY_OPTIONS -warnings-as-errors=*)
    endif()

    message("-- Also setting clang-tidy globally")
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_OPTIONS})
  else()
    message(${WARNING_MESSAGE} "clang-tidy requested but executable not found")
  endif()
endif()

add_subdirectory(src)

add_subdirectory(app)