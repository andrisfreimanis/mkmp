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
    throw std::runtime_error("\n\n***** ERROR: Couldn't open the point value file.\n\n");

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