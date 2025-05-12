#include "parser.h"
#include <stdexcept>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens) {}

std::unique_ptr<Expr> Parser::parse() {
    std::unique_ptr<Expr> result;
    
    while (!isAtEnd()) {
        if (match(TokenType::LET)) {
            // Expect identifier
            if (!match(TokenType::IDENTIFIER)) {
                throw std::runtime_error("Expected identifier after 'let'");
            }
            std::string varName = tokens[current - 1].text;
            
            // Expect equals
            if (!match(TokenType::EQUALS)) {
                throw std::runtime_error("Expected '=' after identifier");
            }
            
            // Parse expression
            result = parseExpr();
            
            // Expect semicolon
            if (!match(TokenType::SEMICOLON)) {
                throw std::runtime_error("Expected ';' after expression");
            }
        }
    }
    
    return result;
}

Token Parser::peek() const {
    return tokens[current];
}

Token Parser::advance() {
    if (!isAtEnd()) current++;
    return tokens[current - 1];
}

bool Parser::match(TokenType type) {
    if (peek().type == type) {
        advance();
        return true;
    }
    return false;
}

bool Parser::isAtEnd() const {
    return peek().type == TokenType::END_OF_FILE;
}

std::unique_ptr<Expr> Parser::parseExpr() {
    return parsePrimary();
}

std::unique_ptr<Expr> Parser::parsePrimary() {
    if (match(TokenType::NUMBER)) {
        int val = std::stoi(tokens[current - 1].text);
        return std::make_unique<NumberExpr>(val);
    }
    if (match(TokenType::IDENTIFIER)) {
        return std::make_unique<VariableExpr>(tokens[current - 1].text);
    }
    throw std::runtime_error("Expected number or identifier");
}
