# 🔤 Mana Script

**Mana Script** is a lightweight, LLVM-based programming language designed for simplicity and performance. Inspired by the [LLVM Kaleidoscope tutorial](https://llvm.org/docs/tutorial/), it demonstrates how to build a custom language from scratch—starting with a lexer and parser, progressing to LLVM IR code generation, and incorporating JIT compilation.

---

## 📚 Chapters Implemented

### ✅ Chapter 1: Lexer & Basic Parsing

* Implements a tokenizer using Finite State Automata (FSA)
* Parses basic identifiers, numbers, and operators
* Builds a simple Abstract Syntax Tree (AST)

### ✅ Chapter 2: Code Generation to LLVM IR

* Converts AST into LLVM Intermediate Representation
* Generates and prints IR using LLVM C++ API

---

## ⚡ Features

* ✅ Simple Finite-State Lexer
* ✅ Recursive Descent / LL(1) Parser
* ✅ Abstract Syntax Tree generation
* ✅ LLVM IR Code Generation
* ✅ Basic JIT Compilation using LLVM
* ⚙️ Extensible Architecture (control flow, functions, user-defined operators in progress)

---

## 📂 Folder Structure

```bash
mana-script/
├── src/            # Compiler source (lexer, parser, codegen)
├── examples/       # Sample .mana programs
├── build/          # Build output
├── CMakeLists.txt  # Build config
└── README.md       # Project documentation
```

---

## 👥 Team Members

* **Manu**
* **Ayush Debnath**
* **Mohd. Adnan**
* **Manish Singh Rathaur**

---

## 🛠️ Getting Started

### ✅ Prerequisites

* C++17 or later
* [LLVM](https://llvm.org/) (version 15.0+ recommended)
* [CMake](https://cmake.org/) (3.15+)
* Git

> 💡 Works on Windows, Linux, and macOS (Tested primarily on Windows)

### 🔧 Build & Run Instructions

```bash
# Clone the repo
git clone https://github.com/adnanis78612/mana-script.git
cd mana-script

# Create a build directory
mkdir build && cd build

# Configure and build
dependency: helm package
cmake ..
cmake --build . --config Release

# Run mana-script (example)
./mana ../examples/hello.mana
```

> On Windows, run `mana.exe` instead of `./mana`.

---

## 🤝 Contributing

Contributions are welcome! If you have suggestions, bug reports, or feature ideas, feel free to:

* Open an Issue
* Create a Pull Request
* Fork and experiment!

---

## 📜 License

This project is released under the MIT License.

---

## 📎 References

* [LLVM Official Docs](https://llvm.org/docs/)
* *Compilers: Principles, Techniques, and Tools* – Aho, Lam, Sethi, Ullman
* *Lex & Yacc* by John Levine

