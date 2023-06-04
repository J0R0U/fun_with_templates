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

template <typename _array_type>
void print_array(const array<_array_type> &_arr)
{
    std::cout << "[";

    for (std::size_t i{0}; i < _arr.size(); ++i) {
        std::cout << ' ' << _arr[i];
    }

    std::cout << " ]\n";
}

template <>
void print_array(const array<bool> &_arr)
{
    std::cout << "[";

    for (std::size_t i{0}; i < _arr.size(); ++i) {
        std::cout << ' ' << _arr[i];
    }

    std::cout << " ] : Saves " << _arr.size() << " bool values in " << _arr.used_bits() << " bits instead of " << (_arr.size() * sizeof(bool) * CHAR_BIT) << " bits.\n";
}

int main()
{
    array<int>    int_arr{11};
    array<double> double_arr{11};
    array<bool>   bool_arr{11};

    int_arr[0]  = -5;
    int_arr[1]  = -4;
    int_arr[2]  = -3;
    int_arr[3]  = -2;
    int_arr[4]  = -1;
    int_arr[5]  = +0;
    int_arr[6]  = +1;
    int_arr[7]  = +2;
    int_arr[8]  = +3;
    int_arr[9]  = +4;
    int_arr[10] = +5;

    double_arr[0]  = -0.5;
    double_arr[1]  = -0.4;
    double_arr[2]  = -0.3;
    double_arr[3]  = -0.2;
    double_arr[4]  = -0.1;
    double_arr[5]  = +0.0;
    double_arr[6]  = +0.1;
    double_arr[7]  = +0.2;
    double_arr[8]  = +0.3;
    double_arr[9]  = +0.4;
    double_arr[10] = +0.5;

    bool_arr[0]  = true;
    bool_arr[1]  = true;
    bool_arr[2]  = false;
    bool_arr[3]  = true;
    bool_arr[4]  = false;
    bool_arr[5]  = true;
    bool_arr[6]  = true;
    bool_arr[7]  = true;
    bool_arr[8]  = false;
    bool_arr[9]  = false;
    bool_arr[10] = false;

    print_array(int_arr);
    print_array(double_arr);
    print_array(bool_arr);

    return 0;
}