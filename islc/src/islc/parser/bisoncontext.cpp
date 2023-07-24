#include "islc/core/application.h"

#include "islc/core/base.h"

extern int yylineno;
extern char *yytext;

int yyerror(const char *s)
{
    auto &app = islc::Application::get();
    app.error(fmt::format("ictl: line {}: {} at character '{}'", yylineno, s, yytext));
    return 0;
}