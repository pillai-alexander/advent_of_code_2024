#include <gtest/gtest.h>

#include <string>
#include <vector>

#include <advent_2024_lib.hpp>

TEST(aoc24_day4, pre_processing) {
    auto data = read_file_lines("data/day4_example.txt");
    EXPECT_EQ(data.size(), 10);
}

TEST(aoc24_day4, part1) {
    auto lines = read_file_lines("data/day4_example.txt");
    const size_t total_matches = day4_part1(lines);
    EXPECT_EQ(total_matches, 18);
}

TEST(aoc24_day4, part2) {
    auto lines = read_file_lines("data/day4_example.txt");
    const size_t total_matches = day4_part2(lines);
    EXPECT_EQ(total_matches, 9);
}