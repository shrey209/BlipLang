#include "tokenization.h"
#include <vector>
#include <iostream>

struct Token {
    TokenType type;
    std::string value;
    int line;
};

static std::vector<Token> tokens;

void addToken(TokenType type, const std::string& value, int line) {
    tokens.push_back({type, value, line});
}

void printAllTokens() {
    for (const auto& token : tokens) {
        std::string typeStr;

        switch (token.type) {
            case TokenType::INTEGER: typeStr = "INTEGER"; break;
            case TokenType::KEYWORD: typeStr = "KEYWORD"; break;
            case TokenType::VARIABLE: typeStr = "VARIABLE"; break;
            case TokenType::RELOP: typeStr = "RELOP"; break;
            case TokenType::OPERATOR: typeStr = "OPERATOR"; break;
            case TokenType::END_OF_FILE: typeStr = "EOF"; break;
            case TokenType::UNKNOWN: typeStr = "UNKNOWN"; break;
        }

        std::cout << "Token(" << typeStr << ", " << token.value << ", line " << token.line << ")\n";
    }
}
