#include <vector>
#include <string_view>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "InputText.hpp"

mkmpNS::InputText::InputText(const std::string_view& filename)
{
  m_filename = filename;
} 

mkmpNS::InputText::~InputText() {};

void mkmpNS::InputText::getPointValues(const int numDims, 
                                       std::vector<double>& pointValues) const
{
  std::cout << "getPointValues" << "\n";

  std::ifstream ifstream{m_filename};
  if (!ifstream)
    throw std::runtime_error("\n***** ERROR: Couldn't open point value file.\n\n");

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