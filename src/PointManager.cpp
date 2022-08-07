#include <vector>
#include <string_view>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "mkmp.hpp"
#include "PointManager.hpp"

mkmpNS::PointManager::PointManager(ParamStruct& params)
{
  m_numDims   = params.numDims;
  m_delimiter = params.delimiter;
  m_pointFile = params.pointFile;
} 

mkmpNS::PointManager::~PointManager() {};

void mkmpNS::PointManager::getPointValues(const int numDims, 
                                          std::vector<double>& pointValues) const
{
  std::ifstream ifstream{m_pointFile};
  if (!ifstream)
    throw std::runtime_error("\n\n***** ERROR: Couldn't open point value file.\n\n");

  while (ifstream.good())
  {
    std::string line{};
    std::getline(ifstream, line);
    std::istringstream valStream(line);

    std::string extractedVal{};
    std::getline(valStream, extractedVal, m_delimiter);
    pointValues.push_back( std::stod(extractedVal) );
  }
  std::cout << numDims << "\n";
  for (auto val : pointValues)
    std::cout << val << "\n";
}