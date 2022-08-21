#include <vector>
#include <fstream>

#include "OutputManager.hpp"

mkmpNS::OutputManager::OutputManager(mkmpNS::ParamStruct& params)
{
  m_outputFrequency = params.outputFrequency;
  m_numDims = params.numDims;
}

void mkmpNS::OutputManager::outputCurrentStep(const int step,
                                              const std::vector<int>& pointClusterIds, 
                                              const std::vector<double>& clusterCentroidCoords)
{
  // Output point cluster Ids
  std::string filename{"pointClusterIds_" + std::to_string(step) + ".csv"};
  std::ofstream ofstream{filename};
  if (!ofstream)
  {
    std::string errMsg{"\n\n***** ERROR: mkmpNS::OutputManager::outputCurrentStep() Couldn't open " + filename + ".\n\n"};
    throw std::runtime_error(errMsg);
  }

  std::string line{};
  size_t counter{0};
  for (auto val : pointClusterIds)
  {
    line += val + " ";
    if (counter == m_numDims)
    {
      line += "\n";
      ofstream << line;
      line = "";
    }
  }
  ofstream.close();

  // Output cluster centroids
  filename = "clusterCentroidCoords.csv";
  ofstream.open(filename);
  if (!ofstream)
  {
    std::string errMsg{"\n\n***** ERROR: mkmpNS::OutputManager::outputCurrentStep() Couldn't open " + filename + ".\n\n"};
    throw std::runtime_error(errMsg);
  }

  line = "";
  counter = 0;
  for (auto val : pointClusterIds)
  {
    line += val + " ";
    if (counter == m_numDims)
    {
      line += "\n";
      ofstream << line;
      line = "";
    }
  }
  ofstream.close();
}