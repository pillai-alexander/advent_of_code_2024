#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <cmath>

#include <advent_2024_lib.hpp>
#include <fmt/core.h>
#include <CLI/CLI.hpp>

int main() {
    // Data pre-processing
    auto data = read_delim_file("day1_input.txt", true);
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

    InputLists lists = {list1, list2};

    std::cout << "Total distance for " << n_rows << " rows: " << total_distance << '\n';
    // Part One
    size_t total_distance = day1_part1(lists);

    // Part Two
        }
    }

    std::cout << "Total similarity for " << n_rows << " rows: " << total_similarity << '\n';
    size_t total_similarity = day1_part2(lists);

    return 0;
}