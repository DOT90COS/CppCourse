#pragma once
#include <typeinfo>
#include <limits>
#include <type_traits>
#include <memory>
#include <string>
#include <iostream>

#define PRINT_INFO(type) printInfo(#type, type);

/***********************************************************************************************************
*****************                              IS FUNDAMENTAL                              *****************
************************************************************************************************************/

// This shows a different usage of enable_if, here I have used it as a parameter. 
template<typename T> T printArithmetic(T var, typename std::enable_if<!std::is_arithmetic<T>::value, int*>::type = nullptr)
{
    std::cout << "Is arithmetic: false\n";
    return var;
}

template<typename T> T printArithmetic(T var, typename std::enable_if<std::is_arithmetic<T>::value, int*>::type = nullptr)
{
    std::cout << "is arithmetic: true\n";
    std::cout << std::boolalpha;
    std::cout << "Is floating point: " << std::is_floating_point<T>::value << "\n"
                 "Is integral: " << std::is_integral<T>::value << "\n"
                 "Is signed: " << std::is_signed<T>::value << "\n"
                 "Is unsigned: " << std::is_unsigned<T>::value << "\n";
    std::cout << std::noboolalpha;
    std::cout << "min: " << std::numeric_limits<decltype(var)>::min() << "\n";
    std::cout << "max: " << std::numeric_limits<decltype(var)>::max() << "\n";
    return var;
}

template<typename T> typename std::enable_if<!std::is_fundamental<T>::value, T>::type printFundamental(T var)
{
    std::cout << "Is fundamental: false\n";
    return var;
}

template<typename T> typename std::enable_if<std::is_fundamental<T>::value, T>::type printFundamental(T var)
{
    std::cout << "Is fundamental: true\n";
    var = printArithmetic(var);
    std::cout << std::boolalpha;
    std::cout << "Is null pointer: " << std::is_null_pointer<T>::value << "\n";
    std::cout << std::noboolalpha;

    return var;
}

/***********************************************************************************************************
*****************                              IS COMPOUND                                 *****************
************************************************************************************************************/

template<typename T> typename std::enable_if<!std::is_reference<T>::value, T>::type printReference(T var)
{
    std::cout << "Is reference: false\n";
    return var;
}

template<typename T> typename std::enable_if<std::is_reference<T>::value, T>::type printReference(T var)
{
    std::cout << "Is reference: true\n";
    std::cout << std::boolalpha;
    std::cout << "Is L-Value Reference: " << std::is_lvalue_reference<T>::value << "\n";
    std::cout << "Is R-Value Reference: " << std::is_rvalue_reference<T>::value << "\n";
    std::cout << std::noboolalpha;
    return var;
}

template<typename T> typename std::enable_if<!std::is_compound<T>::value, T>::type printCompound(T var)
{
    std::cout << "Is compound: false\n";
    return var;
}

template<typename T> typename std::enable_if<std::is_compound<T>::value, T>::type printCompound(T var)
{
    std::cout << "Is compound: true\n";
    var = printReference(std::move(var));
    std::cout << std::boolalpha;
    std::cout << "Is pointer: " << std::is_pointer<T>::value << "\n";
    std::cout << "Is member pointer: " << std::is_member_pointer<T>::value << "\n";
    std::cout << "Is array: " << std::is_array<T>::value << "\n";
    std::cout << "Is function: " << std::is_function<typename std::remove_pointer<T>::type>::value << "\n";
    std::cout << "Is enum: " << std::is_enum<T>::value << "\n";
    std::cout << "Is class: " << std::is_class<T>::value << "\n";
    std::cout << "Is union: " << std::is_union<T>::value << "\n";
    return var;
}


/***********************************************************************************************************
*****************                              Start Here                                *****************
************************************************************************************************************/

template<typename T> void printInfo(std::string typeSpecified, T var)
{
    std::cout << "Information about " << typeSpecified << "\n"
                 "Compiler Identified as: " << typeid(var).name() << "\n"
                 "sizeof(" << typeid(var).name() << "): " << sizeof(var) << "\n";

    //std::move is needed to deal with unique_ptr or any other type without a way to copy. 
    var = printFundamental(std::move(var));
    var = printCompound(std::move(var));
    std::cout << std::endl;
}
/***********************************************************************************************************
*****************                              MACHINE TYPE                                *****************
************************************************************************************************************/

struct unknown_machine
{
    static const std::string type;
};

struct ILP32_machine
{
    static const std::string type;
};

struct LP32_machine
{
    static const std::string type;
};

struct ILP64_machine
{
    static const std::string type;
};

struct LLP64_machine
{
    static const std::string type;
};

template<int I, int L, int P>
struct machine : unknown_machine {};

template<>
struct machine<2, 4, 4> : LP32_machine {};

template<>
struct machine<4, 4, 4> : ILP32_machine {};

template<>
struct machine<4, 4, 8> : LLP64_machine {};

template<>
struct machine<4, 8, 8> : ILP64_machine {};
