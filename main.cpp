#include "Evaluator.hpp"
#include <iostream>
#include <map>


#define TEST(expr, result) \
{ \
  float res; \
  if (Evaluator().evaluate(expr, res) && res == result) \
    correct++; \
  else \
    wrong++; \
}

void test()
{
  unsigned correct = 0;
  unsigned wrong = 0;

  TEST("3", 3)
  TEST("2+3", 5)
  TEST("2+2*2", 6)
  TEST("2*(2+2)", 8)
  TEST("(2+2)*(3+3)", 24)
  TEST("5-3-6", -4)
  TEST("(((2)))", 2)
  TEST("(((2*(2+2))))", 8)

  std::cout << "Correct/wrong " << correct << "/" << wrong << "\n";
}

int main(int argc, char** argv)
{
  test();
}
