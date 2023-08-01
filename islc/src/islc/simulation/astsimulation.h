#pragma once

#include "islc/core/base.h"

#include "islc/parser/node.h"

#include <memory>
#include <map>

namespace islc
{
    class AstSimulation
    {
    public:
        AstSimulation(const std::shared_ptr<Node> &root);
        ~AstSimulation() = default;

        void run();

    private:
        void findVariables(const std::shared_ptr<Node> &node);
        void findFunctions(const std::shared_ptr<Node> &node);
        void evaluate(const std::shared_ptr<Node> &node);

    private:
        std::shared_ptr<Node> m_root;
        std::map<std::string, std::shared_ptr<Node>> m_variables;
        std::map<std::string, std::shared_ptr<Node>> m_functions;
    };
}