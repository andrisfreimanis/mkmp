#pragma once

#include <string>

#include "helper.hpp"
#include "PointManager.hpp"
#include "OutputManager.hpp"


namespace mkmpNS
{
  class MKMP
  {
    public:
      MKMP(const std::string inputFile);

      ~MKMP(){};

      void executeAlgorithm();
      
    private:
      void buildParamList(const std::string inputFile);

      ParamStruct m_paramList;
      PointManager m_pointManager;
      OutputManager m_outputManager;
  };
}