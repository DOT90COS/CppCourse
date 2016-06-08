#include "Person.h"
#include "Employee.h"
#include <iostream>

void printPeople(const Person& person)
{
    std::cout << person << std::endl;
}

void printEmployee(const Employee& e)
{
    std::cout << e << std::endl;
}

int main()
{
    Person me{ "Jeff", "Scaparra" };
    me.setBirthday(1984, 2, 25, 3, 34);

    printPeople(me);

    Employee aaron{"Aaron", "Bray", 42 };
    aaron.setBirthday(1987, 3, 2, 10, 30);

    printPeople(aaron);
    printEmployee(aaron);

    return 0;
}