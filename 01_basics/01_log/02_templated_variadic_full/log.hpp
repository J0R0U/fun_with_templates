// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

#include <iostream>

/**
 * @brief Logs one message argument to stdout.
 *
 * @param _arg The message argument that will be logged.
 */
template <typename _arg_type>
void internal_log(_arg_type _arg)
{
    std::cout << _arg;
}

/**
 * @brief Logs a message to stdout.
 *
 * @param _first The argument, that should be logged next.
 * @param _args The leftover message arguments, that will be printed after the
 *              argument _first is printed.
 */
template <typename _first_arg_type, typename... _arg_types>
void internal_log(_first_arg_type _first, _arg_types... _args)
{
    internal_log(_first);
    internal_log(_args...);
}

/**
 * @brief Logs the message to stdout.
 *
 * @param _args The message, that should be logged.
 */
template <typename... _arg_types>
void log(_arg_types... _args)
{
    std::cout << "Debug: ";
    internal_log(_args...);
    std::cout << "\n";
}

#endif // CONSTANTS_HPP_