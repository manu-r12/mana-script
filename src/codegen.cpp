#include "codegen.h"
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>
#include <stdexcept>
#include <unordered_map>

using namespace llvm;

static std::unique_ptr<LLVMContext> context;
static std::unique_ptr<IRBuilder<>> builder;
static std::unique_ptr<Module> module;
static std::unordered_map<std::string, Value*> namedValues;

void initializeLLVM() {
    context = std::make_unique<LLVMContext>();
    builder = std::make_unique<IRBuilder<>>(*context);
    module = std::make_unique<Module>("mana", *context);
    namedValues.clear();
}

Value* codegenExpr(const std::unique_ptr<Expr>& expr) {
    if (!expr) {
        throw std::runtime_error("Null expression in codegen");
    }

    if (auto num = dynamic_cast<NumberExpr*>(expr.get())) {
        return ConstantInt::get(Type::getInt32Ty(*context), num->value);
    }
    if (auto var = dynamic_cast<VariableExpr*>(expr.get())) {
        auto it = namedValues.find(var->name);
        if (it == namedValues.end()) {
            throw std::runtime_error("Undefined variable: " + var->name);
        }
        return it->second;
    }
    if (auto bin = dynamic_cast<BinaryExpr*>(expr.get())) {
        Value* L = codegenExpr(bin->left);
        Value* R = codegenExpr(bin->right);
        if (!L || !R) {
            throw std::runtime_error("Invalid binary expression operands");
        }
        return builder->CreateAdd(L, R, "addtmp");
    }
    throw std::runtime_error("Unknown expression type in codegen");
}

void generateLLVMIR(const std::unique_ptr<Expr>& ast) {
    if (!ast) {
        throw std::runtime_error("Null AST in codegen");
    }

    initializeLLVM();

    // Create main function
    FunctionType* funcType = FunctionType::get(Type::getInt32Ty(*context), false);
    Function* mainFunc = Function::Create(funcType, Function::ExternalLinkage, "main", module.get());

    // Create entry block
    BasicBlock* BB = BasicBlock::Create(*context, "entry", mainFunc);
    builder->SetInsertPoint(BB);

    // Generate code for the expression
    Value* result = codegenExpr(ast);
    if (!result) {
        throw std::runtime_error("Failed to generate code for expression");
    }

    // Return the result
    builder->CreateRet(result);

    // Print the generated IR
    module->print(outs(), nullptr);
}
