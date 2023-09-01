// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <cstdint>

/**
 * @brief A class implementing a dynamic array.
 */
class array {
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
    int *m_data;

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
    array(const array &_other);

    /**
     * @brief Move constructor.
     */
    array(array &&_other);

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
     * @brief Get a reference to the integer at a given index.
     *
     * The access is unchecked. Beware of undefined behaviour if the index is
     * not within the array bounds (0 <= index < size()).
     *
     * @param _index The index that should be accessed.
     * @return Reference to the integer at the given index.
     */
    int &operator[](const std::size_t &_index);

    /**
     * @brief Get a constant reference to the integer at a given index.
     *
     * The access is unchecked. Beware of undefined behaviour if the index is
     * not within the array bounds (0 <= index < size()).
     *
     * @param _index The index that should be accessed.
     * @return Constant reference to the integer at the given index.
     */
    const int &operator[](const std::size_t &_index) const;

    /**
     * @brief Assignment operator.
     */
    array &operator=(const array &_other);

    /**
     * @brief Move operator.
     */
    array &operator=(array &&_other);
};

#endif // ARRAY_HPP_