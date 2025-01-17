/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Microsoft Corporation
 *
 * -=- Robust Distributed System Nucleus (rDSN) -=-
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once

#include <memory>
#include <string>
#include <vector>

#include "runtime/service_app.h"
#include "utils/error_code.h"

namespace dsn {
namespace replication {

class meta_service;

namespace test {
class test_checker;
}
} // namespace replication
} // namespace dsn

namespace dsn {

namespace service {

class meta_service_app : public service_app
{
public:
    static void register_components();
    static void register_all();

    meta_service_app(const service_app_info *info);
    virtual ~meta_service_app();

    virtual ::dsn::error_code start(const std::vector<std::string> &args) override;

    virtual ::dsn::error_code stop(bool cleanup = false) override;

private:
    friend class ::dsn::replication::test::test_checker;
    std::unique_ptr<dsn::replication::meta_service> _service;
};
} // namespace service
} // namespace dsn
