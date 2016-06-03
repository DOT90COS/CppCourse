#include <functional>

int add(int a, int b)
{
    return a + b;
}
/*
int div(int a, int b)
{
    return a / b;
}
*/

int main()
{
    auto boundAdd = std::bind(add, 5, std::placeholders::_1);
    boundAdd(1);
    boundAdd(2);
 /*   auto screwedUpDiv = std::bind(div, std::placeholders::_2, std::placeholders::_1);
    div(2, 10);
    screwedUpDiv(2, 10);
*/
}