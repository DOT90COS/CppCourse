#include "Date.h"
#include <iostream> 

int main()
{
    Date date1(Day{ 25 }, Month{ 2 }, Year{ 1984 });
    Date date2(Day{ 7 }, Month{ 6 }, Year{ 2016 });

    std::cout << "Jeff was born on " << date1 << ".\n";
    std::cout << "Jeff is " << date2 - date1 << "days old!\n";
}