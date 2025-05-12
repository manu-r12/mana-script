#pragma once
#include <string>
#include <vector>

enum class TokenType {
    LET,
    IDENTIFIER,
    EQUALS,
    NUMBER,
    SEMICOLON,
    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string text;
};

class Lexer {
public:
    explicit Lexer(const std::string& input);
    std::vector<Token> tokenize();

private:
    std::string input;
    size_t position = 0;
    
    char current() const;
    char advance();
    void skipWhitespace();
    Token scanIdentifier();
    Token scanNumber();
};
