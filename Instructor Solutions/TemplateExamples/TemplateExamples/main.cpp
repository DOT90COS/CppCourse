#include <string>
#include <sstream>
#include <vector>
#include <type_traits>
#include <iostream>
#include <deque>

template<typename T> T to(const std::string& number)
{
    std::stringstream ss(number);
    T num;
    ss >> num;
    return num;
}

struct NoAdd {
    int x_ = 0;
};

template<typename T> T add(T a, T b)
{
    return a + b;
}

template<typename Cont, typename Elem>
void push_back(Cont& container, const Elem& elem)
{
    static_assert(std::is_class<Cont>::value, "Cont must be a class");
    container.push_back(elem);
}


class FooBar {
    int count_ = 0;
public:
    template<typename T> 
    void accumulate(T value) {
        count_ += value;
    }
};

template<typename T> 
T foo(const T& element1, const T& element2)
{
    std::cout << "T foo(const T& element1, const T& element2\n";
    return T();
}

template<typename T> 
std::vector<T> foo(const std::vector<T>& elem1, const T& elem2)
{
    std::cout << "std::vector<T> foo(const std::vector<T>& elem1, const T& elem2)\n";
    return std::vector<T>();
}

template<typename T> 
T foo(const T& elem1, int elem2)
{
    std::cout << "T foo(const T& elem1, int elem2)\n";
    return T();
}

int foo(int elem1, int elem2)
{
    std::cout << "int foo(int elem1, int elem2)\n";
    return 0;
}

template<typename T> 
void bar(const T& a, const T& b ){
    std::cout << typeid(T).name() << "\n";
}

template<typename T>
T containerAdd(const T& cont, const typename T::value_type& addee)
{
    T tmp{ cont };
    for (auto& x : tmp)
    {
        x += addee;
    }
    return tmp;
}

int main()
{
    NoAdd no1;
    NoAdd no2;
    //auto no3 = add(no1, no2);
    std::string numStr = "924";
    auto num = to<int>(numStr);

    auto sum = add<std::string>("924", "is a num");
    auto sum2 = add(numStr, sum);
    auto sum3 = add<int>(2.3, 2.1); //sum3 is an int and the parameters will be implicitly converted to an int. 
    auto sum4 = add(2.3, 2.1); //sum4 is a double. 

    std::vector<int> vecInt{ 1,2,3,4,5,6,7,8,9,10 };
    std::deque<int> decInt{ 1,2,3,4,5,6,7,8,9,10 };

    push_back(vecInt, 5); //Fine
    //push_back(num, 2); //error

    std::vector<FooBar> foobar;
    foo(1, 2);
    foo(1.2, 2);
    foo(foobar, FooBar());
    foo(2.3, 2LL);
    foo<long long>(2.4, 2LL);
    auto x = foo('x', 1);

    //bar('c', 1);

    vecInt = containerAdd(vecInt, 40);
    decInt = containerAdd(decInt, 40);
   


    return 0;
}
