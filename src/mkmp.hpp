#include <vector>
#include <string_view>


namespace mkmpNS
{
  class MKMP
  {
    public:
      MKMP(const int numDims, const std::string_view filename);

      ~MKMP(){};

      void executeSolver();
      
      void storeResults();

    private:
      const int m_numDims;
      std::vector<double> m_pointData;
  };
}