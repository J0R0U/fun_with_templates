// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#include <iostream>

#include "fibonacci.hpp"

/**
 * @brief Print the Fibonacci number at _index.
 *
 * The number is calculated at compile time.
 */
template <uint16_t _index>
void print_fib()
{
    std::cout << "Compile time calculated fib(" << fibonacci<_index>::index << ")=" << fibonacci<_index>::value << '\n';
}

/**
 * @brief The main function.
 *
 * @return The exit status.
 */
int main()
{
    print_fib<0>();
    print_fib<1>();
    print_fib<2>();
    print_fib<3>();
    print_fib<4>();
    print_fib<5>();
    print_fib<6>();
    print_fib<7>();
    print_fib<8>();
    print_fib<9>();
    print_fib<10>();
    print_fib<15>();
    print_fib<20>();
    print_fib<25>();
    print_fib<30>();

    return 0;
}