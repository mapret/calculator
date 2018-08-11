#pragma once

#include "Ast.hpp"
#include "BaseVisitor.hpp"
#include <sstream>
#include <stack>


class CalculatorVisitor : public BaseVisitor
{
  public:
    CalculatorVisitor(std::ostream& error_stream);

    void lexingError(char c) override;
    void parsingError(const std::string& message) override;
    void visitNumber(float number) override;
    void visitConstant(const std::string& name) override;
    void visitOperator(char op) override;
    void visitUnaryOperator(char op) override;
    void visitFunction(const std::string& name) override;

    std::unique_ptr<Ast> getRootNode();

  private:
    std::stack<Ast*> stack_;
    std::ostream& error_stream_;
};
