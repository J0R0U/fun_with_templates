// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef CIRCULAR_BUFFER_HPP_
#define CIRCULAR_BUFFER_HPP_

#include <algorithm>
#include <cstdint>
#include <cstring>

/**
 * @brief A class implementing a circular buffer.
 */
class circular_buffer {
  private: // Static member variables
    /**
     * @brief The capacity of the circular buffer.
     */
    static const constexpr std::size_t s_capacity{300};

  private: // Member variables
    /**
     * @brief The internal data representation.
     */
    int *m_data;

    /**
     * @brief The first index in the data representation that is free.
     */
    std::size_t m_first_free;

    /**
     * @brief The first index in the data representation that is valid.
     */
    std::size_t m_first_valid;

  public: // Constructors and destructor
    /**
     * @brief Constructs a circular buffer.
     */
    circular_buffer();

    /**
     * @brief Copy constructor.
     */
    circular_buffer(const circular_buffer &_other);

    /**
     * @brief Move constructor.
     */
    circular_buffer(circular_buffer &&_other);

    /**
     * @brief Free buffer memory if used.
     */
    ~circular_buffer();

  public: // Getter
    /**
     * @brief The potential capacity of the buffer.
     */
    std::size_t capacity() const;

    /**
     * @brief The amount of saved data in the buffer.
     */
    std::size_t size() const;

  public: // Functionality
    /**
     * @brief Adds a new value to the buffer.
     *
     * Result in data loss if the buffer overflows.
     *
     * @param _value The value that is added to the buffer.
     */
    void push(const int &_value);

    /**
     * @brief Removes the first value of the buffer and returns it.
     *
     * Might result in UB if the buffer underflows.
     *
     * @return The first value of the buffer.
     */
    int pop();

  public: // Operators
    /**
     * @brief Assignment operator.
     */
    circular_buffer &operator=(const circular_buffer &_other);

    /**
     * @brief Move operator.
     */
    circular_buffer &operator=(circular_buffer &&_other);
};

#endif // CIRCULAR_BUFFER_HPP_