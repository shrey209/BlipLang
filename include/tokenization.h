#ifndef TOKENIZATION_H
#define TOKENIZATION_H

#include <string>

enum class TokenType {
    INTEGER,
    KEYWORD,
    VARIABLE,
    RELOP,
    OPERATOR,
    END_OF_FILE,
    UNKNOWN
};

void addToken(TokenType type, const std::string& value, int line);
void printAllTokens();

#endif
