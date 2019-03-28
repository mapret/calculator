#include "CalculatorVisitor.hpp"
#include "Evaluator.hpp"
#include <iostream>

extern "C"
{
#include "grammar.lexer.h"
#include "grammar.parser.h"
}


bool Evaluator::evaluate(const std::string& s, float& retval, std::ostream* err)
{
  yy_scan_string(s.c_str());

  std::stringstream error_stream;
  CalculatorVisitor visitor(error_stream);
  visitor.makeCurrent();

  int ret = yyparse();
  yylex_destroy();

  if (err)
    *err << error_stream.str();
  if (ret != 0)
    return false;

  auto ast = visitor.getRootNode();
  retval = ast->evaluate();
  return error_stream.str().empty();
}
