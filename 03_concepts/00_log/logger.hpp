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

#ifndef HASHMAP_HPP_
#define HASHMAP_HPP_

#include <concepts>
#include <ostream>

/**
 * @brief A concept, which ensures that a given type can be written to a stream
 *        and returns a stream, for chaining the calls.
 */
template <typename T>
concept can_be_written_to_stream = requires(std::ostream &_stream, const T &_value)
{
    // clang-format off
    { _stream << _value } -> std::same_as<std::ostream &>;
    // clang-format on
};

/**
 * @brief A concept, which ensures that a given type provides a custom log
 *        message.
 *
 * The provided log message is required to be stream writeable.
 */
template <typename T>
concept provides_custom_log_message = requires(std::ostream &_stream, const T &_value)
{
    // clang-format off
    { _value.get_log_value() } -> can_be_written_to_stream;
    // clang-format on
};

/**
 * @brief A concept, that requires that a given type can be written to a stream,
 *        but does not provide a custom log message.
 */
template <typename T>
concept can_only_be_written_to_stream = can_be_written_to_stream<T> && !provides_custom_log_message<T>;

/**
 * @brief A concept, that requires that a given either provides a custom log
 *        message or is writable to a stream.
 *
 * If a class provides both, only the provided custom log is considered.
 */
template <typename T>
concept can_be_logged = can_only_be_written_to_stream<T> || provides_custom_log_message<T>;

/**
 * @brief Logs the given arguments to stdout.
 *
 * @param _args The arguments that will be logged.
 */
template <can_be_logged... _arg_types>
void log(const _arg_types &..._args);

#include "logger.tpp"

#endif // HASHMAP_HPP_