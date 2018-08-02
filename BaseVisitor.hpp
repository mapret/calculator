#pragma once


class BaseVisitor
{
  public:
    void makeCurrent();
    virtual void visitNumber(int number) {}
    virtual void visitOperator(char op) {}
};
