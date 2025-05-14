#include <cstdio>
extern "C" {
    int yylex();   
    extern FILE* yyin; 
}

int main() {
  yyin = fopen("../input.txt", "r");

    if (!yyin) {
        perror("Failed to open input.txt");
        return 1;
    }

    yylex();
    fclose(yyin);
    return 0;
}
