#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <cmath>

#include <advent_2024_lib.hpp>

size_t day1_part1(InputLists input) {
    assert(input.left_list.size() == input.right_list.size());
    const size_t n_rows = input.left_list.size();
    std::sort(input.left_list.begin(), input.left_list.end());
    std::sort(input.right_list.begin(), input.right_list.end());

    size_t total_distance = 0;
    for (size_t i = 0; i < n_rows; ++i) {
        // cppcheck-suppress useStlAlgorithm
        total_distance += static_cast<size_t>(std::abs(input.left_list[i] - input.right_list[i]));
    }

    return total_distance;
}

size_t day1_part2(const InputLists& input) {
    std::map<int, size_t> right_list_counts;
    for (const auto& val : input.right_list) {
        if (static_cast<bool>(right_list_counts.count(val))) {
            right_list_counts.at(val)++;
        } else {
            right_list_counts[val] = 1;
        }
    }

    size_t total_similarity = 0;
    for (const auto& val : input.left_list) {
        if (static_cast<bool>(right_list_counts.count(val))) {
            // cppcheck-suppress useStlAlgorithm
            total_similarity += static_cast<size_t>(val) * right_list_counts.at(val);
        }
    }

    return total_similarity;
}