#include "controlflowgraph.h"

namespace islc
{
    ControlFlowGraph::ControlFlowGraph(const std::shared_ptr<Node> &root)
        : m_root(root)
    {
        build();
    }

    void ControlFlowGraph::build()
    {
        CFGBasicBlock rootBlock;
        rootBlock.id = m_nextBasicBlockId++;
        rootBlock.type = BlockType::Entry;
        m_basicBlocks.push_back(rootBlock);

        buildRecursive(m_root, rootBlock.id);

        CFGBasicBlock endBlock;
        endBlock.id = m_nextBasicBlockId++;
        endBlock.type = BlockType::Exit;

        auto& lastBlock = m_basicBlocks.back();
        lastBlock.successors.push_back(endBlock.id);
        m_basicBlocks.push_back(endBlock);
    }

    void ControlFlowGraph::buildRecursive(const std::shared_ptr<Node> &node, uint32_t parentId)
    {
    }
} // namespace islc
