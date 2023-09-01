// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

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

#endif // LOGGER_HPP_