#pragma once

#include "islc/parser/node.h"

#include "islc/ir/cfgbasicblock.h"
#include "islc/ir/stringlist.h"

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

        void setStringList(const StringList &stringList) { m_stringList = stringList; }
        const StringList &stringList() const { return m_stringList; }

    private:
        void build();
        uint32_t buildRecursive(const std::shared_ptr<Node> &node, uint32_t parentId);

    private:
        std::shared_ptr<Node> m_root;
        StringList m_stringList;

        std::vector<CFGBasicBlock> m_basicBlocks;
        uint32_t m_nextBasicBlockId = 0;
    };
} // namespace islc