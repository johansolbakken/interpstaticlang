#include "cfginstruction.h"

#include <unordered_map>

namespace islc
{
    static std::unordered_map<Opcode, std::string> opcodes = {
        {Opcode::PrintLn, "PrintLn"},
    };

    std::string toString(Opcode opcode)
    {
        if (opcodes.find(opcode) == opcodes.end())
        {
            return "Unknown";
        }
        return opcodes[opcode];
    }
}