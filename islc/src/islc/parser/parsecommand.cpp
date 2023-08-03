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
        yyparse();
    }

    std::shared_ptr<Node> ParseCommand::root()
    {
        return nodeStore->getRoot();
    }

    void recursiveExtractStrings(StringList &list, const std::shared_ptr<Node> &node)
    {
        if (node->type == NodeType::StringData)
        {
            uint32_t id = list.add(node->valueAsString());
            node->value = std::to_string(id);
        }
        else
        {
            for (const auto &child : node->children)
            {
                recursiveExtractStrings(list, child);
            }
        }
    }

    StringList ParseCommand::generateStringList()
    {
        StringList stringList;
        recursiveExtractStrings(stringList, nodeStore->getRoot());
        return stringList;
    }
}