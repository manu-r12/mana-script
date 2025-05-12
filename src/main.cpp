#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "codegen.h"

int main() {
    try {
        std::cout << "Mana Script Compiler (Prototype)\n";
        
        // Example input: "let x = 42;"
        std::string input = "let x = 42;";
        std::cout << "Input: " << input << "\n\n";
        
        // Lexical analysis
        Lexer lexer(input);
        auto tokens = lexer.tokenize();
        std::cout << "Tokens:\n";
        for (const auto& token : tokens) {
            std::cout << "  " << token.text << "\n";
        }
        std::cout << "\n";
        
        // Parsing
        Parser parser(tokens);
        auto ast = parser.parse();
        if (!ast) {
            throw std::runtime_error("Failed to parse input");
        }
        std::cout << "Parsing successful\n\n";
        
        // Code generation
        std::cout << "Generated LLVM IR:\n";
        generateLLVMIR(ast);
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}