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
#include <bitcoin/bitcoin/wallet/qrcode.hpp>

#include <iostream>
#include <string>
#include <bitcoin/bitcoin/constants.hpp>
#include <bitcoin/bitcoin/define.hpp>
#include <bitcoin/bitcoin/utility/data.hpp>
#include <bitcoin/bitcoin/utility/container_sink.hpp>
#include <bitcoin/bitcoin/utility/container_source.hpp>
#include <bitcoin/bitcoin/utility/istream_reader.hpp>
#include <bitcoin/bitcoin/utility/ostream_writer.hpp>

#ifdef WITH_QRENCODE

namespace bitcoinvc {
namespace wallet {

data_chunk qr::encode(const data_chunk& data)
{
    return qr::encode(data, version, level, mode, case_sensitive);
}

data_chunk qr::encode(const data_chunk& data, uint32_t version,
    error_recovery_level level, encode_mode mode, bool case_sensitive)
{
    data_chunk out;
    data_sink ostream(out);
    data_source istream(data);

    if (qr::encode(istream, version, level, mode, case_sensitive, ostream))
        return out;

    return {};
}

bool qr::encode(std::istream& in, std::ostream& out)
{
    return qr::encode(in, version, level, mode, case_sensitive, out);
}

bool qr::encode(std::istream& in, uint32_t version, error_recovery_level level,
    encode_mode mode, bool case_sensitive, std::ostream& out)
{
    std::string qr_string;
    getline(in, qr_string);

    const auto qrcode = QRcode_encodeString(qr_string.c_str(), version,
        level, mode, case_sensitive);

    if (qrcode == nullptr)
        return false;

    const auto area = qrcode->width * qrcode->width;
    if ((area == 0) || (qrcode->width > max_int32 / qrcode->width))
        return false;

    auto width_ptr = reinterpret_cast<const uint8_t*>(&qrcode->width);
    auto version_ptr = reinterpret_cast<const uint8_t*>(&qrcode->version);

    // Write out raw format of QRcode structure (defined in qrencode.h).
    // Format written is:
    // int version
    // int width
    // unsigned char* data (of width^2 length)
    ostream_writer sink(out);
    sink.write_bytes(version_ptr, sizeof(int));
    sink.write_bytes(width_ptr, sizeof(int));
    sink.write_bytes(qrcode->data, area);
    out.flush();

    return true;
}

} // namespace wallet
} // namespace bitcoinvc

#endif // WITH_QRENCODE
