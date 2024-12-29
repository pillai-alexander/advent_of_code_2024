#include <gtest/gtest.h>

#include <string>
#include <vector>

#include <advent_2024_lib.hpp>

TEST(aoc24_day5, pre_processing) {
    auto data = read_file_lines("data/day5_example.txt");
    EXPECT_EQ(data.size(), 28);

    auto print_data = day5_pre_processing(data);
    EXPECT_EQ(print_data.ordering_instrs.size(), 6);
    EXPECT_EQ(print_data.updates.size(), 6);
}

TEST(aoc24_day5, part1) {
    auto lines = read_file_lines("data/day5_example.txt");
    auto print_data = day5_pre_processing(lines);
    const size_t middle_page_sum = day5_part1(print_data);
    EXPECT_EQ(middle_page_sum, 143);
}

TEST(aoc24_day5, part2) {
    auto lines = read_file_lines("data/day5_example.txt");
    auto print_data = day5_pre_processing(lines);
    const size_t middle_page_sum = day5_part2(print_data);
    EXPECT_EQ(middle_page_sum, 123);
}