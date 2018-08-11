#pragma once


void lexingError(char c);
void parsingError(const char* message);

void visitNumber(float n);
void visitConstant(const char* name);
void visitOperator(char op);
void visitUnaryOperator(char op);
void visitFunction(const char* name);
