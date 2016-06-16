#pragma once
#include <string>

class Person {
    std::string first_name_;
    std::string last_name_;
    int age_;

public:
    Person(const std::string first,
        const std::string last,
        int age) :first_name_(first),
        last_name_(last), age_(age) {}
    std::string getFirst() const;
    std::string getLast() const;
    int age() const;
};