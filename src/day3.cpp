#include <vector>
#include <string>
#include <regex>

#include <advent_2024_lib.hpp>

int day3_part1(const std::vector<std::string>& instructions) {
    const std::regex mul_pattern("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");
    int total_result = 0;
    for (const auto& line : instructions) {
        auto search_start = std::sregex_iterator(line.begin(), line.end(), mul_pattern);
        auto search_end = std::sregex_iterator();

        for (std::sregex_iterator i = search_start; i != search_end; ++i) {
            const auto& match = *i;
            const auto l_val = std::stoi(match[1].str());
            const auto r_val = std::stoi(match[2].str());
            total_result += l_val * r_val;
        }
    }
    return total_result;
}

int day3_part2(const std::vector<std::string>& instructions) {
    const std::regex main_pattern(R"(mul\(([0-9]{1,3}),([0-9]{1,3})\)|do\(\)|don't\(\))");
    int total_result = 0;
    bool exec_mul = true;
    for (const auto& line : instructions) {
        auto search_start = std::sregex_iterator(line.begin(), line.end(), main_pattern);
        auto search_end = std::sregex_iterator();

        for (std::sregex_iterator i = search_start; i != search_end; ++i) {
            const auto& match = *i;
            const auto sub_str = match.str().substr(0, 3);
            const bool is_mul = sub_str == "mul";
            if (not is_mul) { exec_mul = (sub_str != "don"); }

            if (is_mul and exec_mul) {
                const auto l_val = std::stoi(match[1].str());
                const auto r_val = std::stoi(match[2].str());
                total_result += l_val * r_val;
            }
        }
    }
    return total_result;
}