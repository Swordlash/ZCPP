//
// Created by Mateusz Goslinowski on 08/03/2021.
//

#ifndef ZCPP_VALUE_HPP
#define ZCPP_VALUE_HPP

#include <iostream>

namespace value
{
    class value
    {
    public:
        virtual std::ostream& operator<<(std::ostream&) = 0;
    };

}

#endif //ZCPP_VALUE_HPP
