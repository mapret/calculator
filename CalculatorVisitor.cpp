#include <cassert>
#include <iostream>
#include "CalculatorVisitor.hpp"


std::unique_ptr<Ast> CalculatorVisitor::getRootNode()
{
  auto ret = std::unique_ptr<Ast>(stack_.top());
  stack_.pop();
  assert(stack_.empty());
  return ret;
}

void CalculatorVisitor::visitNumber(int number)
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
  node->setLeft(stack_.top());
  stack_.pop();
  node->setRight(stack_.top());
  stack_.pop();
  node->setValue(op);
  stack_.push(node);
}
