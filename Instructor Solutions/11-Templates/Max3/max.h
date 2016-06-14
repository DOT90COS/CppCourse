#pragma once

/***************************************************************
Given a container of numbers. I.E. the constructor will take any
container with any kind of numbers.

Max will include public member functions to compute:
* The Max number in the container (name this function getMax())
* The Min number in the container (name this function getMin())
* The Mean number in the container (name this function double getMean())
* To return the numbers sorted in the same container.  (name this function getSorted()). 

Bonus:
Go learn about enable_if and try to only make this class work with stl containers.
If the type passed in isn't a container use static_asserts to print a nice error message.
Use your BIGNUM class. 
***************************************************************/
#include <set>

template<typename T>
class Max {
    std::multiset<typename T::value_type> data_;

public:
    Max(const T& thing) :data_(thing.begin(), thing.end()) {}
    typename T::value_type getMax() { return *data_.rbegin(); }
    typename T::value_type getMin() { return *data_.begin(); }
    double getMean() {
        double total = 0;
        for (auto& x : data_)
            total += x;
        return total / data_.size();
    }
    T getSorted() { return T(data_.begin(), data_.end()); }
};