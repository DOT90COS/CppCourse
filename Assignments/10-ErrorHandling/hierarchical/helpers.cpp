#include "helpers.h"

//Taken from: http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
std::string trim(const std::string& str,
    const std::string& whitespace)
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}