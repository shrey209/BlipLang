#include <cstdio>
#include "tokenization.h"

extern FILE* yyin;
extern int yylex();

int main() {
    yyin = fopen("../input.txt", "r");

    if (!yyin) {
        perror("Failed to open input.txt");
        return 1;
    }

    // Start lexing process
    yylex();

    // After lexing, print all tokens
    printAllTokens();

    fclose(yyin);
    return 0;
}
