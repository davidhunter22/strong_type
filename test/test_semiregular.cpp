/*
 * strong_type C++14/17/20 strong typedef library
 *
 * Copyright (C) Björn Fahller
 *
 *  Use, modification and distribution is subject to the
 *  Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 *
 * Project home: https://github.com/rollbear/strong_type
 */

#include "catch2.hpp"

#if defined(STRONG_TYPE_IMPORT_MODULE)
import strong_type;
#else
#include <strong_type/semiregular.hpp>
#endif

#if !defined(STRONG_TYPE_IMPORT_STD_LIBRARY)
#include <memory>
#endif

namespace {
using type = strong::type<int, struct type_, strong::semiregular>;
}
TEST_CASE("a semiregular type can be default constructed")
{
    type v;
    REQUIRE(value_of(v) == 0);
}

TEST_CASE("a semiregular type can be value initialized")
{
    type v{3};
    REQUIRE(value_of(v) == 3);
}

TEST_CASE("a semiregular type can be copy constructed")
{
    type v1{2};
    type t2(v1);

    REQUIRE(value_of(t2) == 2);
}

TEST_CASE("a semiregular type can be move constructed")
{
    using t = strong::type<std::shared_ptr<int>, struct tag_, strong::semiregular>;
    t v1{std::make_shared<int>(3)};
    t v2(std::move(v1));
    REQUIRE(value_of(v1).use_count() == 0);
    REQUIRE(value_of(v2).use_count() == 1);
    REQUIRE(*value_of(v2) == 3);
}

TEST_CASE("a semiregular type can me copy assigned")
{
    using t = strong::type<std::shared_ptr<int>, struct tag_, strong::semiregular>;
    t v1{nullptr};
    t v2(std::make_shared<int>(3));
    v1 = v2;
    REQUIRE(value_of(v1).get() == value_of(v2).get());
    REQUIRE(*value_of(v1) == 3);
}

TEST_CASE("a semiregular type can be move assigned")
{
    using t = strong::type<std::shared_ptr<int>, struct tag_, strong::semiregular>;
    t v1{nullptr};
    t v2(std::make_shared<int>(3));
    v1 = std::move(v2);
    REQUIRE(value_of(v1).use_count() == 1);
    REQUIRE(value_of(v2).use_count() == 0);
    REQUIRE(*value_of(v1) == 3);
}
