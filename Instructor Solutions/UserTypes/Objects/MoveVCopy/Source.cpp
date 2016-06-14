#include <iostream>
#include <memory>

class X
{
    int* v_;
    int size_;

public:
    X() :v_(new int[42]), size_(42) { std::cout << "Default construction\n"; }
    X(const X& n) :v_(new int[n.size_]), size_(n.size_)
    {
        std::cout << "Copy Construction\n";
        for (auto i = 0U; i < size_; ++i)
            v_[i] = n.v_[i];
    }
    X(X&& n) :v_(n.v_), size_(n.size_) { std::cout << "Move Construction\n"; n.v_ = nullptr; }
    ~X() { std::cout << "DTOR\n"; if (v_) delete[] v_; }
};

void test()
{
    std::cout << "Define x1\n";
    X x1;
    std::cout << "Define x2\n";
    X x2{ x1 };
    std::cout << "Define x3\n";
    X x3{ std::move(x1) };
}

int main()
{
    test();

    return 0;
}