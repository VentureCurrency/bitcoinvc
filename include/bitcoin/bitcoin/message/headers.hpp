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
#ifndef BITCOINVC_MESSAGE_HEADERS_HPP
#define BITCOINVC_MESSAGE_HEADERS_HPP

#include <cstdint>
#include <initializer_list>
#include <istream>
#include <memory>
#include <string>
#include <bitcoin/bitcoin/define.hpp>
#include <bitcoin/bitcoin/math/hash.hpp>
#include <bitcoin/bitcoin/message/header.hpp>
#include <bitcoin/bitcoin/message/inventory.hpp>
#include <bitcoin/bitcoin/message/inventory_vector.hpp>
#include <bitcoin/bitcoin/utility/data.hpp>
#include <bitcoin/bitcoin/utility/reader.hpp>
#include <bitcoin/bitcoin/utility/writer.hpp>

namespace bitcoinvc {
namespace message {

class BC_API headers
{
public:
    typedef std::shared_ptr<headers> ptr;
    typedef std::shared_ptr<const headers> const_ptr;

    static headers factory(uint32_t version, const data_chunk& data,
        const settings& settings);
    static headers factory(uint32_t version, std::istream& stream,
        const settings& settings);
    static headers factory(uint32_t version, reader& source,
        const settings& settings);

    headers();
    headers(const header::list& values);
    headers(header::list&& values);
    headers(const std::initializer_list<header>& values);
    headers(const headers& other);
    headers(headers&& other);

    header::list& elements();
    const header::list& elements() const;
    void set_elements(const header::list& values);
    void set_elements(header::list&& values);

    bool is_sequential() const;
    void to_hashes(hash_list& out) const;
    void to_inventory(inventory_vector::list& out,
        inventory::type_id type) const;

    bool from_data(uint32_t version, const data_chunk& data,
        const settings& settings);
    bool from_data(uint32_t version, std::istream& stream,
        const settings& settings);
    bool from_data(uint32_t version, reader& source, const settings& settings);
    data_chunk to_data(uint32_t version) const;
    void to_data(uint32_t version, std::ostream& stream) const;
    void to_data(uint32_t version, writer& sink) const;
    bool is_valid() const;
    void reset();
    size_t serialized_size(uint32_t version) const;

    // This class is move assignable but not copy assignable.
    headers& operator=(headers&& other);
    void operator=(const headers&) = delete;

    bool operator==(const headers& other) const;
    bool operator!=(const headers& other) const;

    static const std::string command;
    static const uint32_t version_minimum;
    static const uint32_t version_maximum;

private:
    header::list elements_;
};

} // namespace message
} // namespace bitcoinvc

#endif
