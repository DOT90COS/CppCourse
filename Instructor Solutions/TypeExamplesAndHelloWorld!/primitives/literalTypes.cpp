#include "typeInspection.h"

void literalTypes()
{
    std::cout << "##############################################################\n";
    std::cout << " Literal Types:\n";
    std::cout << "##############################################################\n";
    printInfo("1", 1);
    printInfo("1U", 1U);
	printInfo("1L", 1L);
	printInfo("0xFF", 0xFF);
	printInfo("0xFFFF", 0xFFFFF);
	printInfo("0xFFFFFFFF", 0xFFFFFFFF);
	printInfo("0xFFFFFFFFFFFFFFFF", 0xFFFFFFFFFFFFFFFF);
    printInfo("1LLU", 1LLU);
    printInfo("1.2L", 1.2L);
    printInfo("1.2", 1.2);
}
