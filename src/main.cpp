#include <iostream>
#include "mkmp.hpp"



int main(int argc, char *argv[])
{
  // Check input 
  if(argc != 3)
  {
    std::cout << "*****\n";
    std::cout << "Usage: mkmp <num dimensions> <input file name>\n";
    std::cout << "*****\n";
  } 
  else
  {
    const int numDims{atoi(argv[1])};
    mkmpNS::MKMP mkmpObject{numDims, argv[2]};
    mkmpObject.executeSolver();
    mkmpObject.storeResults();
  }
}