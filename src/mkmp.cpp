#include <iostream>
#include <vector>
#include <string>

#include "mkmp.hpp"

mkmpNS::MKMP::MKMP(const int numDims, const std::string filename)
:m_numDims{numDims}, m_pointData{ }
{
  std::cout << "Num dims: " << m_numDims << "\n";
  std::cout << "Filename is: " << filename << "\n";
}

void mkmpNS::MKMP::executeSolver( )
{
  std::cout << "Execute solver\n";
}

void mkmpNS::MKMP::storeResults( )
{ 
  std::cout << "Store results\n";
}