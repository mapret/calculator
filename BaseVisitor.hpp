#pragma once


class BaseVisitor
{
  public:
    void makeCurrent();
    virtual void visitNumber(float number) {}
    virtual void visitOperator(char op) {}
    virtual void visitUnaryOperator(char op) {}
};
