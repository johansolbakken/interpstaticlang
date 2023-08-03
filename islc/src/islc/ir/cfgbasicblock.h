#pragma once

#include <vector>

#include "islc/ir/cfginstruction.h"

namespace islc
{
    enum class BlockType
    {
        Entry,
        Exit,
        Basic,
    };

    struct CFGBasicBlock
    {
        uint32_t id = 0;
        BlockType type = BlockType::Basic;
        std::vector<uint32_t> successors;
        std::vector<CFGInstruction> instructions;
    };
}