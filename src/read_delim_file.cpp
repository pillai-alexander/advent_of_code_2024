#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> read_delim_file(const std::string file, const bool is_whitespace_delim, const char delim) {
    std::ifstream f(file);

    std::vector<std::vector<std::string>> parsed_tokens;
    std::string line;
    std::string token;
    while (std::getline(f, line)) {
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

    f.close();
    return parsed_tokens;
}