#pragma once
#include "Person.h"
class Employee :
    public Person
{
    int employeeNumber_;
public:
    Employee(std::string first, std::string last, int employeeNumber);
    ~Employee();

    int getEmployeeNumber() const;

    void getEmployeeNumber(int num);
};

std::ostream& operator<<(std::ostream& os, const Employee& p);