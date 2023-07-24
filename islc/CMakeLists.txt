cmake_minimum_required(VERSION 3.10)

project(islc)

set(CMAKE_CXX_STANDARD 23)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(parser src/parser/parser.ypp ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(lexer src/lexer/lexer.lpp ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(lexer parser)

add_executable(islc src/islc.cpp

    src/core/application.h src/core/application.cpp

    src/parser/node.h src/parser/node.cpp
    src/parser/nodestore.h src/parser/nodestore.cpp

    ${BISON_parser_OUTPUTS} 
    ${FLEX_lexer_OUTPUTS}
)
target_include_directories(islc PRIVATE src)
include_directories(${CMAKE_CURRENT_BINARY_DIR})