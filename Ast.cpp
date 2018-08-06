#include "Ast.hpp"
#include <cassert>
#include <ostream>


void Ast::setLeft(Ast* left)
{
  left_.reset(left);
}

void Ast::setRight(Ast* right)
{
  right_.reset(right);
}

void Ast::setValue(NodeValue value)
{
  value_ = value;
}

void Ast::print(std::ostream& out, unsigned level)
{
  if (left_)
    left_->print(out, level + 1);
  if (right_)
    right_->print(out, level + 1);

  out << std::string(level * 2, ' ');
  if (std::holds_alternative<float>(value_))
    out << std::get<float>(value_) << "\n";
  else if (std::holds_alternative<char>(value_))
    out << std::get<char>(value_) << "\n";
}

float Ast::evaluate()
{
  if (left_ && right_)
  {
    float l = left_->evaluate();
    float r = right_->evaluate();

    switch (std::get<char>(value_))
    {
      case '+': return l + r;
      case '-': return l - r;
      case '*': return l * r;
      case '/': return l / r;
      default: throw std::runtime_error("Operator not supported");
    }
  }
  else if (left_)
  {
    float l = left_->evaluate();
    switch (std::get<char>(value_))
    {
      case '-': return -l;
      default: throw std::runtime_error("Operator not supported");
    }
  }
  return std::get<float>(value_);
}
