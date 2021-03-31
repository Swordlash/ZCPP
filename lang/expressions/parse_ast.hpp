//
// Created by Mateusz Goslinowski on 31/03/2021.
//

#ifndef ZCPP_PARSE_AST_HPP
#define ZCPP_PARSE_AST_HPP

#include "expression.hpp"
#include "../utils/format.hpp"
#include <memory>
#include "../exception.hpp"

namespace ast
{
    template <typename ParseInput> std::unique_ptr<expression> parse (ParseInput&&);
}

#endif //ZCPP_PARSE_AST_HPP
