#pragma once
#include "Person.h"
#include <iostream>
//Overload the ostream operator for a person so that it prints out like
// "Jeff Scaparra, Age: 32"

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.getFirst() << " " << p.getLast() << ", Age: " << p.age();
    return os;
}


//put the definition in the .cpp

// write a lambda to use as a comparitor that when used in sort below we sort 
// from lowest to highest age of the person. 

auto increasingAge = [](const Person& a, const Person& b) {
    return a.age() < b.age(); 
};

// write a lambda that will be used as a comparitor to sort by last name 

auto increasingLastName = [](const Person& a, const Person& b) {return a.getLast() < b.getLast(); };

template <typename T>
void sortByLastName(T& people) {
    std::sort(people.begin(), people.end(), increasingLastName);
}

template <typename T>
void sortByAge(T& people) {
    std::sort(people.begin(), people.end(), increasingAge);
}