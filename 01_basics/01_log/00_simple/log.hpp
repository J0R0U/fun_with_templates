// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

/**
 * @brief A type for char strings.
 */
typedef const char *cstring;

/**
 * @brief Logs the message to stdout.
 *
 * @param _format The message format.
 * @param ... The message arguments.
 */
void log(const cstring &_format, ...);

#endif // CONSTANTS_HPP_