#pragma once

#include <string_view>

#include "PointManager.hpp"
#include "OutputManager.hpp"


namespace mkmpNS
{
  struct ParamStruct
  {
    int numDims{};
    char delimiter{' '};
    std::string pointFile{};
  };

  class MKMP
  {
    public:
      MKMP(const std::string inputFile);

      ~MKMP(){};

      void executeSolver();
      
      void storeResults();

    private:
      void buildParamList(const std::string inputFile);

      ParamStruct m_paramList;
      PointManager m_pointManager;
      OutputManager* m_outputManager;
  };
}