// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#include "array.hpp"

#include <algorithm>
#include <cstring>

array::array(const std::size_t &_size)
{
    if (_size > 0) {
        m_size = _size;
        m_data = new int[m_size];
    } else {
        m_size = 0;
    }
}

array::array(const array &_other)
{
    if (_other.m_size > 0) {
        m_size = _other.m_size;
        m_data = new int[m_size];

        std::memcpy(m_data, _other.m_data, m_size * sizeof(int));
    } else {
        m_size = 0;
    }
}

array::array(array &&_other)
    : m_size{_other.m_size},
      m_data{_other.m_data}
{
    _other.m_size = 0;
}

array::~array()
{
    if (m_size > 0) {
        delete[] m_data;
    }
}

std::size_t array::size() const
{
    return m_size;
}

void array::resize(const std::size_t &_size)
{
    const bool delete_old_data{m_size > 0};
    int       *old_data{m_data};

    if (_size > 0) {
        m_data = new int[m_size];

        const std::size_t byte_size{std::min(m_size, _size) * sizeof(int)};
        if (byte_size > 0) {
            std::memcpy(m_data, old_data, byte_size);
        }

        m_size = _size;
    } else {
        m_size = 0;
    }

    if (delete_old_data) {
        delete[] old_data;
    }
}

int &array::operator[](const std::size_t &_index)
{
    return m_data[_index];
}

const int &array::operator[](const std::size_t &_index) const
{
    return m_data[_index];
}

array &array::operator=(const array &_other)
{
    if (m_size > 0) {
        delete[] m_data;
    }

    m_size = _other.m_size;
    if (m_size > 0) {
        m_data = new int[m_size];

        std::memcpy(m_data, _other.m_data, m_size * sizeof(int));
    }

    return *this;
}

array &array::operator=(array &&_other)
{
    if (m_size > 0) {
        delete[] m_data;
    }

    m_size = _other.m_size;
    m_data = _other.m_data;

    _other.m_size = 0;

    return *this;
}