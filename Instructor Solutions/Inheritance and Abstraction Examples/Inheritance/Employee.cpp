#include "Employee.h"

Employee::Employee(std::string first, std::string last, int employeeNumber):Person(first, last), employeeNumber_(employeeNumber)
{
}

Employee::~Employee()
{
}

int Employee::getEmployeeNumber() const { return employeeNumber_; }

void Employee::getEmployeeNumber(int num) { employeeNumber_ = num; }
std::ostream& operator<<(std::ostream& os, const Employee& p)
{
    os << "ID: " << p.getEmployeeNumber() << " Name: " << p.getName() << " born on: " << p.getBirthday();
    return os;
}