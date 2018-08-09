#pragma once

#include <string>


class BaseVisitor
{
  public:
    void makeCurrent();
    virtual void lexingError(char c) {}
    virtual void parsingError(const std::string& message) {}
    virtual void visitNumber(float number) {}
    virtual void visitOperator(char op) {}
    virtual void visitUnaryOperator(char op) {}
};
