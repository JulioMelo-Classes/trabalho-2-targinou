#include "stringHelper.h"

std::vector<int> StringHelper::splitLine(std::string line, std::string delim)
{
  std::vector<int> arrId;
  size_t prev = 0, pos = 0;
  do{
      pos = line.find(delim, prev);
      if (pos == std::string::npos) pos = line.length();
      std::string token = line.substr(prev, pos-prev);
      if (!token.empty()) arrId.push_back(stoi(token));
      prev = pos + delim.length();
  }while (pos < line.length() && prev < line.length());

  return arrId;
}