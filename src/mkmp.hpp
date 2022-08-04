#include <vector>
#include <string>


namespace mkmpNS
{
  class MKMP
  {
    public:
      MKMP(const int numDims, const std::string filename);

      ~MKMP(){};

      void executeSolver();
      
      void storeResults();

    private:
      const int m_numDims;
      std::vector<double> m_pointData;
  };
}