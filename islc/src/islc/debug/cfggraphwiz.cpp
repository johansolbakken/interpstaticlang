#include "cfggraphwiz.h"

#include <fstream>
#include <sstream>

#include "islc/core/base.h"

namespace islc
{
    // prints basic blocks as white squares. Entry block is green, exit block is red. Prints edges as black lines with arrowheads. Prints id inside block.
    void CFGGraphwiz::printCfg(const ControlFlowGraph &cfg, const std::string &filepath)
    {
        std::string dotFilename = filepath + ".dot";
        std::stringstream dotStream;
        dotStream << "digraph {\n";

        for (const auto &block : cfg.basicBlocks())
        {
            std::string color = "white";
            if (block.type == BlockType::Entry)
            {
                color = "green";
            }
            else if (block.type == BlockType::Exit)
            {
                color = "red";
            }

            std::stringstream label;
            label << block.id << "\n";
            for (const auto &instruction : block.instructions)
            {
                std::string opcodeString = islc::toString(instruction.opcode);
                if (opcodeString == "Unknown")
                {
                    fmt::print(fmt::fg(fmt::color::yellow), "Warning: Unknown opcode in CFGGraphwiz::printCfg\n");
                }
                label << opcodeString << " ";
                for (const auto &operand : instruction.operands)
                {
                    label << operand << " ";
                }
                label << "\n";
            }
            dotStream << "    " << block.id << " [shape=box, style=filled, fillcolor=" << color << ", label=\"" << label.str() << "\"];\n";
        }

        for (const auto &block : cfg.basicBlocks())
        {
            for (const auto &successor : block.predecessors)
            {
                dotStream << "    " << successor << " -> " << block.id << ";\n";
            }
        }

        dotStream << "}\n";

        std::ofstream dotFile(dotFilename);
        dotFile << dotStream.str();
        dotFile.close();

        std::string command = "dot -Tpng " + dotFilename + " -o " + filepath;
        system(command.c_str());

        std::string rmCommand = "rm " + dotFilename;
        system(rmCommand.c_str());
    }
}