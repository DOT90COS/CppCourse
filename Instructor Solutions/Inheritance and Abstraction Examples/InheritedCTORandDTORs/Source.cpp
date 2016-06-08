#include <iostream>

class Base {
    int x_ = 0;
public:
    Base() = default;
    Base(int x) :x_{ x } {}
    virtual ~Base() { std::cout << "Base DTOR\n"; }
};

class Derived : Base {
    int y_ = 0;
public:
    Derived() = default;
    Derived(int x, int y) :Base(x), y_(y) {}
};

void foo() {
    Base b1; 
    Derived d1;
    return;
}

int main() {
    foo();
}
