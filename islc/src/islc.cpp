#include <iostream>

#include "parser/nodestore.h"

extern int yyparse();

int yyerror(const char *s)
{
    std::cout << s << std::endl;
    return 0;
}

islc::NodeStore *nodeStore = nullptr;

int main(int argc, char **argv)
{
    nodeStore = new islc::NodeStore();
    yyparse();
    delete nodeStore;
    return 0;
}