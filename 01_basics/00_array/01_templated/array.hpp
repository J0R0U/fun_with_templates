// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <algorithm>
#include <cstdint>
#include <cstring>

/**
 * @brief A class implementing a templated dynamic array.
 */
template <typename _content_type>
class array {
  public: // Typedefs
    /**
     * @brief The content_type saved in this array
     */
    typedef _content_type content_type;

  private: // Member variables
    /**
     * @brief Size of the array
     */
    std::size_t m_size;

    /**
     * @brief Pointer to the start of the array
     *
     * If size is zero, the pointer is invalid.
     */
    content_type *m_data;

  public: // Constructors and destructor
    /**
     * @brief Creates an array of a given size.
     *
     * @param _size The size of the array.
     */
    array(const std::size_t &_size)
    {
        if (_size > 0) {
            m_size = _size;
            m_data = new content_type[m_size];
        } else {
            m_size = 0;
        }
    }

    /**
     * @brief Copy constructor.
     */
    array(const array<content_type> &_other)
    {
        if (_other.m_size > 0) {
            m_size = _other.m_size;
            m_data = new content_type[m_size];

            std::memcpy(m_data, _other.m_data, m_size * sizeof(content_type));
        } else {
            m_size = 0;
        }
    }

    /**
     * @brief Move constructor.
     */
    array(array<content_type> &&_other)
        : m_size{_other.m_size},
          m_data{_other.m_data}
    {
        _other.m_size = 0;
    }

    /**
     * @brief Free array memory if used.
     */
    ~array()
    {
        if (m_size > 0) {
            delete[] m_data;
        }
    }

  public: // Getter
    /**
     * @brief Returns the size of the array.
     *
     * @return The array size.
     */
    std::size_t size() const
    {
        return m_size;
    }

  public: // Functionality
    /**
     * @brief Resizes the array to the new array size.
     *
     * Frees the previously allocated memory if needed and copies as much old
     * values as possible to the new array.
     *
     * @param _size The size of the array.
     */
    void resize(const std::size_t &_size)
    {
        const bool    delete_old_data{m_size > 0};
        content_type *old_data{m_data};

        if (_size > 0) {
            m_data = new content_type[m_size];

            const std::size_t byte_size{std::min(m_size, _size) * sizeof(content_type)};
            if (byte_size > 0) {
                std::memcpy(m_data, old_data, byte_size);
            }

            m_size = _size;
        } else {
            m_size = 0;
        }

        if (delete_old_data) {
            delete[] old_data;
        }
    }

  public: // Operators
    /**
     * @brief Get a reference to the value at a given index.
     *
     * The access is unchecked. Beware of undefined behaviour if the index is
     * not within the array bounds (0 <= index < size()).
     *
     * @param _index The index that should be accessed.
     * @return Reference to the value at the given index.
     */
    content_type &operator[](const std::size_t &_index)
    {
        return m_data[_index];
    }

    /**
     * @brief Get a constant reference to the value at a given index.
     *
     * The access is unchecked. Beware of undefined behaviour if the index is
     * not within the array bounds (0 <= index < size()).
     *
     * @param _index The index that should be accessed.
     * @return Constant reference to the value at the given index.
     */
    const content_type &operator[](const std::size_t &_index) const
    {
        return m_data[_index];
    }

    /**
     * @brief Assignment operator.
     */
    array &operator=(const array<content_type> &_other)
    {
        if (m_size > 0) {
            delete[] m_data;
        }

        m_size = _other.m_size;
        if (m_size > 0) {
            m_data = new content_type[m_size];

            std::memcpy(m_data, _other.m_data, m_size * sizeof(content_type));
        }

        return *this;
    }

    /**
     * @brief Move operator.
     */
    array &operator=(array<content_type> &&_other)
    {
        if (m_size > 0) {
            delete[] m_data;
        }

        m_size = _other.m_size;
        m_data = _other.m_data;

        _other.m_size = 0;

        return *this;
    }
};

#endif // ARRAY_HPP_