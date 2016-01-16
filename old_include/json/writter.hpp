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
 * @file writter.hpp
 *
 * @brief JSON writter interface
 * */

#ifndef JSON_CXX_WRITTER_HPP
#define JSON_CXX_WRITTER_HPP

#include <cstdint>
#include <string>

namespace json {

/*!
 * @brief Abstract class used as JSON serialization formatter
 * */
class Writter {
public:
    Writter();

    virtual void clear() = 0;

    virtual void write(char ch) = 0;

    virtual void write(std::size_t size, char ch) = 0;

    virtual void write(const char* str) = 0;

    virtual void write(const char* str, std::size_t length) = 0;

    virtual void write(const std::string& str) = 0;

    /*! Destructor */
    virtual ~Writter();
};

}

#endif /* JSON_CXX_WRITTER_HPP */