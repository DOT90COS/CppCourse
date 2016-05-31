#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int toInt(const std::string& number)
{
    int res = 0;
    std::stringstream ss(number);
    ss >> res;
    return res;
}

std::string toString(int a)
{
    std::stringstream ss;
    ss << a;
    return ss.str();
}

int main(int argc, char* argv[])
{
    std::string num = "42?";
    int num42 = toInt(num);
    std::cout << toString(num42) << "\n";
    return 0;
}