#pragma once

#include <string>


class Evaluator
{
  public:
    bool evaluate(const std::string& s, float& retval, std::ostream* err = nullptr);
};
