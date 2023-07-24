#include <iostream>

#include "lexer/lexer.h"

int main(int argc, char **argv)
{
    islc::Lexer lexer("func main() { println(\"Hello, World!\") }");
    for (auto token = lexer.lex(); token.has_value() && token->type != islc::TokenType::Eof; token = lexer.lex())
    {
        std::cout << token.value().toString() << std::endl;
    }
}