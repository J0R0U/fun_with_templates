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

# Required cmake version
cmake_minimum_required(VERSION 3.12.0)

# Define current project
project(
    fun_with_template
    VERSION 0.0.1
    LANGUAGES CXX
)

# Set the project description
set(PROJECT_DESCRIPTION "\
A small project showing how C++ templates can be used. For more detailed \
description have a look at the README.md file.\
")

# Set options to treat warnings as errors
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(FUN_TEMPLATE_WARNING_OPTION "-Wall" "-Wextra" "-Wpedantic" "-Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(FUN_TEMPLATE_WARNING_OPTION "-Wall" "-Wextra" "-Wpedantic" "-Weverything" "-Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(FUN_TEMPLATE_WARNING_OPTION "/W4" "/WX")
endif()

# Check if current project is the main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Disable extensions, only the standart should be allowed
    set(CMAKE_CXX_EXTENSIONS OFF)

    # include CTest to run default executable
    include(CTest)
endif()

# Add subfolders with the different project
add_subdirectory(00_preprocessor)
add_subdirectory(01_basics)
add_subdirectory(02_metaprogramming)
