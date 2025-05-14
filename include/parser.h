#ifndef PARSER_H
#define PARSER_H

#include "tokenization.h"

Token getCurrentToken();
void advanceToken();
bool match(TokenType expectedType);
bool match(TokenType expectedType, const std::string& expectedValue); // Optional
bool isAtEnd();

void parseProgram();
void parseStatementList();
void parseStatement();
void parseDeclaration();
void parseAssignment();
void parsePrintStatement();
void parseIfStatement();
void parseBlock();
void parseExpression();
void parseExpressionPrime();
void parseTerm();
void parseTermPrime();
void parseFactor();


#endif