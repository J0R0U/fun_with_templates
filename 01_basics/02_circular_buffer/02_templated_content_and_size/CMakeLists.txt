# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

# Add executable taget
add_executable(basics_circular_buffer_templated_content_and_size "circular_buffer.hpp" "main.cpp")

# Set target properties
target_compile_options(basics_circular_buffer_templated_content_and_size PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
set_property(TARGET basics_circular_buffer_templated_content_and_size PROPERTY CXX_STANDARD 11)

# Run executable target as a test
add_test(
    NAME basics::circular_buffer::templated_content_and_size
    COMMAND basics_circular_buffer_templated_content_and_size
)