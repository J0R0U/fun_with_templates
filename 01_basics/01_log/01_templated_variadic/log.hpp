// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

#include <cstdio>

/**
 * @brief A type for char strings.
 */
typedef const char *cstring;

/**
 * @brief Logs the message to stdout.
 *
 * @param _format The message format.
 * @param _args The message arguments.
 */
template <typename... _arg_types>
void log(const cstring &_format, _arg_types... _args)
{
    fputs("Debug: ", stdout);
    printf(_format, _args...);
}

#endif // CONSTANTS_HPP_