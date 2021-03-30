// Copyright (C) 2021 David Holmes <dholmes@dholmes.us>. All rights reserved.
#include "aoc.hpp"
#include "vec.hpp"

#include <iostream>
#include <optional>
#include <set>

using Vec = vec2<int>;

std::optional<Vec> get_movement(const char c)
{
    if (c == '<') {
        return {{-1, 0}};
    }
    else if (c == '>') {
        return {{1, 0}};
    }
    else if (c == '^') {
        return {{0, 1}};
    }
    else if (c == 'v') {
        return {{0, -1}};
    }
    else if (!is_whitespace(c)) {
        std::cerr << "Read unexpected input character '" << c << "'.\n";
    }
    return {};
}

enum class turn : bool { santa, robo };
turn next_turn(const turn t)
{
    return (t == turn::santa) ? turn::robo : turn::santa;
}

struct day02_result {
    int part1_visited;
    int part2_visited;
};

day02_result process_input(std::istream& file)
{
    Vec part1_location{0, 0};
    Vec part2_santa_location{0, 0};
    Vec part2_robo_location{0, 0};
    std::set<Vec> part1_visited;
    part1_visited.insert(part1_location);

    Vec part2_location{0, 0};
    std::set<Vec> part2_visited;
    part2_visited.insert(part2_location);
    turn current_turn = turn::santa;

    for (const char c : istream_range{file}) {
        auto movement{get_movement(c)};
        if (movement) {
            part1_location += *movement;
            part1_visited.insert(part1_location);

            Vec& part2_location = (current_turn == turn::santa)
                                      ? part2_santa_location
                                      : part2_robo_location;
            part2_location += *movement;
            part2_visited.insert(part2_location);
            current_turn = next_turn(current_turn);
        }
    }

    return {static_cast<int>(part1_visited.size()),
            static_cast<int>(part2_visited.size())};
}

int main(int argc, char** argv)
{
    auto file = open_file(argc, argv);
    const auto result = process_input(file);

    std::cout << "Part 1: Locations visited: " << result.part1_visited << '\n';
    std::cout << "Part 2: Locations visited: " << result.part2_visited << '\n';
}
