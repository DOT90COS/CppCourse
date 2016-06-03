#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

/*
All comparitors comp(a,b):

* For all a, comp(a,a) == false
* If comp(a,b) == true, then comp(b, a) == false
* If comp(a,b) == true and comp(b,c) == true, then comp(a,c) == true

*/

//Less typing! :)
using uint = unsigned int; // == typedef unsigned int uint;

void printVec(const std::vector<uint>& vec)
{
    bool first = true;
    for (auto item : vec)
    {
        first ? std::cout << item : std::cout << ", " << item;
        first = false;
    }
    std::cout << "\n";
}


int main()
{
    const std::vector<uint> dataset = { 10,2,2503,3,5,64,4095,9086,12402,0xDEADBEEF,0765432,9 };

    //Pass a lambda into sort that will put these in increasing order
    std::cout << "Increasing order: \n";
    auto increasingOrder(dataset); //a copy
    std::sort(increasingOrder.begin(), increasingOrder.end(), /*LAMBDA GOES HERE*/);
    printVec(increasingOrder);

    //Pass a lambda into sort that will put these in decreasing order
    std::cout << "Decreasing order: \n";
    auto decreasingOrder(dataset);
    std:First.begin(), evenFirst.end(), evenOverOdd);
    printVec(evenFirst);

    //all odd numbers infront of even ones and inside of both of those sets the numbers are sorted.
    std::cout << "Increasing Odd First: \n";
    auto increasingOddFirst(dataset);
    auto oddOverEvenIncrease =  /*You may reuse your lambdas from above inside this one. Just think about how you access them*/;
    std::sort(increasingOddFirst.begin(), increasingOddFirst.end(), oddOverEvenIncrease);
    printVec(increasingOddFirst);

    //All even numbers infront of odd ones and inside of both of those sets the numbers are sorted.
    std::cout << "Increasing Even First: \n";
    auto increasingEvenFirst(dataset);
    auto evenOverOddIncrease =  /*The inverse of above*/;
    std::sort(increasingEvenFirst.begin(), increasingEvenFirst.end(), evenOverOddIncrease);
    printVec(increasingEvenFirst);

    return 0;
}