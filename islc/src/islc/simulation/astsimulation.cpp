#include "astsimulation.h"

#include "islc/core/application.h"

namespace islc
{

    std::shared_ptr<AstSimulation::Scope> AstSimulation::Scope::create(const std::shared_ptr<Scope> &parent)
    {
        auto scope = std::make_shared<Scope>();
        scope->parent = parent;
        return scope;
    }

    bool AstSimulation::Scope::set(const std::string &name, const std::string& value)
    {
        if (variables.find(name) != variables.end())
        {
            variables[name] = value;
            return true;
        }
        if (parent)
        {
            return parent->set(name, value);
        }
        return false;
    }

    std::string AstSimulation::Scope::get(const std::string &name)
    {
        if (variables.find(name) != variables.end())
        {
            return variables[name];
        }
        if (parent)
        {
            return parent->get(name);
        }
        return "";
    }

    AstSimulation::AstSimulation(const std::shared_ptr<Node> &root)
        : m_root(root)
    {
    }

    void AstSimulation::run()
    {
        m_globalScope = Scope::create();
        m_currentScope = m_globalScope;
        findFunctions(m_root);
        if (m_functions.find("main") == m_functions.end())
        {
            Application::get().error("No main function found");
            return;
        }
        evaluate(m_functions["main"]);
    }

    void AstSimulation::findFunctions(const std::shared_ptr<Node> &node)
    {
        if (node->type == NodeType::FunctionDeclaration)
        {
            m_functions[node->children[0]->value] = node;
        }

        for (auto &child : node->children)
        {
            findFunctions(child);
        }
    }

    void AstSimulation::evaluate(const std::shared_ptr<Node> &node)
    {
        if (node->type == NodeType::Block)
        {
            m_currentScope = Scope::create(m_currentScope);
            for (auto &child : node->children)
            {
                evaluate(child);
            }
            m_currentScope = m_currentScope->parent;
        }
        else if (node->type == NodeType::PrintLnStatement)
        {
            fmt::print("{}\n", node->children[0]->value.substr(1, node->children[0]->value.size() - 2));
        }
        else if (node->type == NodeType::FunctionCall)
        {
            if (m_functions.find(node->children[0]->value) == m_functions.end())
            {
                Application::get().error("Function " + node->children[0]->value + " not found");
                return;
            }

            evaluate(m_functions[node->children[0]->value]);
        }
        else if (node->type == NodeType::ForRangeStatement)
        {
            auto variable = node->children[0]->valueAsString();
            auto range = node->children[1];
            auto start = range->children[0]->valueAsInt();
            auto end = range->children[1]->valueAsInt();

            for (int i = start; i < end; ++i)
            {
                evaluate(node->children[2]);
            }
        }
        else
        {
            for (auto &child : node->children)
            {
                evaluate(child);
            }
        }
    }
}