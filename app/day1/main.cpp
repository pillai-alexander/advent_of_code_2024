#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <cmath>

#include <advent_2024_lib.hpp>

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

    // Part One
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    size_t total_distance = 0;
    for (size_t i = 0; i < n_rows; ++i) {
        total_distance += static_cast<size_t>(std::abs(list1[i] - list2[i]));
    }

    std::cout << "Total distance for " << n_rows << " rows: " << total_distance << '\n';

    // Part Two
    std::map<int, size_t> list2_counts;
    for (const auto& val : list2) {
        if (static_cast<bool>(list2_counts.count(val))) {
            list2_counts.at(val)++;
        } else {
            list2_counts[val] = 1;
        }
    }

    size_t total_similarity = 0;
    for (const auto& val : list1) {
        if (static_cast<bool>(list2_counts.count(val))) {
            total_similarity += static_cast<size_t>(val) * list2_counts.at(val);
        }
    }

    std::cout << "Total similarity for " << n_rows << " rows: " << total_similarity << '\n';

    return 0;
}