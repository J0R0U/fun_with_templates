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

#include "mandelbrot.hpp"

#include <fstream>
#include <iostream>
#include <string>

/**
 * @brief The tiny mandelbrot picture type.
 *
 * Start x:   -2.0
 * Start y:   -1.5
 * Step size:  0.5
 * Size x:     6
 * Size y:     6
 */
// typedef mandelbrot<-2, -1.5, 0.5, 6, 6> picture;

/**
 * @brief The small mandelbrot picture type.
 *
 * Start x:   -2.0
 * Start y:   -1.5
 * Step size:  0.1
 * Size x:     30
 * Size y:     30
 */
typedef mandelbrot<-2.0, -1.5, 0.1, 30, 30> picture;

/**
 * @brief The large mandelbrot picture type.
 *
 * Start x:   -2.00
 * Start y:   -1.50
 * Step size:  0.05
 * Size x:     60
 * Size y:     60
 */
// typedef mandelbrot<-2, -1.5, 0.05, 60, 60> picture;

/**
 * @brief The huge mandelbrot picture type.
 *
 * Start x:   -2.000
 * Start y:   -1.500
 * Step size:  0.025
 * Size x:     120
 * Size y:     120
 */
// typedef mandelbrot<-2, -1.5, 0.025, 120, 120> picture;

/**
 * @brief Write a mandelbrot pixel to to a file.
 *
 * @param _file The stream for writing to the file.
 */
template <typename _pixel_type>
void write_pixel(std::ofstream &_file)
{
    _file << _pixel_type::value_calculator::value;

    write_pixel<typename _pixel_type::next_provider::next>(_file);
}

/**
 * @brief Write a mandelbrot pixel to to a file.
 *
 * This function is a hook if the last pixel is reached.
 *
 * @param _file The stream for writing to the file.
 */
template <>
void write_pixel<void>(std::ofstream &_file)
{
    static_cast<void>(_file);
}

/**
 * @brief Write a mandelbrot picture to a file
 *
 * @param _filename The filename of the picture.
 */
template <typename _mandelbrot_type>
void write_pgm_to_file(const std::string &_filename)
{
    std::ofstream file{_filename, std::ios_base::binary | std::ios_base::trunc};

    file << "P5\n"
         << "# This is an example for meta programming in C++. The given image was\n"
         << "# created using templates at compile time. Have a look, maybe you\n"
         << "# recognize the motive :)\n"
         << _mandelbrot_type::size_x << " " << _mandelbrot_type::size_y << "\n"
         << "255\n";

    write_pixel<typename _mandelbrot_type::pixels>(file);
}

/**
 * @brief The main function.
 *
 * @return The exit status.
 */
int main()
{
    std::cout << "Static mandelbrot picture (generated by compiler):\n"
              << "  - startX:   " << picture::start_x << '\n'
              << "  - startY:   " << picture::start_y << '\n'
              << "  - stepSize: " << picture::step_size << '\n'
              << "  - sizeX:    " << picture::size_x << '\n'
              << "  - sizeY:    " << picture::size_y << '\n';

    write_pgm_to_file<picture>("mandelbrot.pgm");

    return 0;
}