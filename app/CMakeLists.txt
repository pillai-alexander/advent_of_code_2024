add_executable(aoc24_challenges main.cpp)

target_link_libraries(aoc24_challenges PRIVATE advent_2024_library)

set_target_properties(aoc24_challenges
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
)