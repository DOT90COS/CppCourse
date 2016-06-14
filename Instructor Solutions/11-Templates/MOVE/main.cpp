#include <memory>
#include <iostream>
#include <Windows.h>
#include <functional>
template<typename T> 
void foo(std::unique_ptr<T> something)
{
    std::cout << "Hello from foo\n";
}

template <typename T>
void foo2(std::unique_ptr<T>&& something)
{
    std::cout << "Hello from foo2\n";
}

int main()
{
    std::unique_ptr<int> thing(new int(42)); //The meaning of life. 
    auto ptr = thing.release();
    auto intPtr = std::make_unique<int>(0);
    //foo(std::move(intPtr));
    foo2(std::move(intPtr));
    foo2(std::make_unique<int>(40));
    foo2(std::unique_ptr<int>());



    return 0;
}
