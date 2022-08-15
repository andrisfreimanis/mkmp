#include <vector>
#include <array>
#include <string>
#include <iostream>
#include <fstream>

#include "helper.hpp"
#include "PointManager.hpp"

int testNoFile()
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

int testEmptyFile()
{
  int retVal{1};
  mkmpNS::ParamStruct testParams{};
  testParams.numDims = 1;
  testParams.pointFile = "./test/ut_PointManager/emptyFile.csv";
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


int test1D()
{
  int retVal{0};
  mkmpNS::ParamStruct testParams{};
  testParams.numDims = 1;
  testParams.pointFile = "./test/ut_PointManager/1D.csv";
  mkmpNS::PointManager testObject{testParams};
  testObject.loadPointValues();
  const std::vector<double> *loadedVals{testObject.getPointValues()};
  constexpr std::array<double, 8> correctVals{1.234, -12.34, 1.2e3, -12.3e4, 1.2e-3, -12.3e-4, 1234.0, -1234.0};
  int index{0};
  for (auto val : correctVals)
  {
    if (val != (*loadedVals)[index])
    {
      retVal = 1;
      break;
    }
    else 
      ++index;
  }
  return retVal;
}

int test2D()
{
  int retVal{0};
  mkmpNS::ParamStruct testParams{};
  testParams.numDims = 2;
  testParams.pointFile = "./test/ut_PointManager/2D.csv";
  mkmpNS::PointManager testObject{testParams};
  testObject.loadPointValues();
  const std::vector<double> *loadedVals{testObject.getPointValues()};
  constexpr std::array<double, 8> correctVals{1.234, -1234, 1.2e3, -12.3e-4, -12.3e-4, 1.2e3, 1234.0, -12.34};
  int index{0};
  for (auto val : correctVals)
  {
    if (val != (*loadedVals)[index])
    {
      retVal = 1;
      break;
    }
    else 
      ++index;
  }
  return retVal;
}

int testLoadPointValuesIncorrectDims2D()
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

int testLoadPointValuesNaN()
{
  return 0;
}

int main()
{ 
  int retVal{0};
  retVal += testNoFile();
  retVal += testEmptyFile();
  retVal += test1D();
  retVal += test2D();
  retVal += testLoadPointValuesTwoCorrectRows();
  retVal += testLoadPointValuesTwoIncorrectRows();
  retVal += testLoadPointValuesThreeRows();
  retVal += testLoadPointValuesNaN();

  return retVal;
}