#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <advent_2024_lib.hpp>

std::vector<std::vector<std::string>> read_delim_file(const std::string& path, const bool is_whitespace_delim, const char delim) {
    std::ifstream file(path);

    std::vector<std::vector<std::string>> parsed_tokens;
    std::string line;
    std::string token;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream line_stream(line);
        if (is_whitespace_delim) {
            while (line_stream >> token) {
                row.push_back(token);
            }
        } else {
            while (std::getline(line_stream, token, delim)) {
                row.push_back(token);
            }
        }
        parsed_tokens.push_back(row);
    }

    file.close();
    return parsed_tokens;
}

std::vector<std::string> read_file_lines(const std::string& path) {
    std::ifstream file(path);

    std::vector<std::string> read_lines;
    std::string line;
    while (std::getline(file, line)) {
        read_lines.push_back(line);
    }

    file.close();
    return read_lines;
}