#ifndef TOKENIZATION_H
#define TOKENIZATION_H

#include <string>
#include <vector>  // <-- ADD THIS LINE

enum class TokenType {
    INTEGER,
    KEYWORD,
    VARIABLE,
    RELOP,
    OPERATOR,
    ASSIGNMENT,
    SEMICOLON,
    OPEN_BRACE,
    CLOSE_BRACE,
    OPEN_PAREN,
    CLOSE_PAREN,
    END_OF_FILE,
    UNKNOWN
};

// Forward declaration of Token struct/class
struct Token;

void addToken(TokenType type, const std::string& value, int line);
void printAllTokens();
const std::vector<Token>& getTokens();

#endif
