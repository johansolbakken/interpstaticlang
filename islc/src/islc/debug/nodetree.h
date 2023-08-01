#pragma once

#include <memory>

#include "islc/parser/node.h"

namespace islc
{
    class NodeTree
    {
    public:
        static void printAst(const std::shared_ptr<Node> &node, int depth = 0);
    };
}