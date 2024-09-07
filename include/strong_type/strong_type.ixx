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

module;

#if !defined(STRONG_TYPE_IMPORT_STD_LIBRARY)
    #include <format>
    #include <functional>
    #include <initializer_list>
    #include <istream>
    #include <limits>
    #include <ranges>
    #include <type_traits>
    #include <utility>
#endif

#include <version>

#define STRONG_TYPE_MODULE
#define STRONG_TYPE_MODULE_EXPORT export

export module strong_type;

#if defined(STRONG_TYPE_IMPORT_STD_LIBRARY)
   import std;
#endif

export std::string sanity_test( )
{
    return "Hello world";
}

#include "affine_point.hpp"
#include "arithmetic.hpp"
#include "bicrementable.hpp"
#include "bitarithmetic.hpp"
#include "boolean.hpp"
#include "convertible_to.hpp"
#include "decrementable.hpp"
#include "difference.hpp"
#include "equality.hpp"
#include "equality_with.hpp"
#include "formattable.hpp"
#include "hashable.hpp"
#include "implicitly_convertible_to.hpp"
#include "incrementable.hpp"
#include "indexed.hpp"
#include "invocable.hpp"
#include "iostreamable.hpp"
#include "istreamable.hpp"
#include "iterator.hpp"
#include "ordered.hpp"
#include "ordered_with.hpp"
#include "ostreamable.hpp"
#include "pointer.hpp"
#include "range.hpp"
#include "regular.hpp"
#include "scalable_with.hpp"
#include "semiregular.hpp"
#include "strong_ordering.hpp"
#include "type.hpp"
#include "unique.hpp"
