//
// Created by Mateusz Goslinowski on 08/03/2021.
//

#ifndef ZCPP_TYPECHECK_HPP
#define ZCPP_TYPECHECK_HPP

#include <utility>
#include <variant>
#include <memory>
#include <exception>
#include <iostream>

#include <tao/pegtl.hpp>

namespace pegtl = TAO_PEGTL_NAMESPACE;

namespace typecheck
{
    using pegtl::position;

    class context {};
    class type {};
}

#endif //ZCPP_TYPECHECK_HPP
