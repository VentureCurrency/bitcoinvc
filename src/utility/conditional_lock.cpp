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
#include <bitcoin/bitcoin/utility/conditional_lock.hpp>

#include <memory>
#include <bitcoin/bitcoin/utility/thread.hpp>

namespace bitcoinvc {

conditional_lock::conditional_lock(bool lock)
  : conditional_lock(lock ? std::make_shared<shared_mutex>() : nullptr)
{
}

conditional_lock::conditional_lock(std::shared_ptr<shared_mutex> mutex_ptr)
  : mutex_ptr_(mutex_ptr)
{
    if (mutex_ptr_)
        mutex_ptr->lock();
}

conditional_lock::~conditional_lock()
{
    if (mutex_ptr_)
        mutex_ptr_->unlock();
}

} // namespace bitcoinvc
