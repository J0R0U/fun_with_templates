// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#include <iostream>

#include "circular_buffer.hpp"

/**
 * @brief Print the content of the circular buffer.
 *
 * @param _buffer The circular buffer.
 */
template <typename _content_type, std::size_t _capacity>
void print_buffer(circular_buffer<_content_type, _capacity> &_buffer)
{
    std::cout << "[";

    while (_buffer.size()) {
        std::cout << ' ' << _buffer.pop();
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
    circular_buffer<int, 20> buffer{};

    for (std::size_t i{0}; i < 11; ++i) {
        buffer.push(-5 + i);
    }

    print_buffer(buffer);

    return 0;
}