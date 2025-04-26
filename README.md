# Mana-script
mana-script is a simple programming language built using the LLVM framework. Inspired by the Kaleidoscope tutorial, this project demonstrates the process of building a basic language, from lexical analysis to code generation.

## Chapters Implemented:
Chapter 1: Lexer & Basic Parsing
We implement a simple lexer and parser to process the basic structure of the language.

Chapter 2: Code Generation to LLVM IR
With the lexer and parser in place, we generate LLVM Intermediate Representation (IR) code that can be compiled and executed.

👥 Team Members
Manu

Ayush

Adnan

Manish

🛠️ Getting Started
Prerequisites
C++ compiler (C++17 or later)

LLVM (version 14.0+ recommended)

CMake

Build Instructions
bash
Copy
Edit
# Clone the repo
git clone https://github.com/adnanis78612/mana-script.git
cd mana-script

# Create a build directory
mkdir build && cd build

# Configure CMake and build
cmake ..
make

# Run the mana-script
./mana-script
⚡ Features
Simple lexer and parser

Code generation to LLVM IR

Compilation with JIT support

🤝 Contributing
Feel free to contribute to this project, suggest ideas, or report issues.

