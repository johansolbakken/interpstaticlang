#include "nodegraphwiz.h"

#include "islc/core/base.h"

#include <fstream>
#include <sstream>
#include <functional>

namespace islc
{
    void NodeGraphwiz::printAst(const std::shared_ptr<Node> &node, const std::string &filepath)
    {
        std::string dotFilename = filepath + ".dot";
        std::stringstream ss;
        ss << "digraph G {\n";

        int id = 0;
        auto writeNode = std::function<void(const std::shared_ptr<Node> &, int)>();
        writeNode = [&ss, &writeNode, &id](const std::shared_ptr<Node> &node, int parentId)
        {
            int nodeId = ++id;
            ss << "    " << nodeId << " [label=\"" << toString(node->type) << "\"];\n";
            if (parentId >= 0)
            {
                ss << "    " << parentId << " -> " << nodeId << ";\n";
            }

            if (node->value != "")
            {
                int valueId = ++id;
                auto value = node->value;
                if (value[0] == '"' && value[value.size() - 1] == '"')
                {
                    value = value.substr(1, value.size() - 2);
                }
                ss << "    " << valueId << " [label=\"" << value << "\"];\n";
                ss << "    " << nodeId << " -> " << valueId << ";\n";
            }

            for (auto &child : node->children)
            {
                writeNode(child, nodeId);
            }
        };

        writeNode(node, -1);
        ss << "}\n";

        std::ofstream dotFile(dotFilename);
        dotFile << ss.str();
        dotFile.close();

        std::string command = "dot -Tpng " + dotFilename + " -o " + filepath;
        system(command.c_str());

        std::remove(dotFilename.c_str());
    }
}