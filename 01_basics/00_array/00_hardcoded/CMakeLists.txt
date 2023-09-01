# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

# Add executable taget
add_executable(basics_array_hardcoded "array.hpp" "array.cpp" "main.cpp")

# Set target properties
target_compile_options(basics_array_hardcoded PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
set_property(TARGET basics_array_hardcoded PROPERTY CXX_STANDARD 11)

# Run executable target as a test
add_test(
    NAME basics::array::hardcoded
    COMMAND basics_array_hardcoded
)