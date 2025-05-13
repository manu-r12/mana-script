#pragma once
#include "lexer.h"
#include <memory>
#include <vector>

struct Expr {
    virtual ~Expr() = default;
};

struct NumberExpr : Expr {
    int value;
    NumberExpr(int val) : value(val) {}
};

struct BinaryExpr : Expr {
    std::unique_ptr<Expr> left, right;
    BinaryExpr(std::unique_ptr<Expr> l, std::unique_ptr<Expr> r)
        : left(std::move(l)), right(std::move(r)) {}
};

struct VariableExpr : Expr {
    std::string name;
    VariableExpr(const std::string& n) : name(n) {}
};

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);
    std::unique_ptr<Expr> parse();

private:
    std::vector<Token> tokens;
    size_t current = 0;

    Token peek() const;
    Token advance();
    bool match(TokenType type);
    bool isAtEnd() const;
    
    std::unique_ptr<Expr> parseExpr();
    std::unique_ptr<Expr> parsePrimary();
};

std::unique_ptr<Expr> parse(const std::vector<Token>& tokens);
