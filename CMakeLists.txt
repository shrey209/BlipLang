cmake_minimum_required(VERSION 3.10)
project(BlipLang)

find_package(FLEX REQUIRED)

# Tell Flex to output a C++-compiled file
FLEX_TARGET(MyLexer src/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp)

# Add executable using the generated lexer and C++ sources
add_executable(bliplang
    ${FLEX_MyLexer_OUTPUTS}
    src/main.cpp
    src/tokenization.cpp
)

# C++ standard
set_target_properties(bliplang PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# Include headers
target_include_directories(bliplang PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
