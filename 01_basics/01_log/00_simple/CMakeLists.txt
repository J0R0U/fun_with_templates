# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

# Add executable taget
add_executable(basic_log_simple "log.hpp" "log.cpp" "main.cpp")

# Set target properties
target_compile_options(basic_log_simple PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
set_property(TARGET basic_log_simple PROPERTY CXX_STANDARD 11)

# Run executable target as a test
add_test(
    NAME basic::log::simple
    COMMAND basic_log_simple
)