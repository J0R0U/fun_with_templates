// SPDX-FileCopyrightText: 2023 J0R0U <https://github.com/J0R0U>
// SPDX-License-Identifier: MIT

#include <algorithm>
#include <cstring>

template <typename _content_type>
array<_content_type>::array(const std::size_t &_size)
{
    if (_size > 0) {
        m_size = _size;
        m_data = new content_type[m_size];
    } else {
        m_size = 0;
    }
}

template <typename _content_type>
array<_content_type>::array(const array<_content_type> &_other)
{
    if (_other.m_size > 0) {
        m_size = _other.m_size;
        m_data = new content_type[m_size];

        std::memcpy(m_data, _other.m_data, m_size * sizeof(content_type));
    } else {
        m_size = 0;
    }
}

template <typename _content_type>
array<_content_type>::array(array<_content_type> &&_other)
    : m_size{_other.m_size},
      m_data{_other.m_data}
{
    _other.m_size = 0;
}

template <typename _content_type>
array<_content_type>::~array()
{
    if (m_size > 0) {
        delete[] m_data;
    }
}

template <typename _content_type>
std::size_t array<_content_type>::size() const
{
    return m_size;
}

template <typename _content_type>
void array<_content_type>::resize(const std::size_t &_size)
{
    const bool    delete_old_data{m_size > 0};
    content_type *old_data{m_data};

    if (_size > 0) {
        m_data = new content_type[m_size];

        const std::size_t byte_size{std::min(m_size, _size) * sizeof(content_type)};
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

template <typename _content_type>
_content_type &array<_content_type>::operator[](const std::size_t &_index)
{
    return m_data[_index];
}

template <typename _content_type>
const _content_type &array<_content_type>::operator[](const std::size_t &_index) const
{
    return m_data[_index];
}

template <typename _content_type>
array<_content_type> &array<_content_type>::operator=(const array<content_type> &_other)
{
    if (m_size > 0) {
        delete[] m_data;
    }

    m_size = _other.m_size;
    if (m_size > 0) {
        m_data = new content_type[m_size];

        std::memcpy(m_data, _other.m_data, m_size * sizeof(content_type));
    }

    return *this;
}

template <typename _content_type>
array<_content_type> &array<_content_type>::operator=(array<content_type> &&_other)
{
    if (m_size > 0) {
        delete[] m_data;
    }

    m_size = _other.m_size;
    m_data = _other.m_data;

    _other.m_size = 0;

    return *this;
}
