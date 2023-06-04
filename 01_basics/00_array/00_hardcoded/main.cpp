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