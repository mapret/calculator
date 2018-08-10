#pragma once


void lexingError(char c);
void parsingError(const char* message);

void visitNumber(float n);
void visitOperator(char op);
void visitUnaryOperator(char op);
void visitFunction(const char* name);
