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

int run_challenge(const unsigned int day, const std::string& file) {
    switch (day) {
        case 1: { return day1_challenge(file); }
        case 2: { return day2_challenge(file); }
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