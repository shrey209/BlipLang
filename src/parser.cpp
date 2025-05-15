#include "parser.h"
#include <vector>
#include <iostream>

static std::vector<Token> tokens;
static size_t currentIndex = 0;


//to set tokens
void setTokens(const std::vector<Token>& tokenList) {
    tokens = tokenList;
    currentIndex = 0;
}


//to get current token
Token getCurrentToken() {
    if (currentIndex < tokens.size()) {
        return tokens[currentIndex];
    }
    // Return dummy EOF token if out of bounds
    return Token{TokenType::END_OF_FILE, "", -1};
}

void advanceToken() {
    if (currentIndex < tokens.size()) {
        currentIndex++;
    }
}

bool match(TokenType expectedType) {
    if (getCurrentToken().type == expectedType) {
        advanceToken();
        return true;
    }
    return false;
}

bool match(TokenType expectedType, const std::string& expectedValue) {
    const Token& token = getCurrentToken();
    if (token.type == expectedType && token.value == expectedValue) {
        advanceToken();
        return true;
    }
    return false;
}

bool isAtEnd() {
    return getCurrentToken().type == TokenType::END_OF_FILE;
}

void parseProgram() {
    parseStatementList();

    if (!isAtEnd()) {
        std::cerr << "Syntax Error: Unexpected token after program end at line "
                  << getCurrentToken().line << "\n";
    }
}

void parseStatementList() {
    Token current = getCurrentToken();

    if (current.type == TokenType::KEYWORD && 
        (current.value == "let" || current.value == "if" || current.value == "print")) {
        parseStatement();
        parseStatementList(); 
    } else if (current.type == TokenType::VARIABLE) {
        parseStatement();
        parseStatementList(); 
    } else if (current.type == TokenType::CLOSE_BRACE || isAtEnd()) {
        return;
    } else {
        std::cerr << "Syntax Error: Unexpected token '" << current.value
                  << "' at line " << current.line << "\n";
    }
}


void parseStatement() {
    
}

void parseDeclaration() {
    
}

void parseAssignment() {
   
}

void parsePrintStatement() {
   
}

void parseIfStatement() {

}

void parseBlock() {

}

void parseExpression() {
   
}

void parseExpressionPrime() {
 
}

void parseTerm() {
   
}

void parseTermPrime() {
  
}

void parseFactor() {
  
}
