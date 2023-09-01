// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <memory>
#include <ostream>
#include <string>

/**
 * @brief A class that represents a 2d double matrix.
 */
class matrix {
  public: // Classes
    /**
     * @brief A class that is used to reference a column in the array.
     */
    class column {
      private: // Typedefs
        /**
         * @brief The content type served by this column.
         */
        typedef double content_t;

        /**
         * @brief The fitting array type.
         */
        typedef content_t *array_t;

      private: // Members
        /**
         * @brief The requested x coordinate.
         */
        const std::size_t m_x;

        /**
         * @brief The size of one row.
         */
        const std::size_t m_n;

        /**
         * @brief A reference to the data container.
         */
        const array_t m_data_ptr;

      private:
        /**
         * @brief Construct a new object.
         *
         * @param _x The x coordinate of the column.
         * @param _n The size of one row.
         * @param _data_ptr A reference to the data container.
         */
        column(const std::size_t &_x, const std::size_t &_n, const array_t &_data_ptr);

      public:
        /**
         * @brief Return the value at a given row.
         *
         * @param _y The row that should be returned.
         * @return The value at the specified position.
         */
        content_t &operator[](const std::size_t &_y);

      public: // Friends
        /**
         * @brief Allow matrix objects to create columns.
         */
        friend matrix;
    };

    /**
     * @brief A class that is used to reference a column in the array.
     *
     * This class only provides constant access.
     */
    class const_column {
      private: // Typedefs
        /**
         * @brief The content type served by this column.
         */
        typedef const double content_t;

        /**
         * @brief The fitting array type.
         */
        typedef content_t *array_t;

      private: // Members
        /**
         * @brief The requested x coordinate.
         */
        const std::size_t m_x;

        /**
         * @brief The size of one row.
         */
        const std::size_t m_n;

        /**
         * @brief A reference to the data container.
         */
        const array_t m_data_ptr;

      private:
        /**
         * @brief Construct a new object.
         *
         * @param _x The x coordinate of the column.
         * @param _n The size of one row.
         * @param _data_ptr A reference to the data container.
         */
        const_column(const std::size_t &_x, const std::size_t &_n, const array_t &_data_ptr);

      public:
        /**
         * @brief Return the value at a given row.
         *
         * @param _y The row that should be returned.
         * @return The value at the specified position.
         */
        content_t &operator[](const std::size_t &_y);

      public: // Friends
        /**
         * @brief Allow matrix objects to create constant columns.
         */
        friend matrix;
    };

  public: // Static functionality
    /**
     * @brief Constructs a radom matrix, where the size is in [5,10] and each
     *        element is in [-100.0, 100.0].
     *
     * @return The generated random matrix.
     */
    static matrix random();

  private: // Members
    /**
     * @brief The size of the matrix in x direction.
     */
    const std::size_t m_n;

    /**
     * @brief The size of the matrix in y direction.
     */
    const std::size_t m_m;

    /**
     * @brief The data container.
     */
    std::unique_ptr<double[]> m_data;

  public: // Constructors
    /**
     * @brief Constructs a matrix of a given size.
     *
     * @param _n The size of the matrix in x direction.
     * @param _m The size of the matrix in y direction.
     */
    matrix(const std::size_t &_n, const std::size_t &_m);

  public: // Functionality
    /**
     * @brief Getter for the size of the matrix in x direction.
     *
     * @returns The size of the matrix in x direction.
     */
    std::size_t n() const;

    /**
     * @brief Getter for the size of the matrix in x direction.
     *
     * @returns The size of the matrix in y direction.
     */
    std::size_t m() const;

    /**
     * @brief Creates a value that is sufficient for logging this matrix.
     *
     * @return The log value.
     */
    std::string get_log_value() const;

  public: // Operators
    /**
     * @brief Overloaded operator for convenient access of the matrix data.
     *
     * @param _x The colum that is accessed.
     *
     * @returns A colum object that allows to access the values at the selected
     *          position.
     */
    column operator[](const std::size_t &_x);

    /**
     * @brief Overloaded operator for convenient access of the matrix data.
     *
     * This is a const overload.
     *
     * @param _x The colum that is accessed.
     *
     * @returns A colum object that allows to access the values at the selected
     *          position.
     */
    const_column operator[](const std::size_t &_x) const;
};

/**
 * @brief Overloaded stream operator for matrix class.
 *
 * @param _stream The stream the matrix should be written to.
 * @param _matrix The matrix that should be written.
 *
 * @return The passed stream reference for chaining the calls.
 */
std::ostream &operator<<(std::ostream &_stream, const matrix &_matrix);

#endif // MATRIX_HPP_