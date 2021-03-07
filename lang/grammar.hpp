//
// Created by Mateusz Goslinowski on 06/03/2021.
//

#ifndef ZCPP_GRAMMAR_HPP
#define ZCPP_GRAMMAR_HPP

#include <tao/pegtl.hpp>

namespace pegtl = TAO_PEGTL_NAMESPACE;

namespace grammar
{
    using namespace pegtl;

    // Basics
    struct integer : seq<plus<digit>> {};
    struct variable : plus<lower> {};
    struct wildcard : one<'_'> {};

    struct ws : plus<space> {}; //whitespace
    struct os : star<space> {}; //optional space

    // Keywords
    struct true_ : string<'T','r','u','e'> {};
    struct false_ : string<'F','a','l','s','e'> {};
    struct boolean : sor<true_, false_> {};
    struct let : string<'L','e','t'> {};
    struct in : string<'I','n'> {};
    struct if_ : string<'I','f'> {};
    struct then : string<'T','h','e','n'> {};
    struct else_ : string<'E','l','s','e'> {};

    // expressions and their precedence
    struct expr;
    struct expr1;
    struct expr2;
    struct expr3;
    struct expr4;
    struct expr5;
    struct expr6;
    struct expr7;

    //    let x = 5 in ...
    // or let { x = 5; y = x; ... } in ...
    struct letclause : seq<variable, pad<one<'='>, space>, expr> {};
    struct letclauses : list<letclause, one<';'>, space> {};
    struct letdef : seq<
            let,
            ws,
            sor<
                letclause,
                seq<one<'{'>, os, letclauses, os, one<'}'>>
            >,
            os, in, ws, expr> {};

    // \x. -> 2*x
    struct body;
    struct lambda : seq<one<'\\'>, variable, one<'.'>, os, body> {};

    // if x then y else z
    struct ifthenelse : seq<if_, ws, expr, ws, then, ws, expr, ws, else_, ws, expr> {};

    struct bracketed : seq<one<'('>, os, expr, os, one<')'>> {};

    // precedence
    struct expr : sor<letdef, ifthenelse, lambda, expr1> {};
    struct body : expr {};

    struct appd : seq<expr2, os, one<'$'>, os, expr1> {};
    struct or_ : seq<expr2, os, one<'|'>, os, expr2> {};

    struct expr1 : sor<appd, or_, expr2> {};

    struct eq : seq<expr3, os, string<'=','='>, os, expr3> {};
    struct neq : seq<expr4, os, string<'/','='>, os, expr3> {};
    struct not_ : seq<one<'!'>, os, expr3> {};
    struct and_ : seq<expr3, os, one<'&'>, os, expr3> {};
    struct le : seq<expr3, os, one<'<'>, os, expr3> {};
    struct ge : seq<expr3, os, one<'>'>, os, expr3> {};
    struct gt : seq<expr3, os, string<'>','='>, os, expr3> {};
    struct lt : seq<expr3, os, string<'<','='>, os, expr3> {};

    struct expr2 : sor<eq, neq, not_, and_, le, ge, gt, lt, expr3> {};

    struct plus : seq<expr4, os, one<'+'>, os, expr3> {};
    struct minus : seq<expr4, os, one<'-'>, os, expr3> {};

    struct expr3 : sor<plus, minus, expr4> {};

    struct prod : seq<expr5, os, one<'*'>, os, expr4> {};
    struct div : seq<expr5, os, one<'/'>, os, expr4> {};

    struct expr4 : sor<prod, div, expr5> {};

    struct pow : seq<expr6, os, one<'^'>, os, expr5> {};
    struct compose : seq<expr6, os, one<'.'>, os, expr5> {};

    struct expr5 : sor<pow, compose, expr6> {};

    struct neg : seq<one<'-'>, expr7> {};
    struct app : seq<expr7, ws, expr6> {};

    struct expr6 : sor<neg, app, expr7> {};
    struct expr7 : sor<boolean, integer, variable, wildcard, bracketed> {};

    struct fundef : seq<variable, os, string<':','='>, os, body> {};
    struct fundefs : list<fundef, eol> {};
    struct grammar : must<fundefs> {};

    // selectors
    template< typename Rule > struct selector : std::false_type {};
    template<> struct selector< appd > : std::true_type {};
    template<> struct selector< or_ > : std::true_type {};

    template<> struct selector< eq > : std::true_type {};
    template<> struct selector< neq > : std::true_type {};
    template<> struct selector< not_ > : std::true_type {};
    template<> struct selector< and_ > : std::true_type {};
    template<> struct selector< le > : std::true_type {};
    template<> struct selector< ge > : std::true_type {};
    template<> struct selector< gt > : std::true_type {};
    template<> struct selector< lt > : std::true_type {};

    template<> struct selector< plus > : std::true_type {};
    template<> struct selector< minus > : std::true_type {};
    template<> struct selector< prod > : std::true_type {};
    template<> struct selector< div > : std::true_type {};

    template<> struct selector< pow > : std::true_type {};
    template<> struct selector< compose > : std::true_type {};
    template<> struct selector< neg > : std::true_type {};
    template<> struct selector< app > : std::true_type {};

    template<> struct selector< lambda > : std::true_type {};
    template<> struct selector< body > : std::true_type {};
    template<> struct selector< ifthenelse > : std::true_type {};
    template<> struct selector< letdef > : std::true_type {};
    template<> struct selector< letclause > : std::true_type {};
    template<> struct selector< letclauses > : std::true_type {};
    template<> struct selector< integer > : std::true_type {};
    template<> struct selector< variable > : std::true_type {};
    template<> struct selector< boolean > : std::true_type {};
    template<> struct selector< fundef > : std::true_type {};
    template<> struct selector< fundefs > : std::true_type {};

}

#endif //ZCPP_GRAMMAR_HPP
