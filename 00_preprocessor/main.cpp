// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

/**
 * Include iostream, this will be replaced with the content of the <iostream> file.
 */
#include <iostream>

/**
 * Include constants.hpp, this will be replaced with the content of the <constants.hpp> file.
 */
#include "constants.hpp"

/**
 * @brief The main function.
 *
 * @return The program exit value.
 */
int main()
{
    std::cout << greeting << std::endl;

    return 0;
}