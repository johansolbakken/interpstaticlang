#include "application.h"

#include "islc/parser/nodestore.h"

#include <iostream>

extern int yyparse();

int yyerror(const char *s)
{
    std::cout << s << std::endl;
    return 0;
}

islc::NodeStore *nodeStore = nullptr;

namespace islc
{
    void Application::run()
    {
        nodeStore = new NodeStore();
        yyparse();
        delete nodeStore;
        nodeStore = nullptr;
    }
}