#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

#include "mkmp.hpp"
#include "PointManager.hpp"

mkmpNS::MKMP::MKMP(const std::string inputFile)
{
  // Read input file and build the param struct
  std::string_view fileExtension;
  size_t position{inputFile.rfind(".")};
  if (position != std::string_view::npos)
    fileExtension = inputFile.substr(position);

  if (fileExtension == ".txt")
  {
    buildParamList(inputFile);
  } 
  else
    throw std::runtime_error("\n\n***** ERROR: Unrecognized input file extension. Only .txt files are supported.\n\n");
  
  // Create point manager and load point data
  m_pointManager = mkmpNS::PointManager(m_paramList);
  m_pointManager.loadPointValues();
  
  // Create output manager


  std::cout << "Filename is: " << inputFile << "\n";
}

void mkmpNS::MKMP::executeSolver( )
{
  std::cout << "Execute solver\n";
}

void mkmpNS::MKMP::storeResults( )
{ 
  std::cout << "Store results\n";
}


void mkmpNS::MKMP::buildParamList(const std::string inputFile)
{
  std::ifstream ifstream(inputFile);
  if (!ifstream)
    throw std::runtime_error("\n\n***** ERROR: Couldn't open the input file.\n\n");
  
  while (ifstream.good())
  {
    std::string line{};
    std::getline(ifstream, line);
    size_t pos{line.rfind(":")};
    if (pos != std::string_view::npos)
    {
      std::string key{line.substr(0, pos+1)};
      std::string val{line.substr(pos)};
      if (key == "Number of dimensions")
        m_paramList.numDims = std::stoi(val);
      else if (key == "Delimiter")
        m_paramList.delimiter = *(val.c_str());
      else if (key == "Point file")
        m_paramList.pointFile = val;
    }
    else
      throw std::runtime_error("\n\n***** ERROR: ':' must separate all key : val pairs in the input file.\n\n");
  }
}

