#include <iostream>
#include <memory>

int foo(int a, double b, char* c)
{
    return a + static_cast<int>(b) + reinterpret_cast<int>(c);
}

int bar(int, double, char*)
{
    std::cout << "This is bar \n";
    return 0;
}

void foobar(std::unique_ptr<int> foo)
{
    std::cout << *foo << std::endl;
}

int main()
{
    auto sptr = std::make_shared<int>(0);
    *sptr = 1;
    auto uptr = std::make_unique<int>(1);
    *uptr = 2;
    foobar(std::move(uptr));
    int (*fp)(int, double, char*) = &foo;
    int (&fr)(int, double, char*) = foo; //function reference! 
    auto auto_fp = foo;
    const auto auto_fp2 = &foo;
    // auto_fp2 = bar;

    fp = &bar;
    //fr = bar; //Error
    auto_fp = bar;

    char chr = 'a';

    auto a = fp(1, 2.0, nullptr);
    auto b = fr(2, 3.14, nullptr);
    auto c = auto_fp(1, 2.0, &chr);

    constexpr int beef = 0xCAFEBEEF;
    constexpr const int& beefref = beef;
    constexpr const int* beefptr = &beefref;
    
    static_assert(beef == beefref && beef == *beefptr, "This would be bad."); //static_asserts happen at compile time. 
    
    return 0;
}