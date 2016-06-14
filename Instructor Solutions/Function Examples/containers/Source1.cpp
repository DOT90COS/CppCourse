#include <functional>

int add(int a, int b, int c = 0, int d = 0)
{
    return a + b + c + d;
}

int divide(int a, int b)
{
    return a / b;
}


int main()
{
    auto boundAdd = std::bind(add, 5, std::placeholders::_1, 0, 0);
    auto lambdaBound = [](int a) {return add(5, a); };
    boundAdd(1);
    boundAdd(2);
    lambdaBound(1);
    lambdaBound(2);
  
    auto screwedUpDiv = std::bind(divide, std::placeholders::_2, std::placeholders::_1);
    divide(2, 10);
    screwedUpDiv(2, 10);
   

}