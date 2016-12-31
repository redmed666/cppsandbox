#include "util/util.hpp"

namespace Util{
    std::vector<std::string> parseString(std::string input, char separator) {
        std::stringstream iss(input);
        std::vector<std::string> v_input_parsed;
         while(iss.good())
         {
             std::string SingleLine;
             getline(iss,SingleLine, separator);
             v_input_parsed.push_back(SingleLine);
         }
         return v_input_parsed;
    }
}
