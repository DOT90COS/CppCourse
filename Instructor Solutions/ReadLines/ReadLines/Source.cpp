#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 2)
        std::cerr << "USAGE: " << argv[0] << " <FILENAME>\n";

    std::string filename = argv[1];
    std::ifstream inFile(filename);
    std::string line;
    while(std::getline(inFile, line))
    {
        std::cout << line << "\n";
    }

    return 0;
}