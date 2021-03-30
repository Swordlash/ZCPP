//
// Created by Mateusz Goslinowski on 29/03/2021.
//

#include <iostream>
#include "integer.hpp"

std::ostream &value::integer::operator<<(std::ostream &out) {
    return (out << this->value);
}
