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
 * @file formatter.hpp
 *
 * @brief JSON formatter interface
 * */

#ifndef JSON_CXX_FORMATTER_HPP
#define JSON_CXX_FORMATTER_HPP

#include <json/writter.hpp>
#include <json/value.hpp>

#include <functional>
#include <cstdint>
#include <memory>

namespace json {

/*!
 * @brief Abstract class used as JSON serialization formatter
 * */
class Formatter {
public:
    Formatter(WritterPtr writter = nullptr);

    void set_writter(WritterPtr writter) {
        m_writter = std::move(writter);
    }

    WritterPtr& get_writter() {
        return m_writter;
    }

    const WritterPtr& get_writter() const {
        return m_writter;
    }

    /*!
     * @brief Format given JSON value
     *
     * @param[in]   value   JSON value
     * */
    virtual void formatting(const Value& value) = 0;

    /*! Destructor */
    virtual ~Formatter();
protected:
    WritterPtr m_writter;
};

using FormatterPtr = std::unique_ptr<Formatter>;

template<typename T>
FormatterPtr make_formatter() {
    return FormatterPtr(static_cast<Formatter*>(new T()));
}

template<typename T>
FormatterPtr make_formatter(WritterPtr writter) {
    return FormatterPtr(static_cast<Formatter*>(new T(writter)));
}

}

#endif /* JSON_CXX_FORMATTER_HPP */
