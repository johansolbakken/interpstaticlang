#include "cfggraphwiz.h"

#include <fstream>
#include <sstream>

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

            dotStream << "    " << block.id << " [shape=box, style=filled, fillcolor=" << color << ", label=\"" << block.id << "\"];\n";
        }

        for (const auto &block : cfg.basicBlocks())
        {
            for (const auto &successor : block.successors)
            {
                dotStream << "    " << block.id << " -> " << successor << ";\n";
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