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
add_executable(basics_log_templated_variadic_full "log.hpp" "main.cpp")

# Set target properties
target_compile_options(basics_log_templated_variadic_full PRIVATE ${FUN_TEMPLATE_WARNING_OPTION})
set_property(TARGET basics_log_templated_variadic_full PROPERTY CXX_STANDARD 11)

# Run executable target as a test
add_test(
    NAME basics::log::templated_variadic_full
    COMMAND basics_log_templated_variadic_full
)