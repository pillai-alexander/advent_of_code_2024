#pragma once

#include <vector>
#include <string>

std::vector<std::vector<std::string>> read_delim_file(const std::string& path, const bool is_whitespace_delim = false, const char delim = ',');

// Day One
struct InputLists { std::vector<int> left_list; std::vector<int> right_list; };
size_t day1_part1(InputLists input);
size_t day1_part2(const InputLists& input);