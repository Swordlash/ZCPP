//
// Created by Mateusz Goslinowski on 29/03/2021.
//

#ifndef ZCPP_FORMAT_HPP
#define ZCPP_FORMAT_HPP

#include <string>
#include <memory>
#include <stdexcept>

// workaround for std::format not being supported by any compiler right now :(
// source: https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf/8098080

template<typename ... Args>
std::string format( const std::string&& format, Args ... args )
{
    int size_s = snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
    if( size_s <= 0 ){ throw std::runtime_error( "Error during formatting." ); }
    auto size = static_cast<size_t>( size_s );
    auto buf = std::make_unique<char[]>( size );
    snprintf( buf.get(), size, format.c_str(), args ... );
    return std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
}

#endif //ZCPP_FORMAT_HPP
