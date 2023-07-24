#pragma once

#include <memory>
#include "islc/parser/node.h"

namespace islc
{
    class ParseCommand
    {
    public:
        static void begin();
        static void end();

        static void parse();
        static std::shared_ptr<Node> root();
    };
}