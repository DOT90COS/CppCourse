#include <functional>


int foo(double x, int y) {
    return y;
}

struct foo_functor_type {
    int operator()(float x, short y) { return y; }
};
foo_functor_type foo_functor;

int bar(int a, int b)
{
    return a / b;
}

int main()
{
    std::function<int(double, int)> fn = foo;
    
    //This will cause a warning but a double is convertable to a float and 
    //an int is convertable to a short, so it compiles... 
    //but it is a narrowing conversion and would be considered evil
    fn = foo_functor; 

    auto fun = std::bind(bar, std::placeholders::_2, std::placeholders::_1);
    auto fun2 = [](int a, int b) {return bar(b, a); };
}