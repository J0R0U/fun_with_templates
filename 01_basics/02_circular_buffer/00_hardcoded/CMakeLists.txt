# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

# Add executable taget
add_executable(basics_circular_buffer_hardcoded "circular_buffer.hpp" "circular_buffer.cpp" "main.cpp")

# Set target properties
target_compile_options(basics_circular_buffer_hardcoded PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
set_property(TARGET basics_circular_buffer_hardcoded PROPERTY CXX_STANDARD 11)

# Run executable target as a test
add_test(
    NAME basics::circular_buffer::hardcoded
    COMMAND basics_circular_buffer_hardcoded
)