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

#include "matrix.hpp"

#include <random>
#include <sstream>

matrix::column::column(const std::size_t &_x, const std::size_t &_n, const array_t &_data_ptr)
    : m_x{_x},
      m_n{_n},
      m_data_ptr{_data_ptr}
{
}

matrix::column::content_t &matrix::column::operator[](const std::size_t &_y)
{
    return m_data_ptr[_y * m_n + m_x];
}

matrix::const_column::const_column(const std::size_t &_x, const std::size_t &_n, const array_t &_data_ptr)
    : m_x{_x},
      m_n{_n},
      m_data_ptr{_data_ptr}
{
}

matrix::const_column::content_t &matrix::const_column::operator[](const std::size_t &_y)
{
    return m_data_ptr[_y * m_n + m_x];
}

matrix matrix::random()
{
    std::random_device                         dev;
    std::mt19937                               random_number_generator(dev());
    std::uniform_int_distribution<std::size_t> size_distribution(5, 10);
    std::uniform_real_distribution<double>     content_distribution(-100.0, 100.0);

    matrix ret{size_distribution(random_number_generator), size_distribution(random_number_generator)};

    for (size_t i{0}; i < ret.m_n * ret.m_m; ++i) {
        ret.m_data[i] = content_distribution(random_number_generator);
    }

    return ret;
}

matrix::matrix(const std::size_t &_n, const std::size_t &_m)
    : m_n{_n},
      m_m{_m},
      m_data{m_n == 0 || m_m == 0 ? nullptr : std::make_unique<double[]>(m_n * m_m)}
{
}

std::size_t matrix::n() const
{
    return m_n;
}

std::size_t matrix::m() const
{
    return m_m;
}

std::string matrix::get_log_value() const
{
    std::ostringstream ret;

    ret << "Matrix [" << m_n << " x " << m_m << "]";

    return ret.str();
}

matrix::column matrix::operator[](const std::size_t &_x)
{
    return column{_x, m_n, m_data.get()};
}

matrix::const_column matrix::operator[](const std::size_t &_x) const
{
    return const_column{_x, m_n, m_data.get()};
}

std::ostream &operator<<(std::ostream &_stream, const matrix &_matrix)
{
    for (std::size_t i = 0; i < _matrix.n(); ++i) {
        for (std::size_t j = 0; j < _matrix.m(); ++j) {
            _stream << ' ' << _matrix[i][j];
        }
        _stream << '\n';
    }

    return _stream;
}