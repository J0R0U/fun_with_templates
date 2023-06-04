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

#ifndef MANDELBROT_HPP_
#define MANDELBROT_HPP_

#include "double_templates.hpp"

/**
 * @brief The maximum depth of the mandelbrot iteration.
 */
#define max_mandelbrot_iteration 1000

// Forward declaration

template <uint16_t _iteration, typename _x0, typename _y0, typename _x, typename _y>
class mandelbrot_iteration;

template <std::size_t _index, typename _start_x, typename _start_y, typename _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot_pixel;

/**
 * @brief A reference to the next mandelbrot iteration.
 */
template <bool _check_next, uint16_t _iteration, typename _x0, typename _y0, typename _x, typename _y>
class mandelbrot_iteration_next {
  public: // Assert that the given values are within expected bounds
    static_assert(_iteration < max_mandelbrot_iteration, "The iteration needs to be smaller than max_mandelbrot_iteration.");

  public: // Static member variables
    /**
     * @brief The value of the iteration, using the value of next iteration.
     */
    static const constexpr uint8_t value{mandelbrot_iteration<_iteration, _x0, _y0, _x, _y>::value_provider::value};
};

/**
 * @brief A reference to the next mandelbrot iteration.
 *
 * A specialization for the last iteration.
 */
template <uint16_t _iteration, typename _x0, typename _y0, typename _x, typename _y>
class mandelbrot_iteration_next<false, _iteration, _x0, _y0, _x, _y> {
  public: // Static member variables
    /**
     * @brief The value of the iteration.
     */
#if max_mandelbrot_iteration == 0
    static const constexpr uint8_t value{0};
#else
    static const constexpr uint8_t value{_iteration * 255 / max_mandelbrot_iteration};
#endif
};

/**
 * @brief A class that for the mandelbrot iteration.
 */
template <uint16_t _iteration, typename _x0, typename _y0, typename _x, typename _y>
class mandelbrot_iteration {
  private: // Typedefs
    /**
     * @brief A helper to calculate the next iteration.
     */
    using helper_x2_y2 = typename tdouble_sub<
        typename tdouble_mul<_x, _x>::value,
        typename tdouble_mul<_y, _y>::value>::value;

    /**
     * @brief A helper to calculate the next iteration.
     */
    using helper_xy2 = typename tdouble_mul<
        tdouble(2),
        typename tdouble_mul<_x, _y>::value>::value;

    /**
     * @brief The next x value.
     */
    using new_x = typename tdouble_add<helper_x2_y2, _x0>::value;

    /**
     * @brief The next y value.
     */
    using new_y = typename tdouble_add<helper_xy2, _y0>::value;

    /**
     * @brief Tests if the number is diverging.
     */
    using test_lower = tdouble_lower<helper_x2_y2, tdouble(4)>;

  public: // Typedefs
    /**
     * @brief The value provider of the mandelbrot iteration.
     */
    typedef mandelbrot_iteration_next<(test_lower::value && (_iteration + 1) < max_mandelbrot_iteration), _iteration + 1, _x0, _y0, new_x, new_y> value_provider;
};

/**
 * @brief A helper class that starts the mandelbrot iteration.
 */
template <typename _x, typename _y>
class mandelbrot_iteration_start {
  public: // Typedefs
    /**
     * @brief The start of the iteration.
     */
    typedef mandelbrot_iteration<0, _x, _y, tdouble(0), tdouble(0)> start;
};

/**
 * @brief A class that calculates a mandelbrot pixel value.
 */
template <std::size_t _index, typename _start_x, typename _start_y, typename _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot_pixel_value {
  public: // Assert that the given values are within expected bounds
    static_assert(tdouble_greater<_step_size, tdouble(0)>::value, "The step size needs to be greater then zero.");
    static_assert(_size_x > 0, "The picture size in the x direction needs to be greater then zero.");

  private: // Typedefs
    /**
     * @brief Helper to calculate the x value.
     */
    using helper_offset_x_num = tdouble((_index % _size_x));

    /**
     * @brief Helper to calculate the y value.
     */
    using helper_offset_y_num = tdouble((_size_y - _index / _size_x));

    /**
     * @brief Half pixel offset.
     */
    using helper_neg_half_step_size = typename tdouble_div<_step_size, tdouble(-2)>::value;

    /**
     * @brief Helper to calculate the x value.
     */
    using helper_offset_x = typename tdouble_mul<helper_offset_x_num, _step_size>::value;

    /**
     * @brief Helper to calculate the y value.
     */
    using helper_offset_y = typename tdouble_mul<helper_offset_y_num, _step_size>::value;

    /**
     * @brief Helper to calculate the x value.
     */
    using helper_offset_x_norm = typename tdouble_add<helper_offset_x, helper_neg_half_step_size>::value;

    /**
     * @brief Helper to calculate the y value.
     */
    using helper_offset_y_norm = typename tdouble_add<helper_offset_y, helper_neg_half_step_size>::value;

    /**
     * @brief The x value used for the iteration.
     */
    using x = typename tdouble_add<_start_x, helper_offset_x_norm>::value;

    /**
     * @brief The y value used for the iteration.
     */
    using y = typename tdouble_add<_start_y, helper_offset_y_norm>::value;

  public: // Static member variables
    /**
     * @brief The resulting pixel value.
     */
    static const constexpr uint8_t value{mandelbrot_iteration_start<x, y>::start::value_provider::value};
};

/**
 * @brief A class that is a reference to the next value.
 */
template <bool _has_next, std::size_t _index, typename _start_x, typename _start_y, typename _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot_pixel_next {
  public: // Assert that the given values are within expected bounds
    static_assert(tdouble_greater<_step_size, tdouble(0)>::value, "The step size needs to be greater then zero.");
    static_assert(_size_x > 0, "The picture size in the x direction needs to be greater then zero.");
    static_assert(_size_y > 0, "The picture size in the y direction needs to be greater then zero.");

  public: // Typedefs
    /**
     * @brief The reference to the next pixel.
     */
    typedef mandelbrot_pixel<_index, _start_x, _start_y, _step_size, _size_x, _size_y> next;
};

/**
 * @brief A class that is a reference to the next value.
 *
 * Specialization for the last pixel reference.
 */
template <std::size_t _index, typename _start_x, typename _start_y, typename _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot_pixel_next<false, _index, _start_x, _start_y, _step_size, _size_x, _size_y> {
  public: // Assert that the given values are within expected bounds
    static_assert(tdouble_greater<_step_size, tdouble(0)>::value, "The step size needs to be greater then zero.");
    static_assert(_size_x > 0, "The picture size in the x direction needs to be greater then zero.");
    static_assert(_size_y > 0, "The picture size in the y direction needs to be greater then zero.");

  public: // Typedefs
    /**
     * @brief The reference to the next pixel, which does not exist.
     */
    typedef void next;
};

/**
 * @brief A class that corresponds to a mandelbrot pixel.
 */
template <std::size_t _index, typename _start_x, typename _start_y, typename _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot_pixel {
  public: // Assert that the given values are within expected bounds
    static_assert(tdouble_greater<_step_size, tdouble(0)>::value, "The step size needs to be greater then zero.");
    static_assert(_size_x > 0, "The picture size in the x direction needs to be greater then zero.");
    static_assert(_size_y > 0, "The picture size in the y direction needs to be greater then zero.");
    static_assert(_index < _size_x * _size_y, "The picture index is out of bounds.");

  public: // Typedefs
    /**
     * @brief The reference to the next pixel.
     */
    typedef mandelbrot_pixel_next<_index + 1 < _size_x * _size_y, _index + 1, _start_x, _start_y, _step_size, _size_x, _size_y> next_provider;

    /**
     * @brief The grayscale value of the pixel.
     */
    typedef mandelbrot_pixel_value<_index, _start_x, _start_y, _step_size, _size_x, _size_y> value_calculator;
};

/**
 * @brief A class that creates a mandelbrot set at compile time.
 */
template <typename _start_x, typename _start_y, typename _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot {
  public: // Assert that the given values are within expected bounds
    static_assert(tdouble_greater<_step_size, tdouble(0)>::value, "The step size needs to be greater then zero.");
    static_assert(_size_x > 0, "The picture size in the x direction needs to be greater then zero.");
    static_assert(_size_y > 0, "The picture size in the y direction needs to be greater then zero.");

  public: // Typedefs
    /**
     * @brief The pixel values of the picture.
     */
    typedef mandelbrot_pixel<0, _start_x, _start_y, _step_size, _size_x, _size_y> pixels;

  public:
    /**
     * @brief The x start value.
     */
    static const constexpr double start_x{_start_x::value};

    /**
     * @brief The x start value.
     */
    static const constexpr double start_y{_start_y::value};

    /**
     * @brief The step size of each pixel.
     */
    static const constexpr double step_size{_step_size::value};

    /**
     * @brief The x size of the picture.
     */
    static const constexpr std::size_t size_x{_size_x};

    /**
     * @brief The y size of the picture.
     */
    static const constexpr std::size_t size_y{_size_y};
};

#endif // MANDELBROT_HPP_