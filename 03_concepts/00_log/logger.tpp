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

#include <iostream>
#include <string>

/**
 * @brief Write a given argument to the given stream.
 *
 * It is required, that the stream operator for the argument type is overloaded
 * and the value does not provide a log message.
 *
 * @param _stream The stream to write to.
 * @param _value The value that should be written.
 */
template <typename _type>
void write_log_internal(std::ostream &_stream, const _type &_value) requires can_only_be_written_to_stream<_type>
{
    _stream << " " << _value;
}

/**
 * @brief Write a given argument to the given stream.
 *
 * It is required, that the stream operator for the argument provides a log
 * message.
 *
 * @param _stream The stream to write to.
 * @param _value The value that should be written.
 */
template <typename _type>
requires provides_custom_log_message<_type>
void write_log_internal(std::ostream &_stream, const _type &_value)
{
    _stream << " " << _value.get_log_value();
}

/**
 * @brief Write a given argument to the given stream.
 *
 * Only arguments that are can be logged are allowed.
 *
 * This function is needed for parameter unpacking and is the function called,
 * when only one argument is left.
 *
 * @param _stream The stream to write to.
 * @param _value The value that should be written.
 */
template <can_be_logged _type>
void log_internal(std::ostream &_stream, const _type &_last)
{
    write_log_internal(_stream, _last);
}

/**
 * @brief Write a given argument to the given stream.
 *
 * Only arguments that are can be logged are allowed.
 *
 * This function is needed for parameter unpacking consumes a template parameter
 * pack one by one.
 *
 * @param _stream The stream to write to.
 * @param _value The value that should be written.
 */
template <can_be_logged _type, can_be_logged... _remainder_types>
void log_internal(std::ostream &_stream, const _type &_first, const _remainder_types &..._args)
{
    write_log_internal(_stream, _first);
    log_internal(_stream, _args...);
}

template <can_be_logged... _arg_types>
void log(const _arg_types &..._args)
{
    log_internal(std::cout << "DEBUG", _args...);

    std::cout << "\n";
}