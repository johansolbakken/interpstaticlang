#pragma once

#include "islc/ir/controlflowgraph.h"

namespace islc
{
    class CFGGraphwiz
    {
    public:
        static void printCfg(const ControlFlowGraph &cfg, const std::string &filepath = "cfg.png");
    };
}