# SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
# SPDX-License-Identifier: MIT

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
    set(CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    # include CTest to run default executable
    include(CTest)
endif()

# Add subfolders with the different project
add_subdirectory(00_preprocessor)
add_subdirectory(01_basics)
add_subdirectory(02_metaprogramming)
add_subdirectory(03_concepts)
