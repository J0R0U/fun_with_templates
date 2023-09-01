// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#include "logger.hpp"
#include "matrix.hpp"

/**
 * @brief The main function.
 *
 * @return The exit status.
 */
int main()
{
    const matrix matrix{matrix::random()};

    log("Generated matrix (", matrix, ')');
    std::cout << "Compare with the output when writing matrix to a stream.\n"
              << matrix << '\n';

    return EXIT_SUCCESS;
}