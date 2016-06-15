#include <iostream>
#include <type_traits>
#include <functional>

int foo(int x/* = 1*/, int /*y = 2*/)
{
    std::cout << "foo 1\n";
    return 1;
}

int foo(int x/* = 1*/)
{
    std::cout << "foo 2\n";
    return 2;
}

int foo()
{
    std::cout << "foo 3\n";
    return 3;
}

auto foobar(int x)
{
    return x;
}

//does foobar return a int or double??
auto foobar(int x, double y) //-> double
{
    return static_cast<double>(x) > y ? x : y; // returns int no warning
}

int foobar2(int x, double y)
{
    return static_cast<double>(x) > y ? x : static_cast<int>(y); // returns int with a warning
}

double foobar3(int x, double y)
{
    return static_cast<double>(x) > y ? x : y; // returns double no need for a warning. 
}

/* This might be allowed in C++17 there is a proposal for generic functions
int bar(auto x)
{
    std::cout << x << "\n";
}
*/

void cat(int x, int y = 1)
{
    std::cout << "cat1\n";
}

void cat(int x = 2)
{
    std::cout << "cat2\n";
}

void fn(std::function<int()> f)
{
    std::cout << "fn: " << f() << "\n";
}

int main()
{
    //cat(2);

    foo(1, 2);
    foo(1);
    foo();

    std::cout << "foobar(4): " << foobar(4) << std::endl;
    std::cout << "foobar(4, 5.0): " << foobar(4) << std::endl;
    std::cout << std::boolalpha;
    std::cout << "foobar(4, 5.0) is_integer: " << std::is_integral<decltype(foobar(4))>::value << "\n";
    std::cout << "foobar(4, 5.0) is_float: " << std::is_floating_point<decltype(foobar(4))>::value << "\n";
    std::cout << std::noboolalpha;


    fn([]() {return 4; });

    return 0;
}