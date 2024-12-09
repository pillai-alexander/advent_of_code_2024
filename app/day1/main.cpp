#include <vector>
#include <string>
#include <cassert>

#include <fmt/format.h>
#include <CLI/CLI.hpp>

#include <advent_2024_lib.hpp>

int main(int argc, char *argv[]) {
    // Setup
    CLI::App app{"Advent of Code (2024) Day One"};

    std::string file_path;
    app.add_option("-f,--file", file_path, "Required input data file path")
        ->required()
        ->check(CLI::ExistingFile);

    CLI11_PARSE(app, argc, argv);

    // Data pre-processing
    auto data = read_delim_file(file_path, true);
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