#include <vector>
#include <string>
#include <cassert>

#include <fmt/format.h>
#include <CLI/CLI.hpp>

#include <advent_2024_lib.hpp>

int day1_challenge(const std::string& file) {
    // Data pre-processing
    auto data = read_delim_file(file, true);
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

    const InputLists lists = {list1, list2};

    // Part One
    size_t total_distance = day1_part1(lists);
    fmt::print("Total distance for {} rows: {}\n", n_rows, total_distance);

    // Part Two
    size_t total_similarity = day1_part2(lists);
    fmt::print("Total similarity for {} rows: {}\n", n_rows, total_similarity);

    return 0;
}

int day2_challenge(const std::string& file) {
    auto reports = day2_pre_processing(file);

    // Part One
    auto n_safe_reports = day2_part1(reports);
    fmt::println("Number of safe reports: {}", n_safe_reports);

    // Part Two
    n_safe_reports = day2_part2(reports);
    fmt::println("Number of safe reports with dampening: {}", n_safe_reports);

    return 0;
}

int day3_challenge(const std::string& file) {
    auto instructions = read_file_lines(file);

    // Part One
    int total_result = day3_part1(instructions);
    fmt::println("Total product: {}", total_result);

    // Part Two
    total_result = day3_part2(instructions);
    fmt::println("Total product with conditionals: {}", total_result);

    return 0;
}

std::string look_behind(const std::vector<std::string>& text, size_t mut_idx,
                       const size_t& cnst_idx, bool up_down) {
    std::string selection;
    for (size_t i = mut_idx; i >= (mut_idx - 3); --i) {
        selection += (up_down) ? text[i][cnst_idx] : text[cnst_idx][i];
        if (i == 0) break;
    }

    return selection;
}

std::string look_ahead(const std::vector<std::string>& text, size_t mut_idx,
                       const size_t& cnst_idx, bool up_down) {
    std::string selection;
    for (size_t i = mut_idx; i <= (mut_idx + 3); ++i) {
        selection += (up_down) ? text[i][cnst_idx] : text[cnst_idx][i];
        if (i == text.size()) break;
    }

    return selection;
}

enum SearchDirection{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NUM_SEARCH_DIRECTIONS
};

std::string search(const SearchDirection dir, const std::vector<std::string>& text,
                   size_t mut_idx, const size_t& cnst_idx) {
    switch (dir) {
        case UP:    { return look_behind(text, mut_idx, cnst_idx, true); }
        case DOWN:  { return look_ahead(text, mut_idx, cnst_idx, true); }
        case LEFT:  { return look_behind(text, mut_idx, cnst_idx, false); }
        case RIGHT: { return look_ahead(text, mut_idx, cnst_idx, false); }
        case NUM_SEARCH_DIRECTIONS:
        default: {
            fmt::println("ERROR: Invalid search direction.");
            return std::string("");
        }
    }
}

int day4_challenge(const std::string& file) {
    auto lines = read_file_lines(file);

    for (size_t row = 0; row < lines.size(); ++row) {
        for (size_t col = 0; col < lines[row].size(); ++col) {
            const char letter = lines[row][col];
            if (letter == 'X') {
                const int i_row = static_cast<int>(row);
                const int i_col = static_cast<int>(col);
                const int nrows = static_cast<int>(lines.size());
                const int ncols = static_cast<int>(lines[row].size());

                const bool can_look_up    = (i_row - 3) >= 0;
                const bool can_look_down  = (i_row + 3) < nrows;
                const bool can_look_left  = (i_col - 3) >= 0;
                const bool can_look_right = (i_col + 3) < ncols;

                fmt::println("{} @ ({},{}): u({}), d({}), l({}), r({})",
                    letter, row, col, can_look_up, can_look_down, can_look_left, can_look_right);

                if (can_look_up) {
                    std::string selection = search(UP, lines, row, col);
                    if (selection == "XMAS") {
                        fmt::println("\tu({})", selection);
                    }
                }

                if (can_look_down) {
                    std::string selection = search(DOWN, lines, row, col);
                    if (selection == "XMAS") {
                        fmt::println("\td({})", selection);
                    }
                }

                if (can_look_left) {
                    std::string selection = search(LEFT, lines, col, row);
                    if (selection == "XMAS") {
                        fmt::println("\tl({})", selection);
                    }
                }

                if (can_look_right) {
                    std::string selection = search(RIGHT, lines, col, row);
                    if (selection == "XMAS") {
                        fmt::println("\tr({})", selection);
                    }
                }
            }
        }
    }

    return 0;
}

int run_challenge(const unsigned int day, const std::string& file) {
    switch (day) {
        case 1: { return day1_challenge(file); }
        case 2: { return day2_challenge(file); }
        case 3: { return day3_challenge(file); }
        case 4: { return day4_challenge(file); }
        default: { return 0; }
    }
}

int main(int argc, char *argv[]) {
    // Setup
    CLI::App app{"Advent of Code (2024) Challenges"};

    unsigned int day{0};
    app.add_option("-d,--day", day, "Challenge day (required)")
        ->required();

    std::string file_path;
    app.add_option("-f,--file", file_path, "Input data file path (required)")
        ->required()
        ->check(CLI::ExistingFile);

    CLI11_PARSE(app, argc, argv);

    return run_challenge(day, file_path);
}