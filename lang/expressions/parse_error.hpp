//
// Created by Mateusz Goslinowski on 31/03/2021.
//

#ifndef ZCPP_PARSE_ERROR_HPP
#define ZCPP_PARSE_ERROR_HPP

#include "../exception.hpp"

namespace ast
{
    class parse_error : public lang_exception
    {
    public:
        parse_error(std::string &&msg, pegtl::parse_tree::node& node)
          : lang_exception(std::forward<std::string&&>(msg), node) {}
    };
}

#endif //ZCPP_PARSE_ERROR_HPP
