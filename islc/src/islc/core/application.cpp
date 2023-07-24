#include "application.h"

#include "islc/parser/nodestore.h"

#include <iostream>

extern int yyparse();

islc::NodeStore *nodeStore = nullptr;

namespace islc
{
    Application *Application::s_instance = nullptr;

    Application::Application()
    {
        s_instance = this;
    }

    void Application::run()
    {
        nodeStore = new NodeStore();
        yyparse();
        delete nodeStore;
        nodeStore = nullptr;
    }

    void Application::error(const std::string &message) const
    {
        std::cout << message << std::endl;
    }
}