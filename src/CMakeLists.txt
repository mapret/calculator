cmake_minimum_required(VERSION 3.0.2)

set(gen_dir ${CMAKE_CURRENT_BINARY_DIR}/gen)
set(src_dir ${CMAKE_CURRENT_LIST_DIR})
file(MAKE_DIRECTORY ${gen_dir})
include_directories(${src_dir} ${gen_dir})

set(library_sources
    Ast.cpp
    BaseVisitor.cpp
    CalculatorVisitor.cpp
    Evaluator.cpp
    ${gen_dir}/grammar.lexer.c
    ${gen_dir}/grammar.parser.c
)
set(library_headers
    Ast.hpp
    BaseVisitor.h
    BaseVisitor.hpp
    CalculatorVisitor.hpp
    Evaluator.hpp
    ${gen_dir}/grammar.lexer.h
    ${gen_dir}/grammar.parser.h
)

add_custom_command(OUTPUT ${gen_dir}/grammar.lexer.c ${gen_dir}/grammar.lexer.h
                   COMMAND flex --header-file=${gen_dir}/grammar.lexer.h -o ${gen_dir}/grammar.lexer.c ${src_dir}/grammar.lex
                   DEPENDS grammar.lex)
add_custom_command(OUTPUT ${gen_dir}/grammar.parser.c ${gen_dir}/grammar.parser.h
                   COMMAND bison --defines=${gen_dir}/grammar.parser.h -o ${gen_dir}/grammar.parser.c ${src_dir}/grammar.y
                   DEPENDS grammar.y)

add_library(${PROJECT_NAME}-lib ${library_sources} ${library_headers})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
