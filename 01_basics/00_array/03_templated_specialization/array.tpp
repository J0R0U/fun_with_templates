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

array<bool>::bool_wrapper::bool_wrapper(const std::size_t           &_index,
                                        const underlying_type       &_mask,
                                        const underlying_array_type &_data)
    : m_index{_index},
      m_mask{_mask},
      m_data{_data}
{
}

array<bool>::bool_wrapper &array<bool>::bool_wrapper::operator=(const bool &_value)
{
    if (_value) {
        m_data[m_index] |= m_mask;
    } else {
        m_data[m_index] &= ~(m_mask);
    }

    return *this;
}

array<bool>::bool_wrapper::operator bool() const
{
    return (m_data[m_index] & m_mask) != 0;
}

array<bool>::underlying_array_type array<bool>::allocate_for_bits(const std::size_t &_bits, std::size_t &_array_size)
{
    _array_size = (_bits + s_underlying_type_bit_size - 1) / s_underlying_type_bit_size;

    const array<bool>::underlying_array_type ret = new underlying_type[_array_size];

    for (std::size_t i{0}; i < _array_size; ++i) {
        ret[0] = 0;
    }

    return ret;
}

array<bool>::array(const std::size_t &_size)
{
    if (_size > 0) {
        m_size = _size;
        m_data = allocate_for_bits(_size, m_array_size);
    } else {
        m_size = 0;
    }
}

array<bool>::array(const array<bool> &_other)
{
    if (_other.m_size > 0) {
        m_size       = _other.m_size;
        m_array_size = _other.m_array_size;
        m_data       = new underlying_type[m_array_size];

        std::memcpy(m_data, _other.m_data, m_array_size * sizeof(content_type));
    } else {
        m_size = 0;
    }
}

array<bool>::array(array<bool> &&_other)
    : m_size{_other.m_size},
      m_array_size{_other.m_array_size},
      m_data{_other.m_data}
{
    _other.m_size = 0;
}

array<bool>::~array()
{
    if (m_size > 0) {
        delete[] m_data;
    }
}

std::size_t array<bool>::size() const
{
    return m_size;
}

std::size_t array<bool>::used_bits() const
{
    return m_array_size * s_underlying_type_bit_size;
}

void array<bool>::resize(const std::size_t &_size)
{
    const bool            delete_old_data{m_size > 0};
    underlying_array_type old_data{m_data};

    m_size = _size;
    if (m_size > 0) {
        const std::size_t old_array_size{m_array_size};

        m_data = allocate_for_bits(_size, m_array_size);

        const std::size_t byte_size{std::min(m_array_size, old_array_size) * sizeof(underlying_array_type)};
        if (byte_size > 0) {
            std::memcpy(m_data, old_data, byte_size);
        }

        for (std::size_t i{byte_size}; i < m_array_size; ++i) {
            m_data[i] = 0;
        }
    }

    if (delete_old_data) {
        delete[] old_data;
    }
}

array<bool>::bool_wrapper array<bool>::operator[](const std::size_t &_index)
{
    const std::size_t     index{_index / s_underlying_type_bit_size};
    const std::size_t     offset{_index - index * s_underlying_type_bit_size};
    const underlying_type mask{static_cast<underlying_type>(1u << offset)};

    return array<bool>::bool_wrapper{
        index,
        mask,
        m_data};
}

const array<bool>::bool_wrapper array<bool>::operator[](const std::size_t &_index) const
{
    const std::size_t     index{_index / s_underlying_type_bit_size};
    const std::size_t     offset{_index - index * s_underlying_type_bit_size};
    const underlying_type mask{static_cast<underlying_type>(1u << offset)};

    return array<bool>::bool_wrapper{
        _index / s_underlying_type_bit_size,
        mask,
        m_data};
}

array<bool> &array<bool>::operator=(const array<bool> &_other)
{
    if (m_size > 0) {
        delete[] m_data;
    }

    m_size = _other.m_size;
    if (m_size > 0) {
        m_array_size = _other.m_array_size;
        m_data       = new underlying_type[m_array_size];

        std::memcpy(m_data, _other.m_data, m_array_size * sizeof(content_type));
    }

    return *this;
}

array<bool> &array<bool>::operator=(array<bool> &&_other)
{
    if (m_size > 0) {
        delete[] m_data;
    }

    m_size       = _other.m_size;
    m_array_size = _other.m_array_size;
    m_data       = _other.m_data;

    _other.m_size = 0;

    return *this;
}