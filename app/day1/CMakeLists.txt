add_executable(day1 main.cpp)

target_link_libraries(day1 PRIVATE advent_2024_library)

set_target_properties(day1
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
)