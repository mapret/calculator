#pragma once

#include "Ast.hpp"
#include "BaseVisitor.hpp"
#include <stack>


class CalculatorVisitor : public BaseVisitor
{
  public:
    void visitNumber(int number) override;
    void visitOperator(char op) override;

    std::unique_ptr<Ast> getRootNode();

  private:
    std::stack<Ast*> stack_;
};