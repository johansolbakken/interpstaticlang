#pragma once

#include <string>

namespace islc
{
    enum class Opcode
    {
        PrintLn,
    };

    std::string toString(Opcode opcode);

    struct CFGInstruction
    {
        Opcode opcode;
        std::vector<uint32_t> operands;
    };
}