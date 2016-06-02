#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>

template<class T> 
T to(const std::string& from)
{
    std::stringstream ss(from);
    T ret;
    ss >> ret;
    return ret;
}

int random(int max = std::numeric_limits<int>::max()) 
{ //Horrible random number generator
    static bool firstTime = true;
    if(firstTime) std::srand(time(NULL));
    firstTime = false;
    uint32_t randNum = rand();
    randNum <<= 16;
    randNum |= rand();
    return randNum%max;
}

int main(int argc, char* argv[])
{
    if (argc != 3) //Check for proper arguments. 
    {
        std::cerr << "Usage: " << argv[0] << "<Max Elements> <OUTPUT FILE>\n";
        return 0;
    }

    std::string filename = argv[2];
    std::string maxNumStr = argv[1];
    auto numElements{ random(to<int>(maxNumStr)) };
    std::vector<int> data(numElements);
    for (auto& elem : data)
        elem = random();

    std::ofstream outFile(filename, std::ios::trunc);
    if (outFile)
    {
        auto end = data.end() - 1;
        for (auto itr = data.begin(); itr != end; ++itr)
            outFile << *itr << ", ";
        outFile << *end;
        return 0;
    }
    std::cerr << "Can't write to file.\n";
}