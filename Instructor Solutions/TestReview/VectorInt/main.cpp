#include "VectorInt.h"
#include <iostream>
#include <algorithm>



int main()
{
    VectorInt numbers;
    numbers.push_back(5);
    numbers.push_back(5);
    numbers.push_back(42);
    numbers.push_back(6);

    for (auto x : numbers)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}


















/*
void foo(VectorInt i)
{
    for (auto& x : i)
    {
        std::cout << x << ' ';
    }
    std::cout << "\n";
}

int main()
{
    VectorInt v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    std::cout << "sizeof v: " << v.size() << "\n";
    for (auto& x : v)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";

    //foo(v);

    return 0;
}*/