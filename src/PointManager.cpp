#include <fstream>
#include <sstream>
#include <iostream>

#include "PointManager.hpp"

mkmpNS::PointManager::PointManager(mkmpNS::ParamStruct& params)
{
  m_numDims   = params.numDims;
  m_delimiter = params.delimiter;
  m_pointFile = params.pointFile;
} 

void mkmpNS::PointManager::loadPointValues() 
{
  std::ifstream ifstream{m_pointFile};
  if (!ifstream)
  {
    std::string errMsg("\n\n***** ERROR: mkmpNS::PointManager::loadPointValues() Couldn't open the point value file or it's empty.\n\n");
    throw std::runtime_error(errMsg);
  }

  while (ifstream.good())
  {
    std::string line{};
    std::getline(ifstream, line);
    std::istringstream valStream(line);

    std::string extractedVal{};
    std::getline(valStream, extractedVal, m_delimiter);
    m_pointValues.push_back( std::stod(extractedVal) );
  }
  std::cout << m_numDims << "\n";
  for (auto val : m_pointValues)
    std::cout << val << "\n";
}