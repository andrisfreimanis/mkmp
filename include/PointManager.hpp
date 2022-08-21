#pragma once

#include <vector>

#include "helper.hpp"

namespace mkmpNS
{
  //struct ParamStruct;

  class PointManager
  {
    public:
      PointManager() = default;

      PointManager(mkmpNS::ParamStruct& params);

      ~PointManager(){};

      void loadPointValues();

      const std::vector<double>* getPointValues() {return &m_pointValues;};

    private:
      bool isNumber(const std::string& str) const {return str.find_first_not_of("-+e.0123456789") == std::string::npos;};

      int m_numDims;
      int m_numPoints;
      char m_delimiter{' '};
      std::string m_pointFile;
      std::vector<double> m_pointValues;
  };
}