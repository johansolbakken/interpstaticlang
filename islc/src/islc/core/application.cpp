#include "application.h"

#include "islc/core/base.h"

#include "islc/parser/parsecommand.h"

#include "islc/debug/nodegraphwiz.h"
#include "islc/debug/nodetree.h"
#include "islc/debug/cfggraphwiz.h"
#include "islc/debug/stringlisttext.h"

#include "islc/simulation/astsimulation.h"
#include "islc/simulation/cfgsimulation.h"

#include "islc/ir/controlflowgraph.h"

#include "islc/generator/generator.h"

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
        auto stringList = ParseCommand::generateStringList();
        ParseCommand::end();

        NodeGraphwiz::printAst(ast, "ast.png");
        // NodeTree::printAst(ast);
        StringListText::printCsv(stringList, "stringlist.csv");

        // AstSimulation simulation(ast);
        // simulation.run();

        ControlFlowGraph cfg(ast);
        cfg.setStringList(stringList);
        CFGGraphwiz::printCfg(cfg, "cfg.png");

        CfgSimulation cfgSimulation(cfg);
        cfgSimulation.run();

        Generator generator(cfg, "main.c");
        generator.generate();

        system("gcc -o program main.c");
    }

    void Application::error(const std::string &message) const
    {
        fmt::print(fmt::fg(fmt::color::red), "{}\n", message);
    }
}