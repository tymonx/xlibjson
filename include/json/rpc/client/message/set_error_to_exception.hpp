/*!
 * @copyright
 * Copyright (c) 2015, Tymoteusz Blazejczyk
 *
 * @copyright
 * All rights reserved.
 *
 * @copyright
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * @copyright
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * @copyright
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * @copyright
 * * Neither the name of json-cxx nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * @copyright
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @file json/rpc/client/message/set_error_to_exception.hpp
 *
 * @brief Create context event
 * */

#ifndef JSON_CXX_RPC_CLIENT_SET_ERROR_TO_EXCEPTION_HPP
#define JSON_CXX_RPC_CLIENT_SET_ERROR_TO_EXCEPTION_HPP

#include <json/rpc/client/message.hpp>

#include <json/rpc/error.hpp>

#include <exception>
#include <functional>

namespace json {
namespace rpc {
namespace client {
namespace message {

class SetErrorToException : public Message {
public:
    using Callback = std::function<std::exception_ptr(const Error&)>;

    SetErrorToException(Client* client, const Callback& callback);

    virtual ~SetErrorToException() final;

    const Callback& get_callback() const { return m_callback; }
private:
    Callback m_callback{nullptr};
};

} /* message */
} /* client */
} /* rpc */
} /* json */

#endif /* JSON_CXX_RPC_CLIENT_SET_ERROR_TO_EXCEPTION_HPP */
