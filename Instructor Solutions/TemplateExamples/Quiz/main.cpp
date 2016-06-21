#include <iostream>

class Bar {
    int x_ = 0;

public:
    Bar(int a) :x_(a) { std::cout << "constructor 1\n";}
    Bar() = default;
    Bar(const Bar& n) { std::cout << "constructor 3\n"; }
    Bar(const std::initializer_list<int>& a) { std::cout << "constructor 4\n"; }
};

int main()
{
    Bar a{ 0 };
    Bar x(0);
    Bar y(a);
    Bar b = { 0 };
    Bar c = { 1,2,3 };

    return 0;
}