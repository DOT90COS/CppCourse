#include "Person.h"

std::string Person::getFirst() const
{
    return first_name_;
}

std::string Person::getLast() const
{
    return last_name_;
}

int Person::age() const
{
    return age_;
}
