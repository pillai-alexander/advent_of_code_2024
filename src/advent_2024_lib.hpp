#pragma once

#include <vector>
#include <string>

std::vector<std::vector<std::string>> read_delim_file(const std::string file, const bool is_whitespace_delim = false, const char delim = ',');