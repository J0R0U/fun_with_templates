// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef MANDELBROT_HPP_
#define MANDELBROT_HPP_

#include <cstdint>

/**
 * @brief The maximum depth of the mandelbrot iteration.
 */
#define max_mandelbrot_iteration 1000

// Forward declaration

template <uint16_t _iteration, double _x0, double _y0, double _x, double _y>
class mandelbrot_iteration;

template <std::size_t _index, double _start_x, double _start_y, double _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot_pixel;

/**
 * @brief A reference to the next mandelbrot iteration.
 */
template <bool _check_next, uint16_t _iteration, double _x0, double _y0, double _x, double _y>
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
template <uint16_t _iteration, double _x0, double _y0, double _x, double _y>
class mandelbrot_iteration_next<false, _iteration, _x0, _y0, _x, _y> {
  private: // Static members
    /**
     * @brief Check if iteration finished because the length of c is bigger then 2.
     */
    static const constexpr bool quick_diverge{_x * _x + _y * _y < 4};

  public: // Static member variables
    /**
     * @brief The value of the iteration.
     */
#if max_mandelbrot_iteration == 0
    static const constexpr uint8_t value{0};
#else
    static const constexpr uint8_t value{quick_diverge ? 255 : _iteration * 255 / max_mandelbrot_iteration};
#endif
};

/**
 * @brief A class that handles the mandelbrot iteration.
 */
template <uint16_t _iteration, double _x0, double _y0, double _x, double _y>
class mandelbrot_iteration {
  private: // Static members
    /**
     * @brief Indicates if the iteration is finished.
     *
     * The iteration is finished if the length of c is bigger then 2 or the maximum iteration depth is reached.
     */
    static const constexpr bool has_next{(_x * _x + _y * _y < 4) && (_iteration + 1 < max_mandelbrot_iteration)};

    /**
     * @brief The new x value for the next iteration.
     */
    static const constexpr double newX{_x * _x - _y * _y + _x0};

    /**
     * @brief The new y value for the next iteration.
     */
    static const constexpr double newY{2 * _x * _y + _y0};

  public: // Typedefs
    /**
     * @brief The value provider of the mandelbrot iteration.
     */
    typedef mandelbrot_iteration_next<has_next, _iteration + 1, _x0, _y0, newX, newY> value_provider;
};

/**
 * @brief A helper class that starts the mandelbrot iteration.
 */
template <double _x, double _y>
class mandelbrot_iteration_start {
  public: // Typedefs
    /**
     * @brief The start of the iteration.
     */
    typedef mandelbrot_iteration<0, _x, _y, 0., 0.> start;
};

/**
 * @brief A class that calculates a mandelbrot pixel value.
 */
template <std::size_t _index, double _start_x, double _start_y, double _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot_pixel_value {
  public: // Assert that the given values are within expected bounds
    static_assert(_step_size > 0, "The step size needs to be greater then zero.");
    static_assert(_size_x > 0, "The picture size in the x direction needs to be greater then zero.");

  private: // Static members
    /**
     * @brief The x value used for the iteration.
     */
    static const constexpr double x{_start_x + (_index % _size_x) * _step_size + _step_size / 2};

    /**
     * @brief The y value used for the iteration.
     */
    static const constexpr double y{_start_y + (_size_y - _index / _size_x) * _step_size - _step_size / 2};

  public: // Static member variables
    /**
     * @brief The resulting pixel value.
     */
    static const constexpr uint8_t value{mandelbrot_iteration_start<x, y>::start::value_provider::value};
};

/**
 * @brief A class that is a reference to the next value.
 */
template <bool _has_next, std::size_t _index, double _start_x, double _start_y, double _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot_pixel_next {
  public: // Assert that the given values are within expected bounds
    static_assert(_step_size > 0, "The step size needs to be greater then zero.");
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
template <std::size_t _index, double _start_x, double _start_y, double _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot_pixel_next<false, _index, _start_x, _start_y, _step_size, _size_x, _size_y> {
  public: // Assert that the given values are within expected bounds
    static_assert(_step_size > 0, "The step size needs to be greater then zero.");
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
template <std::size_t _index, double _start_x, double _start_y, double _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot_pixel {
  public: // Assert that the given values are within expected bounds
    static_assert(_step_size > 0, "The step size needs to be greater then zero.");
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
template <double _start_x, double _start_y, double _step_size, std::size_t _size_x, std::size_t _size_y>
class mandelbrot {
  public: // Assert that the given values are within expected bounds
    static_assert(_step_size > 0, "The step size needs to be greater then zero.");
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
    static const constexpr double start_x{_start_x};

    /**
     * @brief The x start value.
     */
    static const constexpr double start_y{_start_y};

    /**
     * @brief The step size of each pixel.
     */
    static const constexpr double step_size{_step_size};

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