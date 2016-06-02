#include <iostream>
#include <functional>
#include "typeInspection.h"

void primitiveTypes();
void portableTypes();
void stringLiterals();
void literalTypes();
void userDefinedTypes();

int main()
{
    std::cout << "##############################################################\n"
	             " Machine Type: " << machine<sizeof(int), sizeof(long), sizeof(int*)>::type << "\n"
                 "##############################################################\n";
	
	primitiveTypes();
    portableTypes();
    stringLiterals();
    literalTypes();
    userDefinedTypes();

    std::cout << "##############################################################\n"
                 " Function Types:\n"
                 "##############################################################\n";
    auto fp = primitiveTypes;
    PRINT_INFO(fp);
    PRINT_INFO(&primitiveTypes);
    PRINT_INFO(portableTypes);
    PRINT_INFO(stringLiterals);
    PRINT_INFO(literalTypes);
    PRINT_INFO(std::function<void()>(userDefinedTypes));
    std::function<void()> fn = userDefinedTypes;
    printInfo("std::function<void()>(fn)", fn); //why doesn't this show up as a function type?

    return 0;
}
