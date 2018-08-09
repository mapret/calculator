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

int test()
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
  TEST("-2", -2)
  TEST("-2+3", 1)
  TEST("-(1+2)", -3)
  TEST("2+-3", -1)
  TEST("2--3", 5)
  TEST("2+++3", 5)
  TEST("2+-+-+-3", -1);
  TEST("--2", 2)

  std::cout << "Correct/wrong " << correct << "/" << wrong << "\n";
  return wrong != 0;
}

int interactive()
{
  std::string s;
  Evaluator evaluator;
  while (std::getline(std::cin, s))
  {
    float retval;
    if (evaluator.evaluate(s, retval, &std::cout))
      std::cout << retval << "\n";
  }
  return 0;
}

int main(int argc, char** argv)
{
  if (argc == 1)
    return interactive();

  std::string mode(argv[1]);
  if (mode == "test")
    return test();

  return 1;
}
