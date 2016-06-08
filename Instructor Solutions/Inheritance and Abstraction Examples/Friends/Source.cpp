#include <iostream>

class foo
{
    int x_ = 1;

    friend void bar(const foo&);
};

void bar(const foo& f)
{
    std::cout << "f's private x_ is " << f.x_ << "\n";
}

void foobar(const foo& f)
{
//    std::cout << "f's private x_ is " << f.x_ << "\n";
}

int main()
{
    foo f;
    bar(f);
    return 0;
}