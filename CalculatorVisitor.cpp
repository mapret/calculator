#include <cassert>
#include <iostream>
#include "CalculatorVisitor.hpp"


CalculatorVisitor::CalculatorVisitor(std::ostream& error_stream)
  : error_stream_(error_stream)
{
}

std::unique_ptr<Ast> CalculatorVisitor::getRootNode()
{
  auto ret = std::unique_ptr<Ast>(stack_.top());
  stack_.pop();
  assert(stack_.empty());
  return ret;
}

void CalculatorVisitor::lexingError(char c)
{
  error_stream_ << "Lexing error: " << c << "\n";
}

void CalculatorVisitor::parsingError(const std::string& message)
{
  error_stream_ << "Parsing error: " << message << "\n";
}

void CalculatorVisitor::visitNumber(float number)
{
  //std::cout << "number: " << number << "\n";
  auto node = new Ast;
  node->setValue(number);
  stack_.push(node);
}

void CalculatorVisitor::visitOperator(char op)
{
  //std::cout << "op: " << op << "\n";
  auto node = new Ast;
  node->setRight(stack_.top());
  stack_.pop();
  node->setLeft(stack_.top());
  stack_.pop();
  node->setValue(op);
  stack_.push(node);
}

void CalculatorVisitor::visitUnaryOperator(char op)
{
  //std::cout << "uop: " << op << "\n";
  if (op == '+')
    return; //Do nothing at unary "+"
  auto node = new Ast;
  node->setLeft(stack_.top());
  stack_.pop();
  node->setValue(op);
  stack_.push(node);
}

void CalculatorVisitor::visitFunction(const std::string& name)
{
  //std::cout << "function: " << name << "\n";
  auto node = new Ast;
  node->setLeft(stack_.top());
  stack_.pop();
  node->setValue(name);
  stack_.push(node);
}
