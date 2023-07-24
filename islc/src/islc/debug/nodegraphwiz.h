#pragma once

#include <memory>

#include "islc/parser/node.h"

namespace islc
{
    class NodeGraphwiz
    {
    public:
        static void printAst(const std::shared_ptr<Node> &node, const std::string &filepath = "ast.png");
    };
}