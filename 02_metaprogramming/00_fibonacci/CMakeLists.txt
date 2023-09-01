# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

# Add executable taget
add_executable(metaprogramming_fibonacci "fibonacci.hpp" "main.cpp")

# Set target properties
target_compile_options(metaprogramming_fibonacci PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
set_property(TARGET metaprogramming_fibonacci PROPERTY CXX_STANDARD 11)

# Run executable target as a test
add_test(
    NAME metaprogramming::fibonacci
    COMMAND metaprogramming_fibonacci
)