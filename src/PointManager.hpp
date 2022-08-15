#pragma once

#include <vector>
#include <string_view>

#include "helper.hpp"

namespace mkmpNS
{
  struct ParamStruct;

  class PointManager
  {
    public:
      PointManager() = default;

      PointManager(mkmpNS::ParamStruct& params);

      ~PointManager(){};

      void loadPointValues();

      const std::vector<double>* getPointValues() {return &m_pointValues;};
    
    private:
      int m_numDims;
      char m_delimiter{' '};
      std::string m_pointFile;
      std::vector<double> m_pointValues;
  };
}