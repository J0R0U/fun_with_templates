// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef CIRCULAR_BUFFER_HPP_
#define CIRCULAR_BUFFER_HPP_

#include <algorithm>
#include <cstdint>
#include <cstring>

/**
 * @brief A templated class implementing a circular buffer.
 */
template <typename _content_type, std::size_t _capacity>
class circular_buffer {
  public: // Asserts
    /**
     * @brief Verify that the capacity is bigger then zero.
     */
    static_assert(_capacity > 0, "The buffer capacity is required to be bigger than zero.");

  public: // Typedefs
    /**
     * @brief The content type of the buffer.
     */
    typedef _content_type content_type;

  public: // Static member variables
    static const constexpr std::size_t capacity{_capacity};

  private: // Member variables
    /**
     * @brief The internal data representation.
     */
    content_type *m_data;

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
    circular_buffer()
        : m_data{new content_type[capacity]},
          m_first_free{0},
          m_first_valid{0}
    {
    }

    /**
     * @brief Copy constructor.
     */
    circular_buffer(const circular_buffer<content_type, capacity> &_other)
        : m_data{new content_type[capacity]},
          m_first_free{_other.m_first_free},
          m_first_valid{_other.m_first_free}
    {
        std::memcpy(m_data, _other.m_data, capacity);
    }

    /**
     * @brief Move constructor.
     */
    circular_buffer(circular_buffer<content_type, capacity> &&_other)
        : m_data{std::move(_other.m_data)},
          m_first_free{std::move(_other.m_first_free)},
          m_first_valid{std::move(_other.m_first_valid)}
    {
        _other.m_data = nullptr;
    }

    /**
     * @brief Free buffer memory if used.
     */
    ~circular_buffer()
    {
        if (m_data) {
            delete m_data;
        }
    }

  public: // Getter
    /**
     * @brief The amount of saved data in the buffer.
     */
    std::size_t size() const
    {
        if (m_first_free >= m_first_valid) {
            return m_first_free - m_first_valid;
        }

        return capacity - m_first_valid + m_first_free;
    }

  public: // Functionality
    /**
     * @brief Adds a new value to the buffer.
     *
     * Result in data loss if the buffer overflows.
     *
     * @param _value The value that is added to the buffer.
     */
    void push(const content_type &_value)
    {
        m_data[m_first_free] = _value;

        m_first_free = m_first_free + 1;

        if (m_first_free == capacity) {
            m_first_free = 0;
        }
    }

    /**
     * @brief Removes the first value of the buffer and returns it.
     *
     * Might result in UB if the buffer underflows.
     *
     * @return The first value of the buffer.
     */
    content_type pop()
    {
        content_type value = m_data[m_first_valid];

        m_first_valid = m_first_valid + 1;

        if (m_first_valid == capacity) {
            m_first_valid = 0;
        }

        return value;
    }

  public: // Operators
    /**
     * @brief Assignment operator.
     */
    circular_buffer &operator=(const circular_buffer<content_type, capacity> &_other)
    {
        if (m_data) {
            delete m_data;
        }

        m_data        = new content_type[capacity];
        m_first_free  = _other.m_first_free;
        m_first_valid = _other.m_first_valid;

        std::memcpy(m_data, _other.m_data, capacity);

        return *this;
    }

    /**
     * @brief Move operator.
     */
    circular_buffer &operator=(circular_buffer<content_type, capacity> &&_other)
    {
        if (m_data) {
            delete m_data;
        }

        m_data        = std::move(_other.m_data);
        m_first_free  = std::move(_other.m_first_free);
        m_first_valid = std::move(_other.m_first_valid);

        _other.m_data = nullptr;

        return *this;
    }
};

#endif // CIRCULAR_BUFFER_HPP_
