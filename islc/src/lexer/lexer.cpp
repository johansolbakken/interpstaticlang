#include "lexer.h"

#include <iostream>
#include <unordered_map>

namespace islc
{
    Lexer::Lexer(const std::string &source)
        : m_source(source), m_index(0), m_line(1)
    {
    }

    Lexer::~Lexer()
    {
    }

    std::unordered_map<std::string, TokenType> keywords = {
        {"func", TokenType::Func},
        {"println", TokenType::PrintLn},
    };

    std::optional<Token> Lexer::lex()
    {
        while (m_index < m_source.size() && std::isspace(m_source[m_index]))
        {
            if (m_source[m_index] == '\n')
                m_line++;
            m_index++;
        }

        if (m_index >= m_source.size())
            return Token{TokenType::Eof, "", m_line};

        if (m_source[m_index] == '(')
        {
            m_index++;
            return Token{TokenType::OpenParen, "(", m_line};
        }

        if (m_source[m_index] == ')')
        {
            m_index++;
            return Token{TokenType::CloseParen, ")", m_line};
        }

        if (m_source[m_index] == '{')
        {
            m_index++;
            return Token{TokenType::OpenBrace, "{", m_line};
        }

        if (m_source[m_index] == '}')
        {
            m_index++;
            return Token{TokenType::CloseBrace, "}", m_line};
        }

        if (m_source[m_index] == '"')
        {
            std::string value;
            m_index++;
            while (m_index < m_source.size() && m_source[m_index] != '"')
            {
                value += m_source[m_index];
                m_index++;
            }
            m_index++;
            return Token{TokenType::StringLiteral, value, m_line};
        }

        if (std::isalpha(m_source[m_index]))
        {
            std::string value;
            while (m_index < m_source.size() && std::isalnum(m_source[m_index]))
            {
                value += m_source[m_index];
                m_index++;
            }
            return Token{TokenType::Identifier, value, m_line};
        }

        std::cout << "Unknown token at line " << m_line << std::endl;

        return std::nullopt;
    }
}