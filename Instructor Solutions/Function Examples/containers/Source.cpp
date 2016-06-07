#include <vector>
#include <algorithm>
#include <functional>
#include <memory>
#include <iostream>
#include <fstream>
#include <string>

struct closure
{
    closure(int capture) { capture_ = capture; }
    int operator()(int a) {
        return a + capture_;
    }
private:
    int capture_;
};

void bar()
{
    int thing = 5;
    auto lambda = [thing](int x) {return x + thing; };
    thing = 6;
    auto similarToLambda = closure(thing);
    std::cout << "Labda + 5: " << lambda(5) << "\n";
    std::cout << "closure + 5" << similarToLambda(5) << "\n";
}


int overloaded(int x)
{
    return x > 0 ? x : -x ;
}

auto overloaded(double x)
{
    return x > 0 ? x : -x ;
}

void foo(int x)
{
    std::cout << "foo(int x)\n";
}

void foo(unsigned int x)
{
    std::cout << "foo(const int x)\n";
}

void writeHelloWorld(const std::string& filename = "helloWorld.txt")
{
 //write out stuff
}

int add(int a, int b, int c=0, int d = 0, int e = 0);

void appendMyEncodeName(const std::string& filename)
{
    std::cout << filename;
    std::ofstream outFile(filename);
  // filename += "myinstructor.is.mean.txt";
}
void processor(std::function<void()> f)
{
    f();
}

int main()
{
    std::string file = "fun.txt";
    auto fun = [&file]()mutable {file += ".lambda.txt"; std::cout << file << std::endl; };
    fun();
    processor(fun);
    appendMyEncodeName(file);

    auto a = add(1, 2);
    auto b = add(1, 2, 3);
    auto c = add(1, 2, 3, 4, 5);


   // unsigned int a = 5;
   //int b = 7;

    foo(a);
    foo(b);

    writeHelloWorld();
    writeHelloWorld("myfile.txt");



    return 0;
}

int add(int a, int b, int c, int d, int e)
{
    int tmp = a + b + c + d + e;
    return tmp;
}

