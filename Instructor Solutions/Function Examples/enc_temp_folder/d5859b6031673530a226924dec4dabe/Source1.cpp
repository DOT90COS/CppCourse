#include <functional>

int add(int a, int b)
{
    return a + b;
}

int divide(int a, int b)
{
    return a / b;
}


int main()
{
    auto boundAdd = std::bind(add, 5, std::placeholders::_1);
    boundAdd(1);
    boundAdd(2);
   auto screwedUpDiv = std::bind(divide, std::placeholders::_2, std::placeholders::_1);
    divide(2, 10);
    screwedUpDiv(2, 10);
   

}