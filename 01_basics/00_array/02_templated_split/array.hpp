// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <cstdint>

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
    array(const std::size_t &_size);

    /**
     * @brief Copy constructor.
     */
    array(const array<content_type> &_other);

    /**
     * @brief Move constructor.
     */
    array(array<content_type> &&_other);

    /**
     * @brief Free array memory if used.
     */
    ~array();

  public: // Getter
    /**
     * @brief Returns the size of the array.
     *
     * @return The array size.
     */
    std::size_t size() const;

  public: // Functionality
    /**
     * @brief Resizes the array to the new array size.
     *
     * Frees the previously allocated memory if needed and copies as much old
     * values as possible to the new array.
     *
     * @param _size The size of the array.
     */
    void resize(const std::size_t &_size);

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
    content_type &operator[](const std::size_t &_index);

    /**
     * @brief Get a constant reference to the value at a given index.
     *
     * The access is unchecked. Beware of undefined behaviour if the index is
     * not within the array bounds (0 <= index < size()).
     *
     * @param _index The index that should be accessed.
     * @return Constant reference to the value at the given index.
     */
    const content_type &operator[](const std::size_t &_index) const;

    /**
     * @brief Assignment operator.
     */
    array &operator=(const array<content_type> &_other);

    /**
     * @brief Move operator.
     */
    array &operator=(array<content_type> &&_other);
};

#include "array.tpp"

#endif // ARRAY_HPP_