#include <vector>
#include <string>

#include <fmt/format.h>

#include <advent_2024_lib.hpp>

std::string look_straight(const std::vector<std::string>& text, const RowColIdx& idxs, const SearchDirection dir, const size_t len) {
    std::string selection;
    for (size_t i = 0; i < len; ++i) {
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

std::string look_diagonal(const std::vector<std::string>& text, const RowColIdx& idxs, const SearchDirection dir, const size_t len) {
    std::string selection;
    for (size_t i = 0; i < len; ++i) {
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

std::string search(const SearchDirection dir, const std::vector<std::string>& text, RowColIdx idxs, const size_t len) {
    switch (dir) {
        case UP:
        case DOWN:
        case LEFT:
        case RIGHT: { return look_straight(text, idxs, dir, len); }
        case UP_LEFT:
        case UP_RIGHT:
        case DOWN_LEFT:
        case DOWN_RIGHT: { return look_diagonal(text, idxs, dir, len); }
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
                const size_t search_len = 4;

                const bool u_match = can_look_up and (search(UP, lines, idxs, search_len) == "XMAS");
                const bool d_match = can_look_down and (search(DOWN, lines, idxs, search_len) == "XMAS");
                const bool l_match = can_look_left and (search(LEFT, lines, idxs, search_len) == "XMAS");
                const bool r_match = can_look_right and (search(RIGHT, lines, idxs, search_len) == "XMAS");
                const bool ul_match = can_look_up and can_look_left and (search(UP_LEFT, lines, idxs, search_len) == "XMAS");
                const bool ur_match = can_look_up and can_look_right and (search(UP_RIGHT, lines, idxs, search_len) == "XMAS");
                const bool dl_match = can_look_down and can_look_left and (search(DOWN_LEFT, lines, idxs, search_len) == "XMAS");
                const bool dr_match = can_look_down and can_look_right and (search(DOWN_RIGHT, lines, idxs, search_len) == "XMAS");

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

size_t day4_part2(const std::vector<std::string>& lines) {
    size_t total_matches = 0;
    for (size_t row = 0; row <= (lines.size() - 3); ++row) {
        for (size_t col = 0; col <= (lines[row].size() - 3); ++col) {
            const RowColIdx top_left = {row, col};
            const RowColIdx top_right = {row, col + 2};
            const size_t search_len = 3;

            const auto tl_diag = search(DOWN_RIGHT, lines, top_left, search_len);
            const auto tr_diag = search(DOWN_LEFT, lines, top_right, search_len);

            const bool tl_match = (tl_diag == "MAS") or (tl_diag == "SAM");
            const bool tr_match = (tr_diag == "MAS") or (tr_diag == "SAM");

            if (tl_match and tr_match) { total_matches++; }
        }
    }

    return total_matches;
}