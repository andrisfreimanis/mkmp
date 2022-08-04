#include <vector>
#include <string>

namespace mkmpNS
{
  class InputBase
  {
    public:
      InputBase() : m_filename{} {};

      virtual ~InputBase(){};

      virtual void getPointValues(const int numDims, std::vector<double> &pointValues) const = 0;
    
    protected:
      std::string m_filename; 
  };
}