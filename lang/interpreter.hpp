//
// Created by Mateusz Goslinowski on 10/03/2021.
//

#ifndef ZCPP_INTERPRETER_HPP
#define ZCPP_INTERPRETER_HPP

#include <tao/pegtl/contrib/parse_tree.hpp>
#include "utils/format.hpp"
#include "exception.hpp"

namespace pegtl = TAO_PEGTL_NAMESPACE;

namespace interpreter
{
    class context {};

    class interpreter_error : public lang_exception {};
}

#endif //ZCPP_INTERPRETER_HPP
