#include <iostream>
#include "mkmp.hpp"



int main(int argc, char *argv[])
{
  // Check input 
  if(argc != 2)
  {
    std::cout << "*****\n";
    std::cout << "Usage: mkmp <input file name>\n";
    std::cout << "*****\n";
  } 
  else
  {
    mkmpNS::MKMP mkmpObject{argv[1]};
    mkmpObject.executeSolver();
    mkmpObject.storeResults();
  }
}