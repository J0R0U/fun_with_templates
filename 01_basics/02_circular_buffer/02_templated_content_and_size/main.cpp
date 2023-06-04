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