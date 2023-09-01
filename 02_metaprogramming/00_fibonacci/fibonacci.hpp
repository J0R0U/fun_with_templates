// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

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