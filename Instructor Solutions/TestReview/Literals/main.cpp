#include <iostream>

int main()
{
    auto mystr = R"qwerty("This is'my' \ string"^c)qwerty";
    auto mystr2 = R"abc(abcdef()(lmnop)abc";
    std::cout << mystr << "\n";
    std::cout << mystr2<< "\n";
}