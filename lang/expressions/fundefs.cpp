//
// Created by Mateusz Goslinowski on 31/03/2021.
//

#include <memory>
#include "fundefs.hpp"

std::shared_ptr <value::value> ast::fundefs::interpret(interpreter::context &context) {
    return std::shared_ptr<value::value>();
}

typecheck::type ast::fundefs::typecheck(typecheck::context &context) {
    return typecheck::type();
}

ast::fundefs::fundefs(std::unique_ptr<pegtl::parse_tree::node> &&node) : expression(std::move(node))
{
    if(node->type != "grammar::fundefs")
        throw parse_error(format("Expected fundefs, got %s", node->type.data()), parse_node());
    //TODO parse children
}
