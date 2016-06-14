#include "Test.h"

void buildAndKillTest()
{
    Test one(); //Calls CTOR
} //Calls DTOR out of scope.

int main()
{
    buildAndKillTest();

    return 0;
}