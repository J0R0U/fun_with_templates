# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

# Add executable taget
add_executable(metaprogramming_mandelbrot "mandelbrot.hpp" "main.cpp")

# Set target properties
target_compile_options(metaprogramming_mandelbrot PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
target_compile_options(metaprogramming_mandelbrot PUBLIC "-ftemplate-depth=20000")
set_property(TARGET metaprogramming_mandelbrot PROPERTY CXX_STANDARD 20)

# Run executable target as a test
add_test(
    NAME metaprogramming::mandelbrot
    COMMAND metaprogramming_mandelbrot
)