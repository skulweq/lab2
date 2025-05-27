#include "library.hpp"
#include <iostream>

int main() {
    std::cout << josephus_library::josephus_problem({ 1, 2, 3, 4, 5 }, 3) << std::endl;
    return 0;
}