#include "node.h"

#include "islc/core/base.h"

#include <unordered_map>

namespace islc
{
    std::string Node::toString() const
    {
        return "Node (" + std::to_string((int)type) + ", " + value + ")";
    }

    static std::unordered_map<NodeType, std::string> nodeTypes = {
        {NodeType::Program, "Program"},
        {NodeType::FunctionDeclaration, "FunctionDeclaration"},
        {NodeType::GlobalList, "GlobalList"},
        {NodeType::GlobalDeclaration, "GlobalDeclaration"},
        {NodeType::Statement, "Statement"},
        {NodeType::StatementList, "StatementList"},
        {NodeType::PrintLnStatement, "PrintLnStatement"},
        {NodeType::StringData, "StringData"},
        {NodeType::IdentifierData, "IdentifierData"},
    };

    std::string toString(NodeType type)
    {
        if (nodeTypes.find(type) != nodeTypes.end())
        {
            return nodeTypes[type];
        }

        fmt::print(fmt::fg(fmt::color::yellow), "Warning: encountered unknown node type ({}) in {}\n", int(type), __FILE__);

        return "Unknown";
    }

}