#include <vector>
#include <string>

namespace mkmpNS
{
  class InputBase
  {
    public:
      InputBase(const std::string filename) : m_filename{filename}{};

      virtual ~InputBase(){};

      virtual void getPointValues(const int numDims, const std::vector<double> &pointValues) const = 0;
    
    protected:
      const std::string m_filename; 
  };
}