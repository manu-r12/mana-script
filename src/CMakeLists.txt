cmake_minimum_required(VERSION 3.15)
project(mana_compiler)

set(CMAKE_CXX_STANDARD 17)

# Find LLVM package


message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Add LLVM include and lib paths
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Enable all LLVM components (or choose specific ones)
llvm_map_components_to_libnames(llvm_libs core support irreader)

# Source files
set(SOURCES
    main.cpp
    lexer.cpp
    parser.cpp
    codegen.cpp
)

# Create the executable
add_executable(mana ${SOURCES})

# Link LLVM libraries
target_link_libraries(mana ${llvm_libs})
