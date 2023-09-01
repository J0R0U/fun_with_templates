# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

# There is no actual executable, but the preprocessorrun is executed as a test
add_test(
    NAME preprocessor
    COMMAND "${CMAKE_CXX_COMPILER}" -E -I "${CMAKE_CURRENT_SOURCE_DIR}" -o main.i "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)