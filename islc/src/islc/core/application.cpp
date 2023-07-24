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
        ParseCommand::parse();
    }

    void Application::error(const std::string &message) const
    {
        fmt::print(fmt::fg(fmt::color::red), "{}\n", message);
    }
}