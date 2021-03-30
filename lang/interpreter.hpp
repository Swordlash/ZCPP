//
// Created by Mateusz Goslinowski on 10/03/2021.
//

#ifndef ZCPP_INTERPRETER_HPP
#define ZCPP_INTERPRETER_HPP

#include <tao/pegtl/contrib/parse_tree.hpp>
#include "utils/format.hpp"

namespace pegtl = TAO_PEGTL_NAMESPACE;

namespace interpreter
{
    class context {};

    class interpreter_error : public std::exception
    {
    private:
        std::string message;
    public:

        interpreter_error(const char* msg, std::unique_ptr<pegtl::parse_tree::node>& node)
        : message (format("Error (in line %d, column %d): %s", node->begin().line, node->begin().column, msg)) {};

        const char *what() const noexcept override {
            return message.c_str();
        }
    };
}

#endif //ZCPP_INTERPRETER_HPP
