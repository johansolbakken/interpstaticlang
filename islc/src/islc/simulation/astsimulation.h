#pragma once

#include "islc/core/base.h"

#include "islc/parser/node.h"

#include <memory>
#include <map>

namespace islc
{
    class AstSimulation
    {
        struct Scope
        {
            std::map<std::string, std::string> variables;
            std::shared_ptr<Scope> parent;
            static std::shared_ptr<Scope> create(const std::shared_ptr<Scope> &parent = nullptr);
            bool set(const std::string &name, const std::string& value);
            std::string get(const std::string &name);
        };

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
        std::map<std::string, std::shared_ptr<Node>> m_functions;
        std::shared_ptr<Scope> m_globalScope;
        std::shared_ptr<Scope> m_currentScope;
    };
}