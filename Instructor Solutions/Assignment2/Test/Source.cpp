#include <iostream>

int main()
{
    int nums[5] = { 1,2,3,4,5 };
    for (auto num : nums)
    {
        num = 0;
        std::cout << num << std::endl;
    }
}