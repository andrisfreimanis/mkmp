#pragma once

#include <string>

namespace mkmpNS
{
  struct ParamStruct
  {
    int numDims{};
    int outputFrequency{};
    char delimiter{' '};
    std::string pointFile{};
  };
}

