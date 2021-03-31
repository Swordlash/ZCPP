//
// Created by Mateusz Goslinowski on 01/04/2021.
//

#include <memory>
#include "fundef.hpp"

std::shared_ptr<value::value> ast::fundef::interpret(interpreter::context &context) {
    return std::shared_ptr<value::value>();
}

typecheck::type ast::fundef::typecheck(typecheck::context &context) {
    return typecheck::type();
}
