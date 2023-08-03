#pragma once

#include "islc/core/base.h"

#include "islc/ir/controlflowgraph.h"

#include <memory>
#include <map>

namespace islc
{
    class CfgSimulation
    {
    public:
        CfgSimulation(const ControlFlowGraph &root);
        ~CfgSimulation() = default;

        void run();

    private:
        ControlFlowGraph m_cfg;
    };
}