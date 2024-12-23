#include <vector>
#include <string>

#include <fmt/format.h>

#include <advent_2024_lib.hpp>

std::string look_straight(const std::vector<std::string>& text, const RowColIdx& idxs, const SearchDirection dir) {
    std::string selection;
    for (size_t i = 0; i < 4; ++i) {
        switch (dir) {
            case UP:    { selection += text[idxs.row - i][idxs.col]; break; }
            case DOWN:  { selection += text[idxs.row + i][idxs.col]; break; }
            case LEFT:  { selection += text[idxs.row][idxs.col - i]; break; }
            case RIGHT: { selection += text[idxs.row][idxs.col + i]; break; }
            default: {
                fmt::println("ERROR: Invalid straight search direction.");
                return {""};
            }
        }
    }

    return selection;
}

std::string look_diagonal(const std::vector<std::string>& text, const RowColIdx& idxs, const SearchDirection dir) {
    std::string selection;
    for (size_t i = 0; i < 4; ++i) {
        switch (dir) {
            case UP_LEFT:    { selection += text[idxs.row - i][idxs.col - i]; break; }
            case UP_RIGHT:   { selection += text[idxs.row - i][idxs.col + i]; break; }
            case DOWN_LEFT:  { selection += text[idxs.row + i][idxs.col - i]; break; }
            case DOWN_RIGHT: { selection += text[idxs.row + i][idxs.col + i]; break; }
            default: {
                fmt::println("ERROR: Invalid diagonal search direction.");
                return {""};
            }
        }
    }

    return selection;
}

std::string search(const SearchDirection dir, const std::vector<std::string>& text, RowColIdx idxs) {
    switch (dir) {
        case UP:
        case DOWN:
        case LEFT:
        case RIGHT: { return look_straight(text, idxs, dir); }
        case UP_LEFT:
        case UP_RIGHT:
        case DOWN_LEFT:
        case DOWN_RIGHT: { return look_diagonal(text, idxs, dir); }
        case NUM_SEARCH_DIRECTIONS:
        default: {
            fmt::println("ERROR: Invalid search direction.");
            return {""};
        }
    }
}

size_t day4_part1(const std::vector<std::string>& lines) {
    size_t total_matches = 0;
    for (size_t row = 0; row < lines.size(); ++row) {
        for (size_t col = 0; col < lines[row].size(); ++col) {
            const char letter = lines[row][col];
            if (letter == 'X') {
                const int i_row = static_cast<int>(row);
                const int i_col = static_cast<int>(col);
                const int nrows = static_cast<int>(lines.size());
                const int ncols = static_cast<int>(lines[row].size());

                const bool can_look_up    = (i_row - 3) >= 0;
                const bool can_look_down  = (i_row + 3) < nrows;
                const bool can_look_left  = (i_col - 3) >= 0;
                const bool can_look_right = (i_col + 3) < ncols;
                
                const RowColIdx idxs = {row, col};

                const bool u_match = can_look_up and (search(UP, lines, idxs) == "XMAS");
                const bool d_match = can_look_down and (search(DOWN, lines, idxs) == "XMAS");
                const bool l_match = can_look_left and (search(LEFT, lines, idxs) == "XMAS");
                const bool r_match = can_look_right and (search(RIGHT, lines, idxs) == "XMAS");
                const bool ul_match = can_look_up and can_look_left and (search(UP_LEFT, lines, idxs) == "XMAS");
                const bool ur_match = can_look_up and can_look_right and (search(UP_RIGHT, lines, idxs) == "XMAS");
                const bool dl_match = can_look_down and can_look_left and (search(DOWN_LEFT, lines, idxs) == "XMAS");
                const bool dr_match = can_look_down and can_look_right and (search(DOWN_RIGHT, lines, idxs) == "XMAS");

                total_matches += static_cast<size_t>(u_match)
                                 + static_cast<size_t>(d_match)
                                 + static_cast<size_t>(l_match)
                                 + static_cast<size_t>(r_match)
                                 + static_cast<size_t>(ul_match)
                                 + static_cast<size_t>(ur_match)
                                 + static_cast<size_t>(dl_match)
                                 + static_cast<size_t>(dr_match);
            }
        }
    }

    return total_matches;
}