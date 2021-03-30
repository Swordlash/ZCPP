//
// Created by Mateusz Goslinowski on 29/03/2021.
//

#include "integer.hpp"
#include "../values/integer.hpp"

std::shared_ptr<value::value> ast::integer::interpret(interpreter::context &) {
    return std::make_shared<value::integer>(parse_node().string_view());
}

typecheck::type ast::integer::typecheck(typecheck::context &) {
    return typecheck::type();
}

