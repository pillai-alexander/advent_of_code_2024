#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>

#include <advent_2024_lib.hpp>

PrintData day5_pre_processing(const std::vector<std::string>& lines) {
    std::unordered_map<int, std::unordered_set<int>> ordering_instrs;
    std::vector<std::vector<int>> updates;
    for (const auto& line : lines) {
        const std::string::size_type instr_match = line.find("|");
        const bool is_instr = (instr_match != std::string::npos);
        if (is_instr) {
            const auto l_num = line.substr(0, instr_match);
            const auto r_num = line.substr(instr_match + 1, line.size());
            ordering_instrs[std::stoi(l_num)].insert(std::stoi(r_num));
        } else {
            std::vector<int> page_nums;
            std::stringstream linestream(line);
            std::string token;
            while (std::getline(linestream, token, ',')) {
                page_nums.push_back(std::stoi(token));
            }
            if (not page_nums.empty()) { updates.push_back(page_nums); }
        }
    }

    return {ordering_instrs, updates};
}

bool valid_order(const PagePair& pages, const std::unordered_map<int, std::unordered_set<int>>& order_instrs) {
    // should find second in first's orderings
    const bool first_before_second = (order_instrs.count(pages.first_page) == 1)
                                         ? (order_instrs.at(pages.first_page).count(pages.second_page) == 1)
                                         : false;

    // shouldn't find first in second's orderings
    const bool second_before_first = (not first_before_second)
                                         ? (order_instrs.at(pages.second_page).count(pages.first_page) == 1)
                                         : false;

    return (first_before_second and not second_before_first);
}

bool valid_update(const std::vector<int>& update, const std::unordered_map<int, std::unordered_set<int>>& order_instrs) {
    bool valid_update = true;
    for (size_t i = 0; i < (update.size() - 1); ++i) {
        const PagePair pages = {update.at(i), update.at(i + 1)};
        valid_update = valid_order(pages, order_instrs);
        if (not valid_update) { return false; }
    }

    // if here, update has valid page order
    return valid_update;
}

size_t day5_part1(const PrintData& print_data) {
    const auto& order_instrs = print_data.ordering_instrs;
    size_t middle_page_sum = 0;
    for (const auto& update : print_data.updates) {
        if (valid_update(update, order_instrs)) {
            const auto mid = update.size() / 2;
            const auto midpage = static_cast<size_t>(update.at(mid));
            middle_page_sum += midpage;
        }
    }
    return middle_page_sum;
}