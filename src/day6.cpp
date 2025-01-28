#include <vector>
#include <string>

#include <fmt/format.h>
#include <fmt/ranges.h>

#include <advent_2024_lib.hpp>

size_t day6_part1(const std::vector<std::string>& map) {
    for (const auto& line : map) {
        fmt::println("{}", line);
    }

    return 0;
}