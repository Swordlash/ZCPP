//
// Created by Mateusz Goslinowski on 08/03/2021.
//

#ifndef ZCPP_EXPRESSION_HPP
#define ZCPP_EXPRESSION_HPP

#include <iostream>
#include <tao/pegtl/contrib/parse_tree.hpp>

#include "../interpreter.hpp"
#include "../typecheck.hpp"
#include "../values/value.hpp"

namespace pegtl = TAO_PEGTL_NAMESPACE;

namespace ast
{
    class expression
    {
    private:
        std::unique_ptr<pegtl::parse_tree::node> node;
    public:
        explicit expression(std::unique_ptr<pegtl::parse_tree::node>&& node) : node(std::move(node)) {}

        virtual std::shared_ptr<value::value> interpret(interpreter::context&) = 0;
        virtual typecheck::type typecheck(typecheck::context&) = 0;
        virtual std::ostream& operator<<(std::ostream&);

        pegtl::parse_tree::node& parse_node();
    };

}

#endif //ZCPP_EXPRESSION_HPP
