#pragma once

#include <memory>
#include <variant>


using NodeValue = std::variant<float, char, std::string>;

class Ast
{
    std::unique_ptr<Ast> left_;
    std::unique_ptr<Ast> right_;
    NodeValue value_;

  public:
    void setLeft(Ast* left);
    void setRight(Ast* right);
    void setValue(NodeValue&& value);
    void print(std::ostream& out, unsigned level = 0);
    float evaluate();
};
