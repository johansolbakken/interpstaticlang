#include "application.h"

#include "islc/core/base.h"

#include "islc/parser/parsecommand.h"

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
        ParseCommand::end();

        if (ast == nullptr)
        {
            error("No AST generated");
            return;
        }
    }

    void Application::error(const std::string &message) const
    {
        fmt::print(fmt::fg(fmt::color::red), "{}\n", message);
    }
}