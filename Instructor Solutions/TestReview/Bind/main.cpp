#include <functional>
#include <vector>
#include <iostream>
#include <type_traits>

template<typename T>
void accumulate(typename const T::iterator& begin, typename const T::iterator& end, 
    typename T::value_type thing)
{
    for( auto itr = begin; itr != end; ++ itr)
        *itr += thing;
}

template <typename T>
void accumulate(T* begin, T*end, const T& thing)
{
    for (auto ptr = begin; ptr != end; ++ptr)
        *ptr += thing;
}

template <typename T1, typename T2>
void foo(T1 foo1, T2 foo2) {

    std::cout << "T1 and T2\n";
}

template<typename T1>
void foo(T1 foo1, int foo2) {
    std::cout << "T1\n";
}

void foo(int foo1, int foo2) {
    std::cout << "Not generic\n";
}

int sub(int a, int b)
{
    return a - b;
}

struct foobar {

};


int main()
{
    std::cout << "Is foobar is_class: " << std::boolalpha <<
        std::is_class<foobar>::value << "\n";

    auto subtraction = std::bind(sub, std::placeholders::_2, 5);
    subtraction(10, 2); //-3

    //Same as line above
    auto subtractlambda = [](int x, int y) {return sub(y, 5); }; 
    subtractlambda(10, 2); //-3

    auto sub3 = std::bind(sub, 5, std::placeholders::_1);
    sub3(7); //-2

    auto sub4 = std::bind(sub, std::placeholders::_4, std::placeholders::_5);
    sub4(1, 2, 3, 4, 5); //-1

    //crazy will not be on test. 
    auto sub2 = [](int a, int b, int c, int d, int e) {return sub(sub(sub(sub(a, b), c), d), e); };



    foo(1, 1); //Not generic
    foo(1, 1.0); //T1 and T2
    foo(1.0, 1); //T1
    foo(1.0, 1.0); //T1 and T2

    auto bound = std::bind(foo<double>, std::placeholders::_1, 0);
    bound(1.0); //T1
    bound('c'); //T1
    bound(1); //T1 class: not generic

    auto lambda = [](int x) {foo(1, x); };
    lambda(1);
    lambda(1.0);
    lambda('x');
}
