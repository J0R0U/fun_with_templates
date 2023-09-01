# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

# Add executable taget
add_executable(basics_log_templated_variadic_full "log.hpp" "main.cpp")

# Set target properties
target_compile_options(basics_log_templated_variadic_full PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
set_property(TARGET basics_log_templated_variadic_full PROPERTY CXX_STANDARD 11)

# Run executable target as a test
add_test(
    NAME basics::log::templated_variadic_full
    COMMAND basics_log_templated_variadic_full
)