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
    }else if(strcmp(yytext, "let")==0){
        addToken(TokenType::KEYWORD, "let", currLine);
    }else if(strcmp(yytext, "print")==0){
        addToken(TokenType::KEYWORD, "print", currLine);
    } 
    else {
        addToken(TokenType::VARIABLE, yytext, currLine);
    }
}
"="     { addToken(TokenType::ASSIGNMENT, "=", currLine); }
"<="                { addToken(TokenType::RELOP, "<=", currLine); }
">="                { addToken(TokenType::RELOP, ">=", currLine); }
"<"                 { addToken(TokenType::RELOP, "<", currLine); }
">"                 { addToken(TokenType::RELOP, ">", currLine); }
"+"                 { addToken(TokenType::OPERATOR, "+", currLine); }
"-"                 { addToken(TokenType::OPERATOR, "-", currLine); }
";"                 { addToken(TokenType::END_OF_FILE, ";", currLine); }
"{"     { addToken(TokenType::OPEN_BRACE, yytext, currLine); }
"}"     { addToken(TokenType::CLOSE_BRACE, yytext, currLine); }
"("     { addToken(TokenType::OPEN_PAREN, yytext, currLine); }
")"     { addToken(TokenType::CLOSE_PAREN, yytext, currLine); }


"//".*              { /* Ignore single-line comments */ }
"/*"([^*]|\*+[^*/])*\*+"/"   { /* Ignore multi-line comments */ }

[ \t\r]+            { /* Ignore spaces and tabs */ }
\n                  { currLine++; }

.                   { addToken(TokenType::UNKNOWN, yytext, currLine); }

%%
