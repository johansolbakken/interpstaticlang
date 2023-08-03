#pragma once

namespace islc
{
    enum class Opcode
    {
        PrintLn,
    };

    struct CFGInstruction
    {
        Opcode opcode;
        std::vector<uint32_t> operands;
    };
}