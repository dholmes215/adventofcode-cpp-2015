// Copyright (C) 2021 David Holmes <dholmes@dholmes.us>. All rights reserved.
#include "aoc.hpp"

#include <cctype>

std::ifstream open_file(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "USAGE: " << argv[0] << " input_filename.txt\n";
        std::exit(EXIT_FAILURE);
    }

    std::ifstream file{argv[1]};
    if (!file) {
        std::cerr << "Could not open file " << argv[1] << ".\n";
        std::exit(EXIT_FAILURE);
    }

    return file;
}

bool is_whitespace(char c)
{
    // Cast is necessary because `isspace` on a negative `char` is UB.
    return std::isspace(static_cast<unsigned char>(c));
}

#include <cctype>