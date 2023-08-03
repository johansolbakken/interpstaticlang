#pragma once

#include <vector>

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
    };
}