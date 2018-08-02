cmake_minimum_required(VERSION 3.0.2)

project(Calculator)
set(CMAKE_CXX_STANDARD 17)

include(cmake/qt_functions.cmake)
set(UI_DIR ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/ui)

file(GLOB sources
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
     )
file(GLOB headers
     "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.inl"
     )
file(GLOB ui_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     "${CMAKE_CURRENT_SOURCE_DIR}/*.ui"
     )

qt_add_uic_files(uic_output ${ui_files})
qt_add_moc_files(moc_output ${headers})
if (UNIX)
    set(CMAKE_CXX_FLAGS "-fPIC")
endif ()

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/grammar.lexer.c
                   COMMAND flex --header-file=${CMAKE_CURRENT_SOURCE_DIR}/grammar.lexer.h -o ${CMAKE_CURRENT_SOURCE_DIR}/grammar.lexer.c ${CMAKE_CURRENT_SOURCE_DIR}/grammar.lex
                   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/grammar.lex)

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/grammar.parser.c
                   COMMAND bison --defines=${CMAKE_CURRENT_SOURCE_DIR}/grammar.parser.h -o ${CMAKE_CURRENT_SOURCE_DIR}/grammar.parser.c ${CMAKE_CURRENT_SOURCE_DIR}/grammar.y
                   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/grammar.y)

add_executable(${PROJECT_NAME} ${sources} ${headers} ${uic_output} ${moc_output} grammar.lexer.c grammar.parser.c)
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)
