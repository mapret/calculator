#include "Ast.hpp"
#include <cassert>
#include <cmath>
#include <ostream>


void Ast::setLeft(Ast* left)
{
  left_.reset(left);
}

void Ast::setRight(Ast* right)
{
  right_.reset(right);
}

void Ast::setValue(NodeValue&& value)
{
  value_ = std::move(value);
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
      case '^': return std::pow(l, r);
      default: throw std::runtime_error("Operator not supported");
    }
  }
  else if (left_)
  {
    float l = left_->evaluate();
    if (std::holds_alternative<char>(value_)) //unary operator
    {
      switch (std::get<char>(value_))
      {
        case '-': return -l;
        default: throw std::runtime_error("Operator not supported");
      }
    }
    else //function
    {
      const auto& function = std::get<std::string>(value_);
      if (function == "sin")  return std::sin(l);
      if (function == "cos")  return std::cos(l);
      if (function == "tan")  return std::tan(l);
      if (function == "asin") return std::asin(l);
      if (function == "acos") return std::acos(l);
      if (function == "atan") return std::atan(l);
      if (function == "log")  return std::log10(l);
      if (function == "ln")   return std::log(l);
      if (function == "log2") return std::log2(l);
      if (function == "sqrt") return std::sqrt(l);
      throw std::runtime_error("Function \"" + function + "\" not supported");
    }
  }
  else if (std::holds_alternative<std::string>(value_)) //constant
  {
    const std::string& c = std::get<std::string>(value_);
    if (c == "PI") return 3.1415926535897932384626433f;
    if (c == "E")  return 2.7182818284590452353602874f;
    throw std::runtime_error("Constant\"" + c + "\" not known");
  }
  return std::get<float>(value_);
}
