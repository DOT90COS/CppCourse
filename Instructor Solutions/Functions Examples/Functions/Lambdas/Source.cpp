#include <functional>
#include <iostream>

/*
This file show some of the things that I have found to be tricky about lambdas. 
*/
struct functor {
    functor(int y) :y_(y) {} //This is the construct, it does the same job as the capture.
    int operator()() { return y_++; }
private:
    int y_ = 0;
};

struct functor2 {
    functor2(int& y) :y_(y) {} //This is the construct, it does the same job as the capture.
    int operator()() { return y_++; }
private:
    int& y_; 
};

std::function<int()> foo(int x)
{   
    //This is a good example of why we shouldn't use the generic value and reference capture.
    //If we had put the variable name that we were trying to capture this would have been a compilation error.

    static int y = 0; //important to note this is static (i.e. won't get cleaned up off the stack)
    static int z = 0;
    switch (x)
    {
    case 0: return []() {return 0; }; //return type is auto by default. 
    case 1: return [=]()mutable {return y++; }; //default capture by value
    case 2: return [&]() {return y++; }; //default capture by reference
    case 3: return functor(y); //roughly the same as 1
    case 4: return functor2(y); //roughtly the same as 2.
    default: return [&]() {return z++; }; //default capture by reference
    }
}

void static_scope_example()
{
    auto a = foo(0);
    auto b = foo(1);
    auto e = foo(3);
    int x = 11;
    functor z{ x };
    z();
    e();

    auto c = foo(2);
    auto d = foo(50);
    std::cout << b() << b() << b();
    auto f = b;
    std::cout << a() << b() << c() << b() << d() << b() << c() << std::endl;
    //Expected to print 0211000 .. It doesn't WHY?
}

void do_by_value_captures_hold_state()
{
    auto x = 0;
    // error C3491: 'x': a by copy capture cannot be modified in a non-mutable lambda
    //auto fn = [x]() {std::cout << x++; };

    /*                 #### SIDE NOTE ####
       Herb Sutter, a very well known member of the C++ standardization committee, provides 
       an answer to the question of why the above doesn't work in a paper.
      
       Lambda Correctness and Usability Issues:
       (http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3424.pdf)

       I that paper he talks about why this should be changed in C++14 (It wasn't). He does
       give some insight as to why it was that way to begin with.
       
       "This feature appears to have been added out of a concern that the user might not realize
       he got a copy, and in particular that since lambdas are copyable he might be changing a different 
       lambda's copy."

       We look at the copy problem when lambda_capture_copy(); 
    */

    auto fn = [x]()mutable {std::cout << x++; };          
    fn(); fn(); fn();
    
    std::cout << "\nX in do_by...: " << x << "\n";
   
    auto fr = [&x] {std::cout << x++; };
    fr(); fr(); fr();
    
    std::cout << "\nX in do_by...: " << x << "\n";
}

void lambda_capture_copy()
{
    auto x = 0U;
    auto fn1 = [x]()mutable {std::cout << x++; };
    fn1(); fn1(); 
    auto fn2 = fn1; //a copy;
    std::cout << "\nfn2: "; fn2(); fn2();
    std::cout << "\nfn1: "; fn1(); 
}

int main()
{
    static_scope_example(); //crazy mind blown!
    do_by_value_captures_hold_state(); //only when mutable. 
    lambda_capture_copy(); //At least this one makes sense! :)
    return 0;
}