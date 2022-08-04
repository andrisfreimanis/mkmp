#include <vector>
#include <string_view>
#include <iostream>

#include "InputText.hpp"

namespace testNS
{
  class ut_Wrapper : public mkmpNS::InputText
  {
    public:
      ut_Wrapper(const std::string_view& filename) : mkmpNS::InputText(filename) {}

      ~ut_Wrapper() {}

      std::string_view m_wrap_filename{m_filename};
  };
}

void printTestResult(const bool testPassed, const std::string_view& testName)
{
  std::string_view passFail{testPassed ? "passed" : "failed"};
  std::cout << "Test: " << testName << " " << passFail << ".\n";
}

int main()
{ 
  std::cout << "\n*****\nTesting ut_InputTest\n";
  int numFailedTests{0};

  {
    std::string_view testName{"buildInputText"};
    std::string_view testFilename{"test.csv"};
    testNS::ut_Wrapper testObject{testFilename};
    int retVal{testObject.m_wrap_filename.compare(testFilename)};
    bool testPassed{retVal == 0 ? true : false};
    if (!testPassed)
      ++numFailedTests;
    printTestResult(testPassed, testName);
  }

  {
    std::string_view testName{"getPointValuesNoFile"};
    std::string_view testFilename{"incorrectFilename.csv"};
    testNS::ut_Wrapper testObject{testFilename};
    
    int numDims{0};
    std::vector<double> testVector{};
    bool testPassed{false};
    try
    {
      testObject.getPointValues(numDims, testVector);
    }
    catch(const std::exception& e)
    {
      testPassed = true;
    }

    if (!testPassed)
      ++numFailedTests;
    printTestResult(testPassed, testName);    
  }

  std::cout << "Number of failed tests: " << numFailedTests << ".\n*****\n";
}