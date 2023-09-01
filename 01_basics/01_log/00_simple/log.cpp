// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#include "log.hpp"

#include <cstdarg>
#include <cstdio>

void log(const cstring &_format, ...)
{
    fputs("Debug: ", stdout);

    va_list args;
    va_start(args, _format);

    vprintf(_format, args);

    va_end(args);
}