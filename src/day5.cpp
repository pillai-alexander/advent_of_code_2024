#include <vector>
#include <map>
#include <string>
#include <sstream>

#include <fmt/format.h>

#include <advent_2024_lib.hpp>

PrintData day5_pre_processing(const std::vector<std::string>& lines) {
    std::map<int, int> ordering_instrs;
    std::vector<std::vector<int>> updates;
    for (const auto& line : lines) {
        const std::string::size_type instr_match = line.find("|");
        const bool is_instr = (instr_match != std::string::npos);
        if (is_instr) {
            const auto l_num = line.substr(0, instr_match);
            const auto r_num = line.substr(instr_match + 1, line.size());
            ordering_instrs[std::stoi(l_num)] = std::stoi(r_num);
        } else {
            std::vector<int> page_nums;
            std::stringstream linestream(line);
            std::string token;
            while (std::getline(linestream, token, ',')) {
                page_nums.push_back(std::stoi(token));
            }
            if (page_nums.size() > 0) { updates.push_back(page_nums); }
        }
    }

    return {ordering_instrs, updates};
}