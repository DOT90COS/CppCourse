#include <iostream>
#include <deque>
#include <functional>
#include <utility>

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


// This is a functor...
// You can use this like a normal funciton sub_object(1,2) = -1...
struct sub
{
    int operator()(int a, int b)
    {
        return a - b;
    }
};

int main()
{
    WorkQueue workQueue; //A work queue that stores functions that take an int and return an int.

    workQueue.push_back(std::bind(add, 2, std::placeholders::_1)); //Use add above to add 2 
    //workQueue.push_back([](int a) {return add(2, a); });

    workQueue.push_back([](int a) {return 10 + a; }); //Use a lambda to add 10


    sub subFun;
    workQueue.push_back([&subFun](int a) {return subFun(a, 7); }); //Use the sub functor to sub 7;
    //workQueue.push_back(std::bind(sub(), std::placeholders::_1, 7) );
    //workQueue.push_back([](int a) {return sub()(a, 7); });

    workQueue.push_back([](int a) {return a * 10; }); //Use a lambda to multiply by 10;

    std::cout << "Processing 100: " << processWork(workQueue, 100) << "\n";
}













