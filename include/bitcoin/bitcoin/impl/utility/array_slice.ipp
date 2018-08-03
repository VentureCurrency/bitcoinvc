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
#ifndef BITCOINVC_ARRAY_SLICE_IPP
#define BITCOINVC_ARRAY_SLICE_IPP

namespace bitcoinvc {

template <typename Iterable>
template <typename Container>
array_slice<Iterable>::array_slice(const Container& container)
  : begin_(container.data()), end_(container.data() + container.size())
{
}

template <typename Iterable>
array_slice<Iterable>::array_slice(const Iterable* begin, const Iterable* end)
  : begin_(begin), end_(end)
{
}

template <typename Iterable>
const Iterable* array_slice<Iterable>::begin() const
{
    return begin_;
}

template <typename Iterable>
const Iterable* array_slice<Iterable>::end() const
{
    return end_;
}

template <typename Iterable>
const Iterable* array_slice<Iterable>::data() const
{
    return begin_;
}

template <typename Iterable>
std::size_t array_slice<Iterable>::size() const
{
    return end_ - begin_;
}

template <typename Iterable>
bool array_slice<Iterable>::empty() const
{
    return end_ == begin_;
}

} // namespace bitcoinvc

#endif

