//
// Created by Mateusz Goslinowski on 31/03/2021.
//

#ifndef ZCPP_EXCEPTION_HPP
#define ZCPP_EXCEPTION_HPP

#include <string>
#include <memory>
#include <tao/pegtl/contrib/parse_tree.hpp>

namespace pegtl = TAO_PEGTL_NAMESPACE;

class lang_exception : public std::exception
{
private:
    std::string message;
public:

    lang_exception(std::string &&msg, pegtl::parse_tree::node& node)
            : message (format("Error (in line %d, column %d): %s", node.begin().line, node.begin().column, msg.c_str())) {};

    [[nodiscard]] const char *what() const noexcept override {
        return message.c_str();
    }
};

#endif //ZCPP_EXCEPTION_HPP
