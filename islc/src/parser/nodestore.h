#pragma once

#include "parser/node.h"

namespace islc
{
    using NodeIndex = int;

    class NodeStore
    {
    public:
        NodeStore();
        ~NodeStore();

        NodeIndex addNode(NodeType type, const std::string &value, const std::vector<NodeIndex> &children);
        void setRoot(NodeIndex index);
        std::shared_ptr<Node> getRoot() const;

        const auto& nodes() const { return m_nodes; }

    private:
        std::vector<std::shared_ptr<Node>> m_nodes;
        NodeIndex m_root = 0;
    };
}