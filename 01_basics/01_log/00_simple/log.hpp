// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef LOG_HPP_
#define LOG_HPP_

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

#endif // LOG_HPP_