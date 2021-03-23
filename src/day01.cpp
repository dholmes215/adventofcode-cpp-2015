// Copyright (C) 2021 David Holmes <dholmes@dholmes.us>. All rights reserved.
#include "aoc.hpp"

#include <fstream>
#include <iostream>
#include <optional>

struct day01_result {
    int final_floor{};
    std::optional<int> first_position_in_basement{};
};

day01_result process_input(std::istream& file)
{
    int floor{0};
    int position{1};
    std::optional<int> first_position_in_basement{};
    for (const char c : istream_range{file}) {
        if (c == '(') {
            floor++;
        }
        else if (c == ')') {
            floor--;
        }
        else if (!is_whitespace(c)) {
            std::cerr << "Read unexpected input character '" << c << "'.\n";
        }
        if (floor < 0 && !first_position_in_basement) {
            first_position_in_basement = position;
        }
        position++;
    }

    return {floor, first_position_in_basement};
}

int main(int argc, char** argv)
{
    auto file = open_file(argc, argv);
    const auto result = process_input(file);

    std::cout << "Part 1: Elevator stops on floor " << result.final_floor
              << '\n';
    if (result.first_position_in_basement) {
        std::cout
            << "Part 2: Position of first character that entered basement is "
            << *result.first_position_in_basement << '\n';
    }
    else {
        std::cout << "Part 2: Santa did not enter basement.\n";
    }
}
