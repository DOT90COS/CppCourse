#include <iostream>
#include <fstream>
#include <string>

std::string getName()
{
    std::cout << "What is your name?\n";
    std::string name; 
    std::cin >> name;
    return name;
}

void printName(const std::string& name, std::ostream& os)
{
    os << "Hello, " << name << "!\n";
}

int main(int argc, char* argv[])
{
    std::string name{ getName() };
    std::string filename;
    if (argc > 1)
    {
        filename = argv[1]; //filename
        std::ofstream outFile{ filename };
        printName(name, outFile);
    }
    printName(name, std::cout);
} //implicit return 0;