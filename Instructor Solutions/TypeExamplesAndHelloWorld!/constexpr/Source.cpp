#include <iostream>
#include <limits>

namespace cppcourse //needed as the global namespace gets poluted when limits includes cmath which includes math.h
{
    constexpr int square(int x)
    {
        return x*x;
    }

    constexpr long long_max()
    {
        return std::numeric_limits<long>::max();
    }

    //This function is not constexpr in math.h and there is a collision if not in namespace. //boo 
    constexpr int abs(int x) 
    {
        return x < 0 ? -x : x;
    }
    /*
    constexpr void f(int x)
    {
        //can't have a void constexpr function... this is an error. 
        //yes it compiles but just try to use it. The compiler just ignores this unless it is used. 
    }
    */
    
    constexpr int prev(int x)
    {
        //return x - 1;
        return --x;  //constexpr function return is non-constant
    }

    constexpr int g(int x, int n) //not allowed by microsofts C++14 implementation. Use clang to make it work. 
    {
        int r = 1;
        while (--n > 0) r *= x;
        return r;
    }
}

int main()
{
    using namespace cppcourse;
    int x[square(3)];
    int y[prev(5)];
    return 0;
}