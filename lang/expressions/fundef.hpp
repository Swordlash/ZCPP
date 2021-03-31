//
// Created by Mateusz Goslinowski on 31/03/2021.
//

#ifndef ZCPP_FUNDEF_HPP
#define ZCPP_FUNDEF_HPP

#include <tao/pegtl/contrib/parse_tree.hpp>

#include "expression.hpp"
#include "../interpreter.hpp"
#include "../typecheck.hpp"

namespace pegtl = TAO_PEGTL_NAMESPACE;

namespace ast
{
    class fundef : public expression
    {
    public:
        explicit fundef(std::unique_ptr<pegtl::parse_tree::node> &&node) : expression(std::move(node)) {}

        std::shared_ptr<value::value> interpret(interpreter::context &context) override;
        typecheck::type typecheck(typecheck::context &context) override;
    };
}

#endif //ZCPP_FUNDEF_HPP
