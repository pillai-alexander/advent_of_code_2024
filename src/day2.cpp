#include <vector>
#include <string>
#include <cmath>

#include <fmt/format.h>
#include <fmt/ranges.h>

#include <advent_2024_lib.hpp>

std::vector<std::vector<int>> day2_pre_processing(const std::string& path) {
    auto data = read_delim_file(path, true);
    std::vector<std::vector<int>> reports(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        for (const auto& str_value : data[i]) {
            reports[i].push_back(std::stoi(str_value));
        }
    }
    return reports;
}

bool is_safe_report(const std::vector<int>& report) {
    const bool should_increase = report.back() > report.front();
    for (size_t i = 1; i < report.size(); ++i) {
        const auto l_level = report[i - 1];
        const auto r_level = report[i];
        const auto delta   = r_level - l_level;
        const auto dist    = std::abs(delta);

        if ((dist < 1) or (dist > 3)) { return false; }
        if (should_increase) {
            if (delta < 0) { return false; }
        } else {
            if (delta > 0) { return false; }
        }
    }
    return true;
}

bool safe_if_one_level_removed(const std::vector<int>& report) {
    std::vector<std::vector<int>> modified_reports(report.size(), report);
    int index_to_remove = 0;
    for (auto& mod_rep : modified_reports) {
        const auto& pos_to_remove = mod_rep.begin() + index_to_remove;
        mod_rep.erase(pos_to_remove);
        index_to_remove++;

        if (is_safe_report(mod_rep)) { return true; }
    }
    return false;
}

size_t day2_part1(const std::vector<std::vector<int>>& reports) {
    size_t n_safe_reports = 0;
    for (const auto& report : reports) {
        // cppcheck-suppress useStlAlgorithm
        if (is_safe_report(report)) { n_safe_reports++; }
    }
    return n_safe_reports;
}

size_t day2_part2(const std::vector<std::vector<int>>& reports) {
    size_t n_safe_reports = 0;
    for (const auto& report : reports) {
        // cppcheck-suppress useStlAlgorithm
        if (is_safe_report(report) or safe_if_one_level_removed(report)) { n_safe_reports++; }
    }
    return n_safe_reports;
}