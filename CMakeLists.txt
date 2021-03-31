cmake_minimum_required(VERSION 3.17)
project(ZCPP)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

enable_testing()

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets taocpp::pegtl GMP::gmp GMP::gmpxx)

add_executable(test_grammar lang/analyze.cpp lang/exception.hpp)
add_executable(${PROJECT_NAME} main.cpp lang/grammar.hpp lang/expressions/expression.hpp lang/values/value.hpp lang/typecheck.hpp lang/interpreter.hpp lang/expressions/integer.hpp lang/expressions/expression.cpp lang/values/integer.hpp lang/values/integer.cpp lang/expressions/integer.cpp lang/utils/format.hpp lang/utils/format.cpp lang/expressions/parse_ast.hpp lang/expressions/parse_ast.cpp lang/expressions/fundefs.hpp lang/expressions/fundef.hpp lang/expressions/parse_error.hpp lang/expressions/fundefs.cpp lang/expressions/fundef.cpp)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(pegtl)
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

find_package (GMP REQUIRED)

include_directories(${GMPXX_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
target_link_libraries(test_grammar taocpp::pegtl)

add_test(test_grammar test_grammar "" test_grammar)