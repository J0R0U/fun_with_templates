# -----------------------------------------------------------------------------
# 
# This file is part of fun_with_templates.
# 
# fun_with_templates is free software: you can redistribute it and/or modify it
# under the terms of the "Do What The Fuck You Want To Public License", Version
# 2, as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
# 
# THE PROJECT "fun_with_templates" IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO
# EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
# OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH "fun_with_templates" OR THE USE OR
# OTHER DEALINGS IN THE SOFTWARE.
# 
# SPDX-License-Identifier: WTFPL
# 
# -----------------------------------------------------------------------------

# Add executable taget
add_executable(basics_circular_buffer_hardcoded "circular_buffer.hpp" "circular_buffer.cpp" "main.cpp")

# Set target properties, fetures and directories
target_compile_options(basics_circular_buffer_hardcoded PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
set_property(TARGET basics_circular_buffer_hardcoded PROPERTY CXX_STANDARD 11)

# Run executable target as a test
add_test(
    NAME basics::circular_buffer::hardcoded
    COMMAND basics_circular_buffer_hardcoded
)