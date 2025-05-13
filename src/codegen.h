#pragma once
#include "parser.h"
#include <memory>

void generateLLVMIR(const std::unique_ptr<Expr>& ast);
