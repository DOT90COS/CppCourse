#include <iostream>
#include <fstream>
//Add container headers that you want to use here
#include <string>
#include <vector>
#include <random>
#include <limits>
////////////////////////////////////////////////

/**************************************************
Write an application that will:
generate random numbers for the Max 2 application. 

* You program should take 2 parameters
  * 1st - the max number of numbers
  * 2nd - the filename to output to

Not allowed to use any arrays only STL containers

***EXTRA BONUS 
* utilize the random functions in <random>
* Take commandline options so that
  * the generator only generates random negative numbers
  * so the largest number is the last element
  * so the largest number is the first element

***************************************************/
inline int random()
{
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> distribution(std::numeric_limits<int>::min(), 
                                                    std::numeric_limits<int>::max());
    return distribution(generator);
}

std::vector<int> generateNums(int count)
{
    std::vector<int> nums;
    for (auto i = 0U; i < count; ++i)
    {
        nums.push_back(random());
    }
    return nums;
}

void writeToFile(const std::vector<int>& nums, const std::string& filename)
{
    std::ofstream outFile(filename);

    bool first = true;
    for (auto num : nums)
    {
        if (first && outFile)
            outFile << num;
        else if (outFile)
            outFile << ", " << num;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3)
        std::cerr << "USAGE: " << argv[0] << " <NUMBER OF NUMBERS> <OUTPUT FILENAME>\n";

    int count = std::stoi(argv[1]);
    std::string filename = argv[2];

    auto nums = generateNums(count);
    writeToFile(nums, filename);
}