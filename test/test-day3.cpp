#include <gtest/gtest.h>

#include <string>
#include <vector>

#include <advent_2024_lib.hpp>

TEST(aoc24_day3, pre_processing) {
    auto data = read_file_lines("data/day3_example1.txt");
    EXPECT_EQ(data.size(), 1);

    data = read_file_lines("data/day3_example2.txt");
    EXPECT_EQ(data.size(), 1);
}

TEST(aoc24_day3, part1) {
    auto instructions = read_file_lines("data/day3_example1.txt");
    auto total = day3_part1(instructions);
    EXPECT_EQ(total, 161);
}

TEST(aoc24_day3, part2) {
    auto instructions = read_file_lines("data/day3_example2.txt");
    auto total = day3_part2(instructions);
    EXPECT_EQ(total, 48);
}