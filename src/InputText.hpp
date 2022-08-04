#include <vector>
#include <string_view>

#include "InputBase.hpp"


namespace mkmpNS
{
  class InputText : public InputBase
  {
    public:
      InputText(const std::string_view& filename);

      virtual ~InputText();

      virtual void getPointValues(const int numDims, std::vector<double>& pointValues) const;
    
    private:
      char m_delimiter{' '};
  };
} 