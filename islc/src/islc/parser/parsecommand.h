#pragma once

#include "islc/parser/node.h"

#include "islc/ir/stringlist.h"

namespace islc
{
    class ParseCommand
    {
    public:
        static void begin();
        static void end();

        static void parse();
        static StringList generateStringList();
        static std::shared_ptr<Node> root();
    };
}