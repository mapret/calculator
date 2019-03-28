#include "Evaluator.hpp"
#include <iostream>


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

  return 1;
}
