# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

# Add executable taget
add_executable(basics_array_templated_split "array.hpp" "array.tpp" "main.cpp")

# Set target properties
target_compile_options(basics_array_templated_split PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
set_property(TARGET basics_array_templated_split PROPERTY CXX_STANDARD 11)

# Run executable target as a test
add_test(
    NAME basics::array::templated_split
    COMMAND basics_array_templated_split
)