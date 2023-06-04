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

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <climits>
#include <cstdint>

template <typename _content_type>
class array {
  public: // Typedefs
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

/**
 * @brief Specified array class for bool values.
 */
template <>
class array<bool> {
  public: // Typedefs
    typedef bool content_type;

  private: // Typedefs
    typedef unsigned char    underlying_type;
    typedef underlying_type *underlying_array_type;

  public: // inner class
    /**
     * @brief Wrapper used to get and set bool values saved as bitfields.
     */
    class bool_wrapper {
      private: // Member variables
        /**
         * @brief The index of the internal array containing the specified bit.
         */
        const std::size_t m_index;

        /**
         * @brief The mask that can be used to access the bit.
         */
        const array<bool>::underlying_type m_mask;

        /**
         * @brief The raw array data.
         */
        array<bool>::underlying_array_type m_data;

      private: // Constructor
        /**
         * @brief The constructor with parameters pointing to the specified bit.
         *
         * @param _index The index of the internal array containing the
         *               specified bit.
         * @param _mask The mask that can be used to access the bit.
         * @param _data The raw array data.
         */
        bool_wrapper(const std::size_t                        &_index,
                     const array<bool>::underlying_type       &_mask,
                     const array<bool>::underlying_array_type &_data);

      public: // Operators
        /**
         * @brief Implicit converter to bool.
         */
        bool_wrapper &operator=(const bool &_value);

        /**
         * @brief Implicit converter to bool.
         */
        operator bool() const;

      private: // Friends
        friend array<bool>;
    };

  private: // Static members
    static const constexpr std::size_t s_underlying_type_bit_size{CHAR_BIT * sizeof(underlying_type)};

  private: // Static functionality
    static underlying_array_type allocate_for_bits(const std::size_t &_bits, std::size_t &_array_size);

  private: // Member variables
    /**
     * @brief Amount of stored bool values
     */
    std::size_t m_size;

    /**
     * @brief Size of the internal array
     *
     * If size is zero, the value is invalid.
     */
    std::size_t m_array_size;

    /**
     * @brief Pointer to the start of the array
     *
     * If size is zero, the pointer is invalid. Instead of using a bool array
     * a char array is used, to maximize data density.
     */
    underlying_array_type m_data;

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
    array(const array<bool> &_other);

    /**
     * @brief Move constructor.
     */
    array(array<bool> &&_other);

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

    /**
     * @brief Returns the amount of bits used to save the boolean array.
     *
     * @return The bits used to save the data.
     */
    std::size_t used_bits() const;

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
    bool_wrapper operator[](const std::size_t &_index);

    /**
     * @brief Get a constant reference to the value at a given index.
     *
     * The access is unchecked. Beware of undefined behaviour if the index is
     * not within the array bounds (0 <= index < size()).
     *
     * @param _index The index that should be accessed.
     * @return Constant reference to the value at the given index.
     */
    const bool_wrapper operator[](const std::size_t &_index) const;

    /**
     * @brief Assignment operator.
     */
    array &operator=(const array<content_type> &_other);

    /**
     * @brief Move operator.
     */
    array &operator=(array<content_type> &&_other);

  private: // Friends
    friend bool_wrapper;
};

#include "array.tpp"

#endif // ARRAY_HPP_