cmake_minimum_required(VERSION 3.10)
project(BlipLang)

find_package(FLEX REQUIRED)

# Generate lexer
FLEX_TARGET(MyLexer src/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c)

# Add executable using the generated lexer and main.cpp
add_executable(bliplang
    ${FLEX_MyLexer_OUTPUTS}
    src/main.cpp
)

# Include headers if needed
target_include_directories(bliplang PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
