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