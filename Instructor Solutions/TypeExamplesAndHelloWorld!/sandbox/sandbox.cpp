// sandbox.cpp : Defines the entry point for the console application.
//
#include <memory>
#include <iostream>

struct myType
{
    int a; //4 byte
    double c; //8 bytes
}; //16 byte

enum class light : char { red = 'r', yellow = 'y', green = 'g'};
enum class color : int {red, yellow, green, purple };

auto i = 20'000;

void foo(std::unique_ptr<int> bar)
{
    std::cout << "Bar: " << *bar << std::endl;
}

void foo(int* bar)
{
    std::cout << "Bar: " << *bar << std::endl;
}

int main()
{
    light myLight = light::red;

    auto bar = std::make_unique<int>(0);
    foo(bar.get());
    foo(std::move(bar));


    return 0;
}











