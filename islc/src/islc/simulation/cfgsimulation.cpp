#include "cfgsimulation.h"

namespace islc
{
    CfgSimulation::CfgSimulation(const ControlFlowGraph &root)
        : m_cfg(root)
    {
    }

    void CfgSimulation::run()
    {
        int m_currentBlock = 0;
        while (m_currentBlock < m_cfg.numberOfBlocks())
        {
            const auto &block = m_cfg.basicBlocks()[m_currentBlock];
            for (const auto &instruction : block.instructions)
            {
                switch (instruction.opcode)
                {
                case Opcode::PrintLn:
                    fmt::print("{}\n", m_cfg.stringList()[instruction.operands[0]]);
                    break;
                default:
                    fmt::print(fmt::fg(fmt::color::yellow), "Warning: Unknown opcode in CfgSimulation::run\n");
                    break;
                }
            }
            ++m_currentBlock;
        }
    }
}