#include <vector>

#include "InputBase.hpp"


namespace mkmpNS
{
  class InputText : public InputBase
  {
    InputText();

    virtual ~InputText();

    virtual void getPointValues(const int numDims, const std::vector<double> &pointValues) const;
  };
}