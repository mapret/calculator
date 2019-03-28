cmake_minimum_required(VERSION 3.0.2)

project(Calculator)
set(CMAKE_CXX_STANDARD 17)

set(library_sources
    Ast.cpp
    BaseVisitor.cpp
    CalculatorVisitor.cpp
    Evaluator.cpp
    grammar.lexer.c
    grammar.parser.c
)
set(library_headers
    Ast.hpp
    BaseVisitor.h
    BaseVisitor.hpp
    CalculatorVisitor.hpp
    Evaluator.hpp
    grammar.lexer.h
    grammar.parser.h
)

if (UNIX)
    set(CMAKE_CXX_FLAGS "-fPIC")
endif ()

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/grammar.lexer.c
                   COMMAND flex --header-file=${CMAKE_CURRENT_SOURCE_DIR}/grammar.lexer.h -o ${CMAKE_CURRENT_SOURCE_DIR}/grammar.lexer.c ${CMAKE_CURRENT_SOURCE_DIR}/grammar.lex
                   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/grammar.lex)

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/grammar.parser.c
                   COMMAND bison --defines=${CMAKE_CURRENT_SOURCE_DIR}/grammar.parser.h -o ${CMAKE_CURRENT_SOURCE_DIR}/grammar.parser.c ${CMAKE_CURRENT_SOURCE_DIR}/grammar.y
                   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/grammar.y)

add_library(${PROJECT_NAME}-lib ${library_sources} ${library_headers} grammar.lexer.c grammar.parser.c)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

add_subdirectory(test)
