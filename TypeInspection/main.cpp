#include "typeInspection.h"
#include <cstdint>
#include <vector>

struct myType {
    int a;
    double b;
    int foo() { return 5; }
};

void testPrimatives()
{
    PRINT_INFO((signed int)(0));
    PRINT_INFO((uint32_t)(0));
    PRINT_INFO(std::vector<int>(40));
    PRINT_INFO(std::vector<int>(30));
    PRINT_INFO(testPrimatives);
    myType type = { 1,2 };
    printInfo("myType", type);
}

int main()
{
    testPrimatives();
}