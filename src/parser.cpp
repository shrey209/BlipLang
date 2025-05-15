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
    Token current = getCurrentToken();

    switch (current.type) {
        case TokenType::KEYWORD:
            if (current.value == "let") {
                parseDeclaration();
            } else if (current.value == "print") {
                parsePrintStatement();
            } else if (current.value == "if") {
                parseIfStatement();
            } else {
                std::cerr << "Syntax Error: Unexpected keyword '" << current.value
                          << "' at line " << current.line << "\n";
            }
            break;

        case TokenType::VARIABLE:
            parseAssignment();
            break;

        default:
            std::cerr << "Syntax Error: Unexpected token '" << current.value
                      << "' at line " << current.line << "\n";
            break;
    }
}


void parseDeclaration() {
    if (!match(TokenType::KEYWORD, "let")) {
        std::cerr << "Syntax Error: Expected 'let' at line "
                  << getCurrentToken().line << "\n";
        return;
    }

    if (!match(TokenType::VARIABLE)) {
        std::cerr << "Syntax Error: Expected identifier after 'let' at line "
                  << getCurrentToken().line << "\n";
        return;
    }

    if (!match(TokenType::ASSIGNMENT, "=")) {
        std::cerr << "Syntax Error: Expected '=' after identifier at line "
                  << getCurrentToken().line << "\n";
        return;
    }

    parseExpression();

    if (!match(TokenType::SEMICOLON, ";")) {
        std::cerr << "Syntax Error: Expected ';' at end of declaration at line "
                  << getCurrentToken().line << "\n";
    }
}

void parseAssignment() {
    if (!match(TokenType::VARIABLE)) {
        std::cerr << "Syntax Error: Expected identifier after 'let' at line "
                  << getCurrentToken().line << "\n";
        return;
    }

    if (!match(TokenType::ASSIGNMENT, "=")) {
        std::cerr << "Syntax Error: Expected '=' after identifier at line "
                  << getCurrentToken().line << "\n";
        return;
    }

    parseExpression();

    if (!match(TokenType::SEMICOLON, ";")) {
        std::cerr << "Syntax Error: Expected ';' at end of declaration at line "
                  << getCurrentToken().line << "\n";
    }
}

void parsePrintStatement() {
    if (match(TokenType::KEYWORD, "print")) {
        parseExpression();  
        if (!match(TokenType::SEMICOLON)) {
            std::cerr << "Error: Expected ';' after print statement at line " 
                      << getCurrentToken().line << std::endl;
        }
    } else {
        std::cerr << "Error: Expected 'print' keyword at line " 
                  << getCurrentToken().line << std::endl;
    }
}

void parseIfStatement() {
    if (!match(TokenType::KEYWORD, "if")) {
        std::cerr << "Expected 'if' at line " << current.line << "\n";
        return;
    }

    if (!match(TokenType::OPEN_PAREN)) {
        std::cerr << "Expected '(' after 'if' at line " << current.line << "\n";
        return;
    }

    parseExpression();

    if (!match(TokenType::CLOSE_PAREN)) {
        std::cerr << "Expected ')' after expression at line " << current.line << "\n";
        return;
    }

    parseBlock();

 
    if (match(TokenType::KEYWORD, "else")) {
        parseBlock();
    }
}


void parseBlock() {
    if (!match(TokenType::OPEN_BRACE)) {
        std::cerr << "Expected '{' at line " << getCurrentToken().line << "\n";
        return;
    }

    parseStatementList();

    if (!match(TokenType::CLOSE_BRACE)) {
        std::cerr << "Expected '}' at line " << getCurrentToken().line << "\n";
        return;
    }
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
