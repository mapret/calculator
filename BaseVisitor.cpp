#include "BaseVisitor.hpp"
extern "C"
{
#include "BaseVisitor.h"
}


BaseVisitor* visitor = nullptr;

void BaseVisitor::makeCurrent()
{
  visitor = this;
}

void visitNumber(int n)
{
  if (visitor)
    visitor->visitNumber(n);
}

void visitOperator(char op)
{
  if (visitor)
    visitor->visitOperator(op);
}
