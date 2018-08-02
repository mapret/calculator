#include "Evaluator.hpp"
#include <iostream>

extern "C"
{
#include "grammar.lexer.h"
#include "grammar.parser.h"
}


void Evaluator::evaluate(const std::string& s)
{
  yy_scan_string(s.c_str());
  yyout = stdout;

  int ret = yyparse();
  std::cout << "- " << ret << " -\n";
}
