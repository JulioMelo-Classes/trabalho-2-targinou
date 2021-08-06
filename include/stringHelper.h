#ifndef STRING_HELPER_H
#define STRING_HELPER_H

#include <vector>
#include <string>

class StringHelper
{
    public:
        static std::vector<int> splitLine(std::string line, std::string delim);
};

#endif