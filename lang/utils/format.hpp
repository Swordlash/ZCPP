//
// Created by Mateusz Goslinowski on 29/03/2021.
//

#ifndef ZCPP_FORMAT_HPP
#define ZCPP_FORMAT_HPP

#include <string>

template<typename ... Args>
std::string format( const std::string_view& format, Args ... args );

#endif //ZCPP_FORMAT_HPP
