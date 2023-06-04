// ----------------------------------------------------------------------------
//
// This file is part of fun_with_templates.
//
// fun_with_templates is free software: you can redistribute it and/or modify
// it under the terms of the "Do What The Fuck You Want To Public License",
// Version 2, as published by Sam Hocevar. See http://www.wtfpl.net/ for more
// details.
//
// THE PROJECT "fun_with_templates" IS PROVIDED "AS IS", WITHOUT WARRANTY OF
// ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO
// EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH "fun_with_templates"
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
// SPDX-License-Identifier: WTFPL
//
// ----------------------------------------------------------------------------

#include "circular_buffer.hpp"

#include <algorithm>
#include <cstring>

circular_buffer::circular_buffer()
    : m_data{new int[s_capacity]},
      m_first_free{0},
      m_first_valid{0}
{
}

circular_buffer::circular_buffer(const circular_buffer &_other)
    : m_data{new int[s_capacity]},
      m_first_free{_other.m_first_free},
      m_first_valid{_other.m_first_free}
{
    std::memcpy(m_data, _other.m_data, s_capacity);
}

circular_buffer::circular_buffer(circular_buffer &&_other)
    : m_data{std::move(_other.m_data)},
      m_first_free{std::move(_other.m_first_free)},
      m_first_valid{std::move(_other.m_first_valid)}
{
    _other.m_data = nullptr;
}

circular_buffer::~circular_buffer()
{
    if (m_data) {
        delete m_data;
    }
}

std::size_t circular_buffer::capacity() const
{
    return s_capacity;
}

std::size_t circular_buffer::size() const
{
    if (m_first_free >= m_first_valid) {
        return m_first_free - m_first_valid;
    }

    return s_capacity - m_first_valid + m_first_free;
}

void circular_buffer::push(const int &_value)
{
    m_data[m_first_free] = _value;

    m_first_free = m_first_free + 1;

    if (m_first_free == s_capacity) {
        m_first_free = 0;
    }
}

int circular_buffer::pop()
{
    int value = m_data[m_first_valid];

    m_first_valid = m_first_valid + 1;

    if (m_first_valid == s_capacity) {
        m_first_valid = 0;
    }

    return value;
}

circular_buffer &circular_buffer::operator=(const circular_buffer &_other)
{
    if (m_data) {
        delete m_data;
    }

    m_data        = new int[s_capacity];
    m_first_free  = _other.m_first_free;
    m_first_valid = _other.m_first_valid;

    std::memcpy(m_data, _other.m_data, s_capacity);

    return *this;
}

circular_buffer &circular_buffer::operator=(circular_buffer &&_other)
{
    if (m_data) {
        delete m_data;
    }

    m_data        = std::move(_other.m_data);
    m_first_free  = std::move(_other.m_first_free);
    m_first_valid = std::move(_other.m_first_valid);

    _other.m_data = nullptr;

    return *this;
}