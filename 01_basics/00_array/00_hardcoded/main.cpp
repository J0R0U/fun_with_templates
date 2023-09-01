// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#include <iostream>

#include "array.hpp"

/**
 * Prints an array to the console.
 *
 * @param _arr The array that is printed.
 */
void print_array(const array &_arr)
{
    std::cout << "[";

    for (std::size_t i{0}; i < _arr.size(); ++i) {
        std::cout << ' ' << _arr[i];
    }

    std::cout << " ]\n";
}

/**
 * @brief The main function.
 *
 * @return The exit status.
 */
int main()
{
    array arr{11};

    arr[0]  = -5;
    arr[1]  = -4;
    arr[2]  = -3;
    arr[3]  = -2;
    arr[4]  = -1;
    arr[5]  = +0;
    arr[6]  = +1;
    arr[7]  = +2;
    arr[8]  = +3;
    arr[9]  = +4;
    arr[10] = +5;

    print_array(arr);

    return 0;
}