//
// Created by Mateusz Goslinowski on 29/03/2021.
//

#include "expression.hpp"

namespace ast
{
    pegtl::parse_tree::node &expression::parse_node() {
        return *node;
    }

    std::ostream &expression::operator<<(std::ostream &out) {
        return (out << parse_node().string_view());
    }
}