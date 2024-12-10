#include <vector>
#include <string>

#include <advent_2024_lib.hpp>

std::vector<std::vector<int>> day2_pre_processing(const std::string& path) {
    auto data = read_delim_file(path, true);
    std::vector<std::vector<int>> reports(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        for (const auto& s : data[i]) {
            reports[i].push_back(std::stoi(s));
        }
    }
    return reports;
}