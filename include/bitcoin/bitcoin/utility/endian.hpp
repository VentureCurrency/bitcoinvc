/**
 * Copyright (c) 2011-2017 libbitcoin developers (see COAUTHORS)
 *
 * Copyright (c) 2018 bitcoin.org.vc Bitcoin Venture Currency/Jason Coombs (see COAUTHORS)￼
 *
 ￼* This file is part of bitcoinvc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BITCOINVC_ENDIAN_HPP
#define BITCOINVC_ENDIAN_HPP

#include <istream>
#include <bitcoin/bitcoin/define.hpp>
#include <bitcoin/bitcoin/utility/data.hpp>

namespace bitcoinvc {

template <typename Integer, typename Iterator>
Integer from_big_endian(Iterator start, Iterator end);

template <typename Integer, typename Iterator>
Integer from_little_endian(Iterator start, Iterator end);

template <typename Integer, typename Iterator>
Integer from_big_endian_unsafe(Iterator start);

template <typename Integer, typename Iterator>
Integer from_little_endian_unsafe(Iterator start);

template <typename Integer>
Integer from_big_endian_stream_unsafe(std::istream& stream);

template <typename Integer>
Integer from_little_endian_stream_unsafe(std::istream& stream);

template <typename Integer>
byte_array<sizeof(Integer)> to_big_endian(Integer value);

template <typename Integer>
byte_array<sizeof(Integer)> to_little_endian(Integer value);

} // namespace bitcoinvc

#include <bitcoin/bitcoin/impl/utility/endian.ipp>

#endif
