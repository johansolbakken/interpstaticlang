#include "core/application.h"

int main(int argc, char **argv)
{
    auto* app = new islc::Application();
    app->run();
    delete app;

    return 0;
}