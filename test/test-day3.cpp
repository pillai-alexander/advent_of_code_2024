#include <gtest/gtest.h>

#include <string>
#include <vector>

#include <advent_2024_lib.hpp>

TEST(aoc24_day3, pre_processing) {
    auto data = read_file_lines("data/day3_example.txt");
    EXPECT_EQ(data.size(), 1);
}

TEST(aoc24_day3, part1) {
    auto instructions = read_file_lines("data/day3_example.txt");
    auto total = day3_part1(instructions);
    EXPECT_EQ(total, 161);
}