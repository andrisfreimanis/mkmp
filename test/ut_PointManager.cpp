#include <vector>
#include <string>
#include <iostream>

#include "helper.hpp"
#include "PointManager.hpp"

int testLoadPointValuesNoFile()
{
  int retVal{1};
  mkmpNS::ParamStruct testParams{};
  testParams.numDims = 1;
  testParams.pointFile = "noFile.csv";
  mkmpNS::PointManager testObject{testParams};
  try 
  {
    testObject.loadPointValues();
  }
  catch (const std::runtime_error &e)
  {
    retVal = 0;
  }
  return retVal;
}

int main()
{ 
  int retVal{0};
  retVal += testLoadPointValuesNoFile();
  std::cout << retVal << "\n";
  return retVal;
}