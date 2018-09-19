/**
 * Copyright (c) 2011-2018 libbitcoin developers (see COAUTHORS)
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
#ifndef BITCOINVC_LOG_ROTABLE_FILE_HPP
#define BITCOINVC_LOG_ROTABLE_FILE_HPP

#include <boost/filesystem.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <bitcoin/bitcoin/define.hpp>

namespace bitcoinvc {
namespace log {

typedef boost::shared_ptr<std::ostream> stream;
typedef boost::log::formatting_ostream::ostream_type formatter;

struct rotable_file
{
    boost::filesystem::path original_log;
    boost::filesystem::path archive_directory;
    size_t rotation_size;
    size_t minimum_free_space;
    size_t maximum_archive_size;
    size_t maximum_archive_files;
};

} // namespace log
} // namespace bitcoinvc

#endif
