#include "CalculatorVisitor.hpp"
#include "Evaluator.hpp"
#include <iostream>

extern "C"
{
#include "grammar.lexer.h"
#include "grammar.parser.h"
}


bool Evaluator::evaluate(const std::string& s, float& retval)
{
  yy_scan_string(s.c_str());
  yyout = stdout;

  CalculatorVisitor visitor;
  visitor.makeCurrent();

  int ret = yyparse();
  yylex_destroy();
  if (ret != 0)
    return false;

  auto ast = visitor.getRootNode();
  retval = ast->evaluate();
  return true;
}
