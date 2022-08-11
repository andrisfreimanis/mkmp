#pragma once

#include <string>

namespace mkmpNS
{
  struct ParamStruct
  {
    int numDims{};
    char delimiter{' '};
    std::string pointFile{};
  };
}