#include "lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string& input) : input(input) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    
    while (position < input.length()) {
        skipWhitespace();
        
        if (position >= input.length()) break;
        
        char c = current();
        
        if (std::isalpha(c)) {
            tokens.push_back(scanIdentifier());
        }
        else if (std::isdigit(c)) {
            tokens.push_back(scanNumber());
        }
        else if (c == '=') {
            tokens.push_back({TokenType::EQUALS, "="});
            advance();
        }
        else if (c == ';') {
            tokens.push_back({TokenType::SEMICOLON, ";"});
            advance();
        }
        else {
            throw std::runtime_error("Unexpected character: " + std::string(1, c));
        }
    }
    
    tokens.push_back({TokenType::END_OF_FILE, ""});
    return tokens;
}

char Lexer::current() const {
    return position < input.length() ? input[position] : '\0';
}

char Lexer::advance() {
    return input[position++];
}

void Lexer::skipWhitespace() {
    while (position < input.length() && std::isspace(current())) {
        advance();
    }
}

Token Lexer::scanIdentifier() {
    std::string identifier;
    while (position < input.length() && (std::isalnum(current()) || current() == '_')) {
        identifier += advance();
    }
    
    if (identifier == "let") {
        return {TokenType::LET, identifier};
    }
    return {TokenType::IDENTIFIER, identifier};
}

Token Lexer::scanNumber() {
    std::string number;
    while (position < input.length() && std::isdigit(current())) {
        number += advance();
    }
    return {TokenType::NUMBER, number};
}
