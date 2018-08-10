#include "BaseVisitor.hpp"
extern "C"
{
#include "BaseVisitor.h"
}


BaseVisitor* visitor_ = nullptr;
#define visitor if(visitor_) visitor_

void BaseVisitor::makeCurrent()
{
  visitor_ = this;
}

void lexingError(char c)
{
  visitor->lexingError(c);
}

void parsingError(const char* message)
{
  visitor->parsingError(std::string(message));
}

void visitNumber(float n)
{
  visitor->visitNumber(n);
}

void visitOperator(char op)
{
  visitor->visitOperator(op);
}

void visitUnaryOperator(char op)
{
  visitor->visitUnaryOperator(op);
}

void visitFunction(const char* name)
{
  visitor->visitFunction(std::string(name));
}
