#include "Evaluator.hpp"

int main(int argc, char** argv)
{
  Evaluator().evaluate("((1+2)+(3+4))+(5+(6+(7*8)))");
}
