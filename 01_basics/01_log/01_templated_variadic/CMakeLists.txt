# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

# Add executable taget
add_executable(basics_log_templated_variadic "log.hpp" "main.cpp")

# Set target properties
target_compile_options(basics_log_templated_variadic PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
set_property(TARGET basics_log_templated_variadic PROPERTY CXX_STANDARD 11)

# Run executable target as a test
add_test(
    NAME basic::log::templated_variadic
    COMMAND basics_log_templated_variadic
)