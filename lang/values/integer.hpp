//
// Created by Mateusz Goslinowski on 29/03/2021.
//

#ifndef ZCPP_VAL_INTEGER_HPP
#define ZCPP_VAL_INTEGER_HPP

#include <iostream>
#include "value.hpp"
#include <gmpxx.h>

namespace value
{
    class integer : public value
    {
    private:
        mpz_class value;

    public:
        explicit integer(std::string_view value_str) : value(value_str.data()) {}

        std::ostream& operator<<(std::ostream&) override;
    };
}

#endif //ZCPP_VAL_INTEGER_HPP
