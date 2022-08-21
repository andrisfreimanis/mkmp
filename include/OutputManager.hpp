#pragma once

#include "helper.hpp"

namespace mkmpNS
{
  class OutputManager
  {
    public:
      OutputManager() = default;

      OutputManager(mkmpNS::ParamStruct& params);

      void outputCurrentStep(const int step,
                             const std::vector<int>& pointClusterIds,
                             const std::vector<double>& clusterCentroidCoords);

    private:
      int m_outputFrequency;
      int m_numDims;
  };
}