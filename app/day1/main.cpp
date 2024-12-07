#include <iostream>
#include <vector>
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
    }

    // Part One
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    unsigned int total_distance = 0;
    for (size_t i = 0; i < n_rows; ++i) {
        total_distance += std::abs(list1[i] - list2[i]);
    }

    std::cout << "Total distance for " << n_rows << " rows: " << total_distance << '\n';

    return 0;
}