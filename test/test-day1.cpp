#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include <advent_2024_lib.hpp>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(aoc24_example_input, day1) {
    // Data pre-processing
    auto data = read_delim_file("data/day1_example.txt", true);
    const size_t n_rows = data.size();

    std::vector<int> list1(n_rows);
    std::vector<int> list2(n_rows);
    for (size_t i = 0; i < n_rows; ++i) {
        assert(data[i].size() == 2);

        list1[i] = std::stoi(data[i].front());
        list2[i] = std::stoi(data[i].back());

        assert(list1[i] >= 0);
        assert(list2[i] >= 0);
    }

    const InputLists lists = {list1, list2};

    EXPECT_EQ(day1_part1(lists), 11);
}

TEST(aoc24_example_input, day2) {
    // Data pre-processing
    auto data = read_delim_file("data/day1_example.txt", true);
    const size_t n_rows = data.size();

    std::vector<int> list1(n_rows);
    std::vector<int> list2(n_rows);
    for (size_t i = 0; i < n_rows; ++i) {
        assert(data[i].size() == 2);

        list1[i] = std::stoi(data[i].front());
        list2[i] = std::stoi(data[i].back());

        assert(list1[i] >= 0);
        assert(list2[i] >= 0);
    }

    const InputLists lists = {list1, list2};

    EXPECT_EQ(day1_part2(lists), 31);
}