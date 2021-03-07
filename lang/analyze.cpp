//
// Created by Mateusz Goslinowski on 07/03/2021.
//

#include <tao/pegtl/contrib/analyze.hpp>
#include "grammar.hpp"
#include <iostream>

int main()
{
    const std::size_t issues = tao::pegtl::analyze<grammar::grammar>(1);
    std::cout<< issues << " issues found." << std::endl;

    assert (issues == 0);
    return 0;
}
