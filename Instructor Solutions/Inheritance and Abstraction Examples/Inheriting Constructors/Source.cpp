#include <string>

struct B1 {
    B1(int) {}
};

struct D1 : B1 {
    using B1::B1; // implicitly declares D1(int)
    std::string s; //string has a default constructor
    int x; //we "forgot" to provide for initialization of x
};

struct D2 : B1 {
    using B1::B1; // implicitly declares D1(int)
    std::string s; //string has a default constructor
    int x{ 0 }; //x is initialized
};

int main() {
    D1 d1a{ 6 }; //d1a.x not initialized
    //D1 d1b; //ERROR no default constructor
    D2 d2a{ 6 }; //ok d2a.x is 0;
    //D2 d2b; //Still and Error
}