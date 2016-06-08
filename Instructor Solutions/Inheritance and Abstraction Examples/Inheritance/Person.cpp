#include "Person.h"
#include <ostream>

Person::Person(std::string first_name, std::string last_name):first_name_(first_name), last_name_(last_name), birthday_(std::chrono::system_clock::now())
{   
}

Person::~Person()
{
}

void Person::setBirthday(int year, int mon, int day, int hour, int min, int sec)
{
    birthday_ = mytime::makeTimePoint(year, mon, day, hour, min, sec);
}

std::string Person::getBirthday() const
{
    return mytime::asString(birthday_);
}

std::string Person::getFirstName() const { return first_name_; }
std::string Person::getLastName() const { return last_name_; }
std::string Person::getName() const
{
    std::stringstream ss;
    ss << first_name_ << " " << last_name_;
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << p.getName() << " born on: " << p.getBirthday();
    return os;
}