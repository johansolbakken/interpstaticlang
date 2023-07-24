cmake_minimum_required(VERSION 3.10)

project(islc)

set(CMAKE_CXX_STANDARD 23)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(parser src/islc/parser/parser.ypp ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(lexer src/islc/lexer/lexer.lpp ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(lexer parser)

add_executable(islc src/islc.cpp

    src/islc/core/application.h src/islc/core/application.cpp

    src/islc/parser/node.h src/islc/parser/node.cpp
    src/islc/parser/nodestore.h src/islc/parser/nodestore.cpp

    ${BISON_parser_OUTPUTS} 
    ${FLEX_lexer_OUTPUTS}
)
target_include_directories(islc PRIVATE src)
include_directories(${CMAKE_CURRENT_BINARY_DIR})