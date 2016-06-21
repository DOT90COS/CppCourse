#include <iostream>


int main()
{
    int* ptr1 = new int; //no initialization
    int* ptr2 = new int(20); //initializes to 20
    int* ptr3 = new int[20]; //no initialization
    int* ptr4 = new int[20](); //initializes to 0
    int& ref1 = ptr3[0];
    int& ref2 = ptr3[1];
    int& ref3 = ptr4[0];
    int& ref4 = ptr4[1];

    delete ptr1;
    delete ptr2;
    delete[] ptr3;
    delete[] ptr4;
}