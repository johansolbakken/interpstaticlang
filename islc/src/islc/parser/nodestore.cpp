#include "nodestore.h"

namespace islc
{
    NodeStore::NodeStore()
    {
    }

    NodeStore::~NodeStore()
    {
    }

    NodeIndex NodeStore::addNode(NodeType type, const std::string &value, const std::vector<NodeIndex> &children)
    {
        int index = m_nodes.size();
        std::vector<std::shared_ptr<Node>> childNodes;
        for (auto child : children)
            childNodes.push_back(m_nodes[child]);
        auto node = std::make_shared<Node>(Node(type, value, childNodes));
        m_nodes.push_back(node);
        return index;
    }

    void NodeStore::setRoot(NodeIndex root)
    {
        m_root = root;
    }

    std::shared_ptr<Node> NodeStore::getRoot() const
    {
        return m_nodes[m_root];
    }
}