%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yywrap(void) {
    return 1;
}
%}

%%

[0-9]+              { printf("INTEGER: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* {
    if (strcmp(yytext, "if") == 0) {
        printf("KEYWORD: if\n");
    } else if (strcmp(yytext, "else") == 0) {
        printf("KEYWORD: else\n");
    } else {
        printf("VARIABLE: %s\n", yytext);
    }
}

"<="                { printf("RELOP: <=\n"); }
">="                { printf("RELOP: >=\n"); }
"<"                 { printf("RELOP: <\n"); }
">"                 { printf("RELOP: >\n"); }
"+"                 { printf("OPERATOR: +\n"); }
"-"                 { printf("OPERATOR: -\n"); }

";"                 { printf("EOF: ;\n"); }

"//".*              { /* Ignore single-line comments */ }

"/*"([^*]|\*+[^*/])*\*+"/"   { /* Ignore multi-line comments */ }

[ \t\n\r]+          { /* Ignore whitespace */ }

.                   { printf("UNKNOWN: %s\n", yytext); }

%%
