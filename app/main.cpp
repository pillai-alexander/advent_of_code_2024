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

int day4_challenge(const std::string& file) {
    auto lines = read_file_lines(file);

    // Part One
    size_t total_matches = day4_part1(lines);
    fmt::println("Total XMAS matches: {}", total_matches);

    total_matches = day4_part2(lines);
    fmt::println("Total X-MAS matches: {}", total_matches);

    return 0;
}

int day5_challenge(const std::string& file) {
    auto lines = read_file_lines(file);
    auto print_data = day5_pre_processing(lines);

    size_t middle_page_sum = day5_part1(print_data);
    fmt::println("Middle page-number sum: {}", middle_page_sum);

    middle_page_sum = day5_part2(print_data);
    fmt::println("Middle page-number sum: {}", middle_page_sum);

    return 0;
}

int run_challenge(const unsigned int day, const std::string& file) {
    const std::vector<int (*)(const std::string&)> challenges{
        day1_challenge,
        day2_challenge,
        day3_challenge,
        day4_challenge,
        day5_challenge
    };

    return challenges[day - 1](file);
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