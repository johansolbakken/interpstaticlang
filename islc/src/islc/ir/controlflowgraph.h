#pragma once

#include "islc/parser/node.h"

#include "islc/ir/cfgbasicblock.h"

#include <vector>

namespace islc
{
    class ControlFlowGraph
    {
    public:
        ControlFlowGraph(const std::shared_ptr<Node> &root);
        ~ControlFlowGraph() = default;

        uint32_t numberOfBlocks() const { return m_basicBlocks.size(); }

        const std::vector<CFGBasicBlock> &basicBlocks() const { return m_basicBlocks; }

    private:
        void build();
        void buildRecursive(const std::shared_ptr<Node> &node, uint32_t parentId);

    private:
        std::shared_ptr<Node> m_root;

        std::vector<CFGBasicBlock> m_basicBlocks;
        uint32_t m_nextBasicBlockId = 0;
    };
} // namespace islc