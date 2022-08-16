#include <fstream>
#include <sstream>
#include <string>

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
    std::string errMsg{"\n\n***** ERROR: mkmpNS::PointManager::loadPointValues() Couldn't open the file '"};
    errMsg += m_pointFile;
    errMsg += "' or it's empty.\n\n";
    throw std::runtime_error(errMsg);
  }

  std::string line{}; 
  // Loop over lines in the file
  while (std::getline(ifstream, line))
  {
    // ignore comments and empty lines, otherwise parse
    if ( !(line[0] == '/' || line[0] == '#' || line[0] == '%' || line.empty()) )
    {
      std::istringstream valStream(line);
      std::string extractedVal{};

      //Loop over values in the line
      int columnCounter{0};
      while(std::getline(valStream, extractedVal, m_delimiter))
      {
        if (isNumber(extractedVal))
        {
          m_pointValues.emplace_back( std::stod(extractedVal) );
          ++columnCounter;
        }
        else
        {
          std::string errMsg{"\n\n***** ERROR: mkmpNS::PointManager::loadPointValues() Value '"};
          errMsg += extractedVal;
          errMsg += "' is not a number.\n\n";
          throw std::runtime_error(errMsg);
        }
      }
      // Check already when reading values, so we don't have problems later
      if (columnCounter != m_numDims)
      {
        std::string errMsg("\n\n***** ERROR: mkmpNS::PointManager::loadPointValues() Number of columns != numDims.\n\n");
        throw std::runtime_error(errMsg);
      }
    } // if (not comments)
  } // while loop
  
  // Check if we read anything
  if (m_pointValues.size() == 0)
  {
    std::string errMsg("\n\n***** ERROR: mkmpNS::PointManager::loadPointValues() we didn't read any values.\n\n");
    throw std::runtime_error(errMsg);
  }
}