add_library(advent_2024_library
  read_delim_file.cpp
  advent_2024_lib.hpp
)

target_include_directories(advent_2024_library PUBLIC .)

target_link_libraries(advent_2024_library CLI11::CLI11 fmt::fmt)