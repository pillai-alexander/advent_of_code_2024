#pragma once

#include <vector>
#include <string>

// Utilities
std::vector<std::vector<std::string>> read_delim_file(const std::string& path, const bool is_whitespace_delim = false, const char delim = ',');
std::vector<std::string> read_file_lines(const std::string& path);

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

// Day Three
int day3_part1(const std::vector<std::string>& instructions);
int day3_part2(const std::vector<std::string>& instructions);

// Day Four
enum SearchDirection{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UP_LEFT,
    UP_RIGHT,
    DOWN_LEFT,
    DOWN_RIGHT,
    NUM_SEARCH_DIRECTIONS
};

struct RowColIdx { size_t row; size_t col; };

std::string look_straight(const std::vector<std::string>& text, const RowColIdx& idxs, const SearchDirection dir);
std::string look_diagonal(const std::vector<std::string>& text, const RowColIdx& idxs, const SearchDirection dir);
std::string search(const SearchDirection dir, const std::vector<std::string>& text, RowColIdx idxs);
size_t day4_part1(const std::vector<std::string>& lines);