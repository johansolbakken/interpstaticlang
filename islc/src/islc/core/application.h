#pragma once

#include <string>

namespace islc{
    class Application {
    public: 
        Application();
        void run();

        void error(const std::string &message) const;

        static Application &get() { return *s_instance; }
    
    private:
        static Application *s_instance;
    };
}