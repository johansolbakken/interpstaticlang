#include "application.h"

#include "islc/core/base.h"

#include "islc/parser/parsecommand.h"

#include "islc/debug/nodegraphwiz.h"
#include "islc/debug/nodetree.h"
#include "islc/debug/cfggraphwiz.h"

#include "islc/simulation/astsimulation.h"

#include "islc/ir/controlflowgraph.h"

namespace islc
{
    Application *Application::s_instance = nullptr;

    Application::Application()
    {
        s_instance = this;
    }

    void Application::run()
    {
        ParseCommand::begin();
        ParseCommand::parse();
        auto ast = ParseCommand::root();
        ParseCommand::end();

        NodeGraphwiz::printAst(ast, "ast.png");
        // NodeTree::printAst(ast);

        // AstSimulation simulation(ast);
        // simulation.run();

        ControlFlowGraph cfg(ast);
        CFGGraphwiz::printCfg(cfg, "cfg.png");
        for (const auto &block : cfg.basicBlocks())
        {
            fmt::print("Block {}:\n", block.id);
            for (const auto &successor : block.successors)
            {
                fmt::print("    {}\n", successor);
            }
        }
    }

    void Application::error(const std::string &message) const
    {
        fmt::print(fmt::fg(fmt::color::red), "{}\n", message);
    }
}