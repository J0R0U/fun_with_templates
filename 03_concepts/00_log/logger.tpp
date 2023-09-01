// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

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