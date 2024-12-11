#include <gtest/gtest.h>

#include <string>
#include <vector>

#include <advent_2024_lib.hpp>

TEST(aoc24_day2, pre_processing) {
    auto data = day2_pre_processing("data/day2_example.txt");
    EXPECT_EQ(data.size(), 6);
}

TEST(aoc24_day2, part1) {
    auto reports = day2_pre_processing("data/day2_example.txt");
    auto n_safe_reports = day2_part1(reports);

    EXPECT_EQ(n_safe_reports, 2);
}

TEST(aoc24_day2, part2) {
    auto reports = day2_pre_processing("data/day2_example.txt");
    auto n_safe_reports = day2_part2(reports);

    EXPECT_EQ(n_safe_reports, 4);
}