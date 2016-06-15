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

    std::cout << "Increasing order: \n";
    auto increasingOrder(dataset); //a copy
    std::sort(increasingOrder.begin(), increasingOrder.end(), [](uint a, uint b) {return a < b; });
    printVec(increasingOrder);

    std::cout << "Decreasing order: \n";
    auto decreasingOrder(dataset);
    std::sort(decreasingOrder.begin(), decreasingOrder.end(), [](uint a, uint b) {return a > b; });
    printVec(decreasingOrder);

    std::cout << "Odd First: \n";
    auto oddFirst(dataset);
    auto oddOverEven = [](uint a, uint b) {
        return (a % 2 == 1 && b % 2 == 0);
    };
    std::sort(oddFirst.begin(), oddFirst.end(), oddOverEven);
    printVec(oddFirst);
    
    std::cout << "Even First: \n";
    auto evenFirst(dataset);
    auto evenOverOdd = [](uint a, uint b) {
        return (a % 2 == 0 && b % 2 == 1);
    };
    std::sort(evenFirst.begin(), evenFirst.end(), evenOverOdd);
    printVec(evenFirst);
    
    std::cout << "Increasing Odd First: \n";
    auto increasingOddFirst(dataset);
    auto oddOverEvenIncrease = [&oddOverEven, &evenOverOdd](uint a, uint b) 
    {
        return (oddOverEven(a, b) ? true : (evenOverOdd(a,b) ? false : a < b));
    };
    std::sort(increasingOddFirst.begin(), increasingOddFirst.end(), oddOverEvenIncrease);
    printVec(increasingOddFirst);
   
    std::cout << "Increasing Even First: \n";
    auto increasingEvenFirst(dataset);
    auto evenOverOddIncrease = [&oddOverEven, &evenOverOdd](uint a, uint b) 
    {
        return (evenOverOdd(a, b) ? true : (oddOverEven(a,b) ? false : a < b));
    };
    std::sort(increasingEvenFirst.begin(), increasingEvenFirst.end(), evenOverOddIncrease);
    printVec(increasingEvenFirst);

    return 0;
}