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
***************************************************************/

template<typename T>
class Max {

public:
    Max(const T& thing);

};