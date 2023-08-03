#pragma once

#include "islc/ir/controlflowgraph.h"

namespace islc
{

    class Generator
    {
    public:
        Generator(const ControlFlowGraph &cfg, const std::string &filepath);
        ~Generator() = default;

        void generate();

    private:
        void generateBasicBlock(const CFGBasicBlock &basicBlock, std::stringstream &stream) const;
        void generateInstruction(const CFGInstruction &instruction, std::stringstream &stream) const;

    private:
        const ControlFlowGraph &m_cfg;
        const std::string &m_filepath;
    };

}
