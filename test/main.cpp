#include "src/Evaluator.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>


namespace fs = std::filesystem;

template <typename T>
bool approximatelyEqual(T a, T b, T epsilon = T(10.e-4))
{
  return std::abs(a - b) <= std::max(std::max(std::abs(a), std::abs(b)), epsilon) * epsilon;
}

int main(int argc, const char** argv)
{
  std::vector<std::pair<std::string, std::string>> testcases;
  for (const auto& direntry : fs::directory_iterator("test/data"))
  {
    std::ifstream in(direntry.path());
    std::string input, reference, dummy;
    while (!in.eof())
    {
      std::getline(in, input);
      std::getline(in, reference);
      std::getline(in, dummy);
      testcases.emplace_back(input, reference);
    }
  }

  int num_correct = 0;
  int num_wrong = 0;

  for (const auto& testcase : testcases)
  {
    float reference = std::stof(testcase.second);
    float retval;
    if (Evaluator().evaluate(testcase.first, retval) && approximatelyEqual(reference, retval))
    {
      num_correct++;
    }
    else
    {
      num_wrong++;
      std::cout << "FAIL: " << testcase.first << " was " << retval << " but should be " << reference << std::endl;
    }
  }

  std::cout << "Num correct/wrong: " << num_correct << "/" << num_wrong << std::endl;

  return num_wrong != 0;
}
