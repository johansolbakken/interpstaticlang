cmake_minimum_required(VERSION 3.10)

project(islc)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(vendor)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(parser src/islc/parser/parser.ypp ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(lexer src/islc/lexer/lexer.lpp ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(lexer parser)

add_executable(islc src/islc.cpp

    src/islc/core/application.h src/islc/core/application.cpp

    src/islc/parser/node.h src/islc/parser/node.cpp
    src/islc/parser/nodestore.h src/islc/parser/nodestore.cpp
    src/islc/parser/bisoncontext.cpp
    src/islc/parser/parsecommand.h src/islc/parser/parsecommand.cpp

    src/islc/debug/nodegraphwiz.h src/islc/debug/nodegraphwiz.cpp
    src/islc/debug/nodetree.h src/islc/debug/nodetree.cpp
    src/islc/debug/cfggraphwiz.h src/islc/debug/cfggraphwiz.cpp
    src/islc/debug/stringlisttext.h src/islc/debug/stringlisttext.cpp

    src/islc/simulation/astsimulation.h src/islc/simulation/astsimulation.cpp
    src/islc/simulation/cfgsimulation.h src/islc/simulation/cfgsimulation.cpp

    src/islc/ir/controlflowgraph.h src/islc/ir/controlflowgraph.cpp
    src/islc/ir/cfgbasicblock.h
    src/islc/ir/stringlist.h src/islc/ir/stringlist.cpp
    src/islc/ir/cfginstruction.h src/islc/ir/cfginstruction.cpp

    src/islc/generator/generator.h src/islc/generator/generator.cpp

    ${BISON_parser_OUTPUTS} 
    ${FLEX_lexer_OUTPUTS}
)
target_include_directories(islc PRIVATE src vendor/fmt/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(islc PRIVATE fmt::fmt)