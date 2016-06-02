
#include "typeInspection.h"
#include <vector>
#include <string>

void userDefinedTypes()
{
    printInfo(R"](std::string("This is a standard string"))]", std::string("This is a standard string"));
    printInfo("std::vector<int>(10, 1)", std::vector<int>(10, 1));
}