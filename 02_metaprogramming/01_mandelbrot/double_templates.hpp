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

#ifndef DOUBLE_TEMPLATES_HPP_
#define DOUBLE_TEMPLATES_HPP_

#include <cmath>
#include <cstdint>
#include <limits>

/**
 * @brief The factor for converting form double to fixed size decimal number and
 *        back.
 */
#define tdouble_fixed_factor 1000000

/**
 * @brief Converts a double to an integer representing a fixed size decimal
 *        number.
 *
 * @param _value The double value which should be converted.
 * @return The fixed size representation.
 */
constexpr long long int tdouble_fixed_to_value(const long double &_value)
{
    const long double v{_value * tdouble_fixed_factor};

    return ((v > std::numeric_limits<long long int>::max())
                ? std::numeric_limits<long long int>::max()
                : ((v < std::numeric_limits<long long int>::min())
                       ? std::numeric_limits<long long int>::min()
                       : v));
}

/**
 * @brief Class that handles doubles in template parameters.
 */
template <long long int _value>
class tdouble_fixed {
  public:
    /**
     * @brief The double value, passed at the parameter.
     */
    static const constexpr long double value{static_cast<long double>(_value) / tdouble_fixed_factor};
};

/**
 * @brief Convert double to fixed size decimal number for passing doubles as
 *        values in template parameters.
 */
#define tdouble(_value) \
    tdouble_fixed<tdouble_fixed_to_value(_value)>

#endif // DOUBLE_TEMPLATES_HPP_