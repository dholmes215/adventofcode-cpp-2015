// Copyright (C) 2021 David Holmes <dholmes@dholmes.us>. All rights reserved.
#ifndef AOC_HPP
#define AOC_HPP

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// Open a file as a `ifstream`, or exit on error.
std::ifstream open_file(int argc, char** argv);

// Helper to allow iterating the `char`s in an `istream` with a ranged for loop.
struct istream_range {
   public:
    using Iterator = std::istreambuf_iterator<char>;
    istream_range(std::istream& stream) : begin_iter(stream) {}
    Iterator begin() { return begin_iter; }
    Iterator end() { return {}; }

   private:
    Iterator begin_iter{};
};

// Return true if `c` is a whitespace character.  Takes a `char` safely without
// a cast unlike std::isspace.
bool is_whitespace(char c);

// Read every line from input stream into a `vector`
std::vector<std::string> read_lines(std::istream& stream);

#endif  // AOC_HPP