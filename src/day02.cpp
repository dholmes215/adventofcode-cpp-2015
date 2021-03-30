// Copyright (C) 2021 David Holmes <dholmes@dholmes.us>. All rights reserved.
#include "aoc.hpp"

#include <algorithm>
#include <array>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using Feet = int;
using SqFt = int;

// Dimensions of a box (in feet)
struct box {
    box(Feet l, Feet w, Feet h) : length(l), width(w), height(h) {}
    Feet length;
    Feet width;
    Feet height;
};

box box_from_string(const char* s)
{
    const char* start{s};
    char* end{};
    Feet l{static_cast<Feet>(std::strtol(start, &end, 10))};
    start = end + 1;
    Feet w{static_cast<Feet>(std::strtol(start, &end, 10))};
    start = end + 1;
    Feet h{static_cast<Feet>(std::strtol(start, &end, 10))};
    return {l, w, h};
}

// Calculate wrapping paper required for a single box.
SqFt paper_required(const box& b)
{
    std::array<SqFt, 3> side_areas{b.length * b.width, b.length * b.height,
                                   b.width * b.height};
    std::sort(begin(side_areas), end(side_areas));

    SqFt paper = side_areas[0] * 3  // smallest side
                 + side_areas[1] * 2 + side_areas[2] * 2;
    return paper;
}

// Calculate ribbon required for a single box.
Feet ribbon_required(const box& b)
{
    std::array<Feet, 3> side_perimeters{2 * (b.length + b.width),
                                        2 * (b.length + b.height),
                                        2 * (b.width + b.height)};
    Feet shortest_perimeter =
        *std::min_element(begin(side_perimeters), end(side_perimeters));
    Feet bow = b.length * b.width * b.height;
    Feet ribbon = shortest_perimeter + bow;
    return ribbon;
}

int main(int argc, char** argv)
{
    auto file = open_file(argc, argv);
    const auto lines = read_lines(file);

    SqFt total_paper_required{0};
    Feet total_ribbon_required{0};
    for (const auto& line : lines) {
        const box b{box_from_string(line.c_str())};
        total_paper_required += paper_required(b);
        total_ribbon_required += ribbon_required(b);
    }

    std::cout << "Part 1: Total paper required: " << total_paper_required
              << " square feet\n";
    std::cout << "Part 2: Total ribbon required: " << total_ribbon_required
              << " feet\n";
}
