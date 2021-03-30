//
// Created by Mateusz Goslinowski on 10/03/2021.
//

#ifndef ZCPP_EXPR_INTEGER_HPP
#define ZCPP_EXPR_INTEGER_HPP

#include <iostream>
#include <tao/pegtl/contrib/parse_tree.hpp>

#include "expression.hpp"
#include "../interpreter.hpp"
#include "../typecheck.hpp"

namespace pegtl = TAO_PEGTL_NAMESPACE;

namespace ast
{
    class integer : public expression
    {
        explicit integer(std::unique_ptr<pegtl::parse_tree::node>& node) : expression(node) {}

        virtual typecheck::type typecheck(typecheck::context&) override;
        virtual std::shared_ptr<value::value> interpret(interpreter::context&) override;
    };
}

#endif //ZCPP_EXPR_INTEGER_HPP
