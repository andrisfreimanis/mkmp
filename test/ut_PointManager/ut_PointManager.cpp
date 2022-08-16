#include <vector>
#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "helper.hpp"
#include "PointManager.hpp"

namespace testNS
{
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


  int test1D()
  {
    int retVal{0};
    mkmpNS::ParamStruct testParams{};
    testParams.numDims = 1;
    testParams.pointFile = "1D.csv";
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
    testParams.pointFile = "2D.csv";
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

  int test3DIncorrectDims()
  {
    int retVal{0};
    mkmpNS::ParamStruct testParams{};
    testParams.numDims = 3;
    testParams.pointFile = "3DIncorrectDims.csv";
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

  int testCommentsEmptyLines()
  {
    int retVal{0};
    mkmpNS::ParamStruct testParams{};
    testParams.numDims = 3;
    testParams.pointFile = "commentsEmptyLines.csv";
    mkmpNS::PointManager testObject{testParams};
    testObject.loadPointValues();
    const std::vector<double> *loadedVals{testObject.getPointValues()};
    constexpr std::array<double, 6> correctVals{1.234, -1234.0, -12.3e-4, 1.2e3, -12.3e-4, 0.123};
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

  int testNaN()
  {
    int retVal{0};
    mkmpNS::ParamStruct testParams{};
    testParams.numDims = 3;
    testParams.pointFile = "nan.csv";
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

} // testNS

  int main()
  { 
    int retVal{0};
    retVal += testNS::testNoFile();
    retVal += testNS::testEmptyFile();
    retVal += testNS::test1D();
    retVal += testNS::test2D();
    retVal += testNS::testCommentsEmptyLines();
    retVal += testNS::testNaN();
    return retVal;
  }