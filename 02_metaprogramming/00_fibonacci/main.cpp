// ----------------------------------------------------------------------------
//
// This file is part of fun_with_templates.
//
// fun_with_templates is free software: you can redistribute it and/or modify
// it under the terms of the "Do What The Fuck You Want To Public License",
// Version 2, as published by Sam Hocevar. See http://www.wtfpl.net/ for more
// details.
//
// THE PROJECT "fun_with_templates" IS PROVIDED "AS IS", WITHOUT WARRANTY OF
// ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO
// EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH "fun_with_templates"
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
// SPDX-License-Identifier: WTFPL
//
// ----------------------------------------------------------------------------

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