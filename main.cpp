#include <array>
#include <iomanip>
#include <iostream>

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <tao/pegtl/contrib/parse_tree_to_dot.hpp>

#include "lang/grammar.hpp"

using namespace TAO_PEGTL_NAMESPACE;

int main(int argc, char *argv[]) {

    argv_input in( argv, 1 );
    try
    {
        if( const auto root = parse_tree::parse< grammar::grammar, grammar::selector >( in ) ) {
            parse_tree::print_dot( std::cout, *root);
            return 0;
        }
    }
    catch( const pegtl::parse_error& e ) {

        // This catch block needs access to the input
        const auto p = e.positions().front();
        std::cerr << e.what() << '\n'
                  << in.line_at( p ) << '\n'
                  << std::setw( p.column ) << '^' << std::endl;
    }

    return 1;
}
