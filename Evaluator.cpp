#include "CalculatorVisitor.hpp"
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

  CalculatorVisitor visitor;
  visitor.makeCurrent();

  int ret = yyparse();
  yylex_destroy();
  std::cout << "- " << ret << " -\n";

  auto ast = visitor.getRootNode();
  //ast->print(std::cout);
  std::cout << "Evaluate: " << ast->evaluate() << "\n";
}
