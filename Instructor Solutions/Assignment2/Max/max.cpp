#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <limits>
constexpr int k_maxValues = 256;

void readInValues(int values[k_maxValues], const std::string& filename)
{
    std::ifstream inFile(filename);
    if (inFile)
    {
        char delim;
        inFile >> values[0];
        for (auto i = 1U; i < k_maxValues  && inFile; ++i)
        {
            inFile >> delim >> values[i];
        }
        
        return;
    }
    throw std::runtime_error("Can't open file to read");
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "USAGE: " << argv[0] << " <INPUT FILENAME>\n";
        return 0;
    }

    std::string filename = argv[1];
    int values[k_maxValues] = { 0 };

    try
    {
        readInValues(values, filename);
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << "\n";
        return -1;
    }

    //auto max = static_cast<int>(0x7FFFFFFF) + 1;
    auto max = std::numeric_limits<int>::min();
    for (auto elem : values)
    {
        max = max < elem ? elem : max;
    }

    std::cout << "Max: " << max << "\n";
}











