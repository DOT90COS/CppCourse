#include <iostream>
#include <deque>
#include <functional>
#include <utility>
/********************************************************************
Your Assignment 

In the main function:
* Convert all std::bind to use lambdas
* Convert all lambdas to use std::bind
**********************************************************************/

using WorkQueue = std::deque<std::function<int(int)>>;

int processWork(WorkQueue queue, int start)
{
    for (auto fun : queue)
    {
        start = fun(start);
    }
    return start;
}

int add(int a, int b)
{
    return a + b;
}

int abs(int a)
{
    return a < 0 ? -a : a;
}

int sub(int a, int b)
{
    return a - b;
}

int power(int a, int b)
{
    int tmp = a;
    for (int i = 0; i < b; i++)
        tmp *= a;
    return tmp;
}

int divide(int a, int b)
{
    return a / b;
}

int mod(int a, int b)
{
    return a % b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    WorkQueue workQueue; //A work queue that stores functions that take an int and return an int.

    workQueue.push_back(std::bind(add, 2, std::placeholders::_1)); //Use add above to add 2 
    workQueue.push_back(std::bind(divide, 1000, std::placeholders::_1)); //divided 1000 by x
    workQueue.push_back(std::bind(power, 2, std::placeholders::_1)); //2 ^x
    workQueue.push_back(std::bind(mod, std::placeholders::_1, 0xF));
    workQueue.push_back([](int a) {return multiply(a, 100); });
    workQueue.push_back([](int a) {return divide(0xDEAD, a); });

    std::cout << "Processing 100: " << processWork(workQueue, 100) << "\n";  //should print 142
    std::cout << "Processing 1000: " << processWork(workQueue, 1000) << "\n"; //should print 285
    return 0;
}













