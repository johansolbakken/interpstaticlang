#include "token.h"

namespace islc
{
    std::string toString(TokenType type)
    {
        switch (type)
        {
        case TokenType::Func:
            return "Func";
        case TokenType::Identifier:
            return "Identifier";
        case TokenType::OpenParen:
            return "OpenParen";
        case TokenType::CloseParen:
            return "CloseParen";
        case TokenType::OpenBrace:
            return "OpenBrace";
        case TokenType::CloseBrace:
            return "CloseBrace";
        case TokenType::StringLiteral:
            return "StringLiteral";
        case TokenType::PrintLn:
            return "PrintLn";
        default:
            return "Unknown";
        }
    }

    std::string Token::toString() const
    {
        return "Token(" + ::islc::toString(type) + ", " + value + ")";
    }
}