# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

# Add executable taget
add_executable(concepts_log "logger.hpp" "logger.tpp" "matrix.hpp" "matrix.cpp" "main.cpp")

# Set target properties
target_compile_options(concepts_log PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
set_property(TARGET concepts_log PROPERTY CXX_STANDARD 20)

# Run executable target as a test
add_test(
    NAME concepts::log
    COMMAND concepts_log
)
