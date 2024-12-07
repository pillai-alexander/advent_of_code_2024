#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#include <advent_2024_lib.hpp>

int main() {
    auto data = read_delim_file("example_input.txt", true);
    for (const auto& row : data) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }

    std::vector<int> list1(data.size());
    std::vector<int> list2(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        assert(data[i].size() == 2);
        list1[i] = std::stoi(data[i].front());
        list2[i] = std::stoi(data[i].back());
    }

    return 0;
}