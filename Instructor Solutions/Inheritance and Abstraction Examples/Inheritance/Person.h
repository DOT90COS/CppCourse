#pragma once
#include <string>
#include "timepoint.h"

class Person
{
    std::string first_name_;
    std::string last_name_;
    std::chrono::system_clock::time_point birthday_;

public:
    Person(std::string first_name, std::string last_name);
    ~Person();

    void setBirthday(int year, int mon, int day, int hour = 0, int min = 0, int sec = 0);

    std::string getBirthday() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getName() const;
};

std::ostream& operator<<(std::ostream& os, const Person& p);