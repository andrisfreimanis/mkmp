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

int testLoadPointValuesEmptyFile()
{
  int retVal{0};
  mkmpNS::ParamStruct testParams{};
  testParams.numDims = 1;
  testParams.pointFile = "emptyFile.csv";
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

int testLoadPointValuesIncorrectDims()
{
  return 0;
}

int testLoadPointValuesCorrectDims()
{ 
  return 0;
}

int testLoadPointValuesTwoCorrectRows()
{
  return 0;
}

int testLoadPointValuesTwoIncorrectRows()
{
  return 0;
}

int testLoadPointValuesThreeRows()
{
  return 0;
}

int main()
{ 
  int retVal{0};
  retVal += testLoadPointValuesNoFile();
  retVal += testLoadPointValuesEmptyFile();
  retVal += testLoadPointValuesIncorrectDims();
  retVal += testLoadPointValuesCorrectDims();
  retVal += testLoadPointValuesTwoCorrectRows();
  retVal += testLoadPointValuesTwoIncorrectRows();
  retVal += testLoadPointValuesThreeRows();

  return retVal;
}