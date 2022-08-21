#include <iostream>
#include "mkmp.hpp"



int main(int argc, char *argv[])
{
  // Check input 
  if(argc != 2)
  {
    std::cout << "\n*****\n";
    std::cout << "Usage: mkmp <input file name>\n";
    std::cout << "*****\n\n";
  } 
  else
  {
    try
    {
      mkmpNS::MKMP mkmpObject{argv[1]};
      mkmpObject.executeAlgorithm();
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }
}