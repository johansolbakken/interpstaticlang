#pragma once

#include <memory>
#include <vector>
#include <string>

namespace islc
{
    enum class NodeType
    {
        Program,
        FunctionDeclaration,
        GlobalList,
        GlobalDeclaration,
        Statement,
        StatementList,
        PrintLnStatement,
        StringData,
        IdentifierData
    };

    struct Node
    {
        NodeType type;
        std::vector<std::shared_ptr<Node>> children;
        std::string value;

        Node(NodeType type, const std::string &value, const std::vector<std::shared_ptr<Node>> &children)
            : type(type), value(value), children(children)
        {
        }

        std::string toString() const;
    };

}