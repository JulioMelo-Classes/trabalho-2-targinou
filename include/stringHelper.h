#ifndef STRING_HELPER_H
#define STRING_HELPER_H

#include <vector>
#include <string>

class StringHelper
{
    public:
    	/*! Metodo para converter uma linha de ids(string) para um vetor de ints
				@param linha com ids.
				@param string de espaço.
				@return um array com ids.
		*/
        static std::vector<int> splitLine(std::string line, std::string delim);
};

#endif