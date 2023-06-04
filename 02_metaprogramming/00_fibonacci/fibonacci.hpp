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

#ifndef FIBONACCI_HPP_
#define FIBONACCI_HPP_

#include <cstdint>

/**
 * @brief A class calculating a fibonacci number recursively.
 */
template <uint16_t _index>
class fibonacci {
  public: // Static member variables
    /**
     * @brief The index of the fibonacci number.
     */
    static const constexpr uint16_t index{_index};

    /**
     * @brief The value of the fibonacci number at the specified index.
     *
     * The value is defined using the recursive definition.
     */
    static const constexpr uint32_t value{fibonacci<index - 1>::value + fibonacci<index - 2>::value};
};

/**
 * @brief Specialization of the fibonacci class for the index zero.
 *
 * This is comparable to a recursion anchor when calculating fibonacci numbers
 * for higher index.
 */
template <>
class fibonacci<0> {
  public: // Static member variables
    /**
     * @brief The index of the fibonacci number.
     */
    static const constexpr uint16_t index{0};

    /**
     * @brief The value of the fibonacci number at the specified index.
     */
    static const constexpr uint32_t value{0};
};

/**
 * @brief Specialization of the fibonacci class for the index one.
 *
 * This is comparable to a recursion anchor when calculating fibonacci numbers
 * for higher index.
 */
template <>
class fibonacci<1> {
  public: // Static member variables
    /**
     * @brief The index of the fibonacci number.
     */
    static const constexpr uint16_t index{1};

    /**
     * @brief The value of the fibonacci number at the specified index.
     */
    static const constexpr uint32_t value{1};
};

#endif // FIBONACCI_HPP_