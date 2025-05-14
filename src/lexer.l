%option noyywrap

%{
#include <iostream>
#include <cstring>
#include "tokenization.h"

int currLine = 1;
%}

%%

[0-9]+              { addToken(TokenType::INTEGER, yytext, currLine); }

[a-zA-Z_][a-zA-Z0-9_]* {
    if (strcmp(yytext, "if") == 0) {
        addToken(TokenType::KEYWORD, "if", currLine);
    } else if (strcmp(yytext, "else") == 0) {
        addToken(TokenType::KEYWORD, "else", currLine);
    } else {
        addToken(TokenType::VARIABLE, yytext, currLine);
    }
}

"<="                { addToken(TokenType::RELOP, "<=", currLine); }
">="                { addToken(TokenType::RELOP, ">=", currLine); }
"<"                 { addToken(TokenType::RELOP, "<", currLine); }
">"                 { addToken(TokenType::RELOP, ">", currLine); }
"+"                 { addToken(TokenType::OPERATOR, "+", currLine); }
"-"                 { addToken(TokenType::OPERATOR, "-", currLine); }
";"                 { addToken(TokenType::END_OF_FILE, ";", currLine); }

"//".*              { /* Ignore single-line comments */ }
"/*"([^*]|\*+[^*/])*\*+"/"   { /* Ignore multi-line comments */ }

[ \t\r]+            { /* Ignore spaces and tabs */ }
\n                  { currLine++; }

.                   { addToken(TokenType::UNKNOWN, yytext, currLine); }

%%
