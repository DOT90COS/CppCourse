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
// You can use this like a normal funciton sub(1,2) = -1...
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

    workQueue.push_back( ); //Use add above to add 2 
    workQueue.push_back( ); //Use a lambda to add 10
    workQueue.push_back(); //Use the sub functor to sub 7;
    workQueue.push_back(); //Use a lambda to multiply by 10;

    std::cout << "Processing 100: " << processWork(workQueue, 100) << "\n";
}