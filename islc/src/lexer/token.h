#pragma once

#include <string>

namespace islc
{
    enum class TokenType
    {
        Eof,
        Func,
        Identifier,
        OpenParen,
        CloseParen,
        OpenBrace,
        CloseBrace,
        StringLiteral,
        PrintLn,
    };

    std::string toString(TokenType type);

    struct Token
    {
        TokenType type;
        std::string value;
        uint32_t line;

        std::string toString() const;
    };
}