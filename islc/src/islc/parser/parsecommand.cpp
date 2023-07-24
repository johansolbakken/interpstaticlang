#include "parsecommand.h"

#include "islc/parser/nodestore.h"

extern int yyparse();
extern islc::NodeStore *nodeStore; // defined in bison file

namespace islc
{
    void ParseCommand::begin()
    {
        nodeStore = new NodeStore();
    }

    void ParseCommand::end()
    {
        delete nodeStore;
        nodeStore = nullptr;
    }

    void ParseCommand::parse()
    {
        begin();
        yyparse();
        end();
    }
}