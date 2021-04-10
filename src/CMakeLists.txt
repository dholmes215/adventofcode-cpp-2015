add_library(aoc aoc.cpp aoc.hpp)
target_link_libraries(aoc PRIVATE project_warnings)

add_executable(day01 day01.cpp aoc)
target_link_libraries(day01 PRIVATE project_warnings)
add_executable(day02 day02.cpp aoc)
target_link_libraries(day02 PRIVATE project_warnings)
add_executable(day03 day03.cpp aoc)
target_link_libraries(day03 PRIVATE project_warnings)
