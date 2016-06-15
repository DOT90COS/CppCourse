#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>

void print_vector(const std::vector<int>& vec)
{
    bool first = true;
    for (auto item : vec)
    {
        first ? std::cout << item : std::cout << ", " << item;
        first = false;
    }
    std::cout << "\n";
}

int main()
{
    std::function<void()> foo = []() {};

    std::vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
    std::transform(vec.begin(), vec.end(), vec.begin(), std::bind(std::multiplies<int>(), std::placeholders::_1, 2));

    std::vector< std::function<void()> > function_queue = { std::bind(print_vector, vec),[]() {std::cout << "\n"; }, [&vec]() {print_vector(vec); } };
    print_vector(vec);

    return 0;
}
