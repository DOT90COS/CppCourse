#include "typeInspection.h"
#include <vector>
#include <memory>

void pointerTypes()
{
    //pointer types
    void* voidPtr = nullptr;
    int* intPtr = nullptr;
    std::vector<int>* vectorIntPtr = nullptr;
    std::unique_ptr<int> uniqueIntPtr; //defaults to nullptr
    double* doublePtr = new double();
    *doublePtr = 55.22;


    std::cout << "##############################################################\n";
    std::cout << " Pointer Types:\n";
    std::cout << "##############################################################\n";
    printInfo("nullptr", nullptr);
    printInfo("voidPtr", voidPtr);
    printInfo("intPtr", intPtr);
	printInfo("std::move(uniqueIntPtr)", std::move(uniqueIntPtr));
    printInfo("doublePtr", doublePtr);
}