#pragma once

#include "lexer/token.h"

#include <optional>

namespace islc
{
    class Lexer
    {
    public:
        Lexer(const std::string &source);
        ~Lexer();

        std::optional<Token> lex();

    private:
        std::string m_source;
        uint32_t m_index;
        uint32_t m_line;
    };
}