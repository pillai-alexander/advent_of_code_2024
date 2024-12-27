#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
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

std::string look_straight(const std::vector<std::string>& text, const RowColIdx& idxs, const SearchDirection dir, const size_t len);
std::string look_diagonal(const std::vector<std::string>& text, const RowColIdx& idxs, const SearchDirection dir, const size_t len);
std::string search(const SearchDirection dir, const std::vector<std::string>& text, RowColIdx idxs, const size_t len);

size_t day4_part1(const std::vector<std::string>& lines);
size_t day4_part2(const std::vector<std::string>& lines);

// Day Five
struct PrintData {
    std::unordered_map<int, std::unordered_set<int>> ordering_instrs;
    std::vector<std::vector<int>> updates;
};

struct PagePair{ int first_page; int second_page; };

PrintData day5_pre_processing(const std::vector<std::string>& lines);
bool valid_order(const PagePair& pages, const std::unordered_map<int, std::unordered_set<int>>& order_instrs);
bool valid_update(const std::vector<int>& update, const std::unordered_map<int, std::unordered_set<int>>& order_instrs);

size_t day5_part1(const PrintData& print_data);