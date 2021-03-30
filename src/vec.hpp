// Copyright (C) 2021 David Holmes <dholmes@dholmes.us>. All rights reserved.
#ifndef VEC_HPP
#define VEC_HPP

#include <tuple>

template <typename T>
struct vec2 {
    T x{};
    T y{};

    vec2<T> operator+(const vec2<T>& rhs) const
    {
        return {x + rhs.x, y + rhs.y};
    }
    vec2<T> operator-(const vec2<T>& rhs) const
    {
        return {x - rhs.x, y + rhs - y};
    }
    vec2<T> operator+=(const vec2<T>& rhs) { return (*this = *this + rhs); }
    vec2<T> operator-=(const vec2<T>& rhs) { return (*this = *this - rhs); }

    // TODO: Use C++20 spaceship operator
    bool operator==(const vec2<T>& rhs) const
    {
        return std::tie(x, y) == std::tie(rhs.x, rhs.y);
    }
    bool operator!=(const vec2<T>& rhs) const { return !(*this == rhs); }
    bool operator<(const vec2<T>& rhs) const
    {
        return std::tie(x, y) < std::tie(rhs.x, rhs.y);
    }
    bool operator>(const vec2<T>& rhs) const { return rhs < *this; }
    bool operator<=(const vec2<T>& rhs) const { return !(*this > rhs); }
    bool operator>=(const vec2<T>& rhs) const { return !(*this < rhs); }
};

#endif  // VEC_HPP
