//
// Created by Mateusz Goslinowski on 31/03/2021.
//

#ifndef ZCPP_FUNDEFS_HPP
#define ZCPP_FUNDEFS_HPP

#include "expression.hpp"
#include <tao/pegtl/contrib/parse_tree.hpp>

#include "expression.hpp"
#include "fundef.hpp"
#include "../interpreter.hpp"
#include "../typecheck.hpp"
#include "parse_error.hpp"

namespace pegtl = TAO_PEGTL_NAMESPACE;

namespace ast
{
    class fundefs : public expression
    {
    private:
        std::vector<std::unique_ptr<fundef>> decls;

    public:
        explicit fundefs(std::unique_ptr<pegtl::parse_tree::node>&& node);

        std::shared_ptr<value::value> interpret(interpreter::context &context) override;
        typecheck::type typecheck(typecheck::context &context) override;
    };
}

#endif //ZCPP_FUNDEFS_HPP
