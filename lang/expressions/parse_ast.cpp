//
// Created by Mateusz Goslinowski on 31/03/2021.
//

#include "parse_ast.hpp"
#include "expression.hpp"
#include "fundefs.hpp"
#include <memory>

#include "../grammar.hpp"
#include <tao/pegtl/contrib/parse_tree.hpp>

namespace pegtl = TAO_PEGTL_NAMESPACE;


namespace ast {
    template<typename ParseInput>
    std::unique_ptr<expression> parse(ParseInput &&in) {
        const std::unique_ptr<pegtl::parse_tree::node> root
          = pegtl::parse_tree::parse< grammar::grammar, grammar::selector >( in );
        if(!root) return nullptr;
        assert(root->children.size() == 1);

        return std::make_unique<fundefs>(root->children.front());
    }
}