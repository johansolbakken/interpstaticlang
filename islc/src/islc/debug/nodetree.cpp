#include "nodetree.h"

#include "islc/core/base.h"

namespace islc
{
    void NodeTree::printAst(const std::shared_ptr<Node> &node, int depth)
    {
        for (int i = 0; i < depth; ++i) {
            fmt::print("  ");
        }

        fmt::print("{}\n", node->toString());

        for (auto &child : node->children) {
            printAst(child, depth + 1);
        }
    }
}