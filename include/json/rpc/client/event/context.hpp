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
 * @file json/rpc/client/message.hpp
 *
 * @brief JSON client message interface
 *
 * Message used for communication between clients and proactor
 * */

#ifndef JSON_CXX_RPC_CLIENT_EVENT_CONTEXT_HPP
#define JSON_CXX_RPC_CLIENT_EVENT_CONTEXT_HPP

#include <json/json.hpp>
#include <json/rpc/list.hpp>
#include <json/rpc/client/event.hpp>
#include <json/rpc/client/protocol.hpp>
#include <json/rpc/client/protocol/ipv4.hpp>

#include <string>

namespace json {
namespace rpc {
namespace client {
namespace event {

class Context : public Event {
public:
    Context(Client* client, const Protocol& protocol);
    ~Context();

    bool check(const Client* client) const { return get_client() == client; }

    void dispatch_event(Event* pevent) {
        m_events.push(pevent);
    }
private:
    union ContextProtocol {
        protocol::IPv4 ipv4;
        ~ContextProtocol() {}
    } m_protocol{};
    ProtocolType m_protocol_type{ProtocolType::UNDEFINED};
    List m_events{};

    template<class T>
    void create_protocol(const Protocol& protocol) {
        new (&m_protocol) T(static_cast<const T&>(protocol));
    }
};

class DestroyContext : public Event {
public:
    DestroyContext(Client* client) :
        Event(EventType::DESTROY_CONTEXT, client, AUTO_REMOVE) { }
};

} /* event */
} /* client */
} /* rpc */
} /* json */

#endif /* JSON_CXX_RPC_CLIENT_EVENT_CONTEXT_HPP */
