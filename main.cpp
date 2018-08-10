#include "Evaluator.hpp"
#include <cmath>
#include <iostream>
#include <map>


#define TEST(expr, result) \
{ \
  float res; \
  if (Evaluator().evaluate(expr, res) && approximatelyEqual(res, static_cast<float>(result))) \
    correct++; \
  else \
    wrong++; \
}

template <typename T>
bool approximatelyEqual(T a, T b, T epsilon = T(10.e-4))
{
  return std::abs(a - b) <= ((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * epsilon);
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
  TEST("2+-+-+-3", -1)
  TEST("--2", 2)
  TEST("2^10", 1024)
  TEST("2+2*2^2", 10)
  TEST("2^3^4", 4096)
  TEST("2^-3", 0.125)
  TEST("cos(1)", 0.5403023058681398)
  TEST("sin(asin(0.3))", 0.3)
  TEST("sin(0.3)^2+cos(0.3)^2", 1)
  TEST("sin(0.2)/cos(0.2)-tan(0.2)", 0)

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
