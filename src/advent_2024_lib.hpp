#pragma once

#include <vector>
#include <string>

std::vector<std::vector<std::string>> read_delim_file(const std::string& path, const bool is_whitespace_delim = false, const char delim = ',');

// Day One
struct InputLists { std::vector<int> left_list; std::vector<int> right_list; };
size_t day1_part1(InputLists input);
size_t day1_part2(const InputLists& input);

// Day Two
std::vector<std::vector<int>> day2_pre_processing(const std::string& path);
bool is_safe_report(const std::vector<int>& report);
bool safe_if_one_level_removed(const std::vector<int>& report);
size_t day2_part1(const std::vector<std::vector<int>>& reports);
size_t day2_part2(const std::vector<std::vector<int>>& reports);