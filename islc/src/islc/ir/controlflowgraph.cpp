#include "controlflowgraph.h"

#include <string>

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

        uint32_t id = buildRecursive(m_root, rootBlock.id);

        CFGBasicBlock endBlock;
        endBlock.id = m_nextBasicBlockId++;
        endBlock.type = BlockType::Exit;
        endBlock.predecessors.push_back(id);
        m_basicBlocks.push_back(endBlock);
    }

    uint32_t ControlFlowGraph::buildRecursive(const std::shared_ptr<Node> &node, uint32_t parentId)
    {
        if (node->type == NodeType::PrintLnStatement)
        {
            CFGBasicBlock block;
            block.id = m_nextBasicBlockId++;
            block.predecessors.push_back(parentId);
            uint32_t stringId = std::stoi(node->children[0]->value);
            block.instructions.push_back(CFGInstruction{Opcode::PrintLn, {stringId}});
            m_basicBlocks.push_back(block);
            return block.id;
        }
        uint32_t id = parentId;
        for (const auto &child : node->children)
        {
            id = buildRecursive(child, id);
        }
        return id;
    }
} // namespace islc
