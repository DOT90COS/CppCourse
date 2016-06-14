#include <iostream>
#include <fstream>
#include <utility>
#include <string>

class Widget1
{
public:
    Widget1() { std::cout << "Widget1 Default Constructor\n"; }
    Widget1(int a) :a_(a) { std::cout << "Widget1 int constructor\n";  }
    int a() { return a_; }
private:
    int a_ = 1;
};

class Widget2
{
public:
    Widget2() { std::cout << "Widget2 Default Constructor\n"; }
    Widget2(int a) :a_(a) { std::cout << "Widget2 int constructor\n";}
    Widget2(std::initializer_list<int> li)
    {
        std::cout << "Widget2 Initializer list\n";
    }
    Widget2(const Widget2& n)
    {
        std::cout << "Widget2 copy constructor\n";
    }
    int a() { return a_; }
private:
    int a_ = 1;
};

class Widget3
{
    int i_;
    bool b_;

public: 
    Widget3(int i, bool b) :i_(i), b_(b) {}
    Widget3(std::initializer_list<long double> il) { i_ = *il.begin(); }
};

int main()
{
    auto a = { 1,2,3 };
    auto b = Widget1{ 1 };
    auto c = Widget2{ 1 };
    Widget1 d{};
    Widget2 e{};
    Widget2 f{ e }; //copy
    Widget2 g{ 1 };
    Widget2 h{ 1,2,3,4 };
    Widget2 i(20); //The only way to call the Widget2 int constructor.

    Widget3 w1{ 4, true };
    auto foo = Widget3{ w1 };
    Widget3 w2{ 1, 2 };
    Widget3 w3{ 1.2, 3.4 };
    Widget3 w4{ w1 }; //copy
    return 0;
}