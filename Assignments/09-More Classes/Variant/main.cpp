#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Variant_Type{

public:
    enum class Type {intType, doubleType, stringType };
    using type = void;
    virtual Type getType() = 0;
    virtual int asInt() = 0;
    virtual double asDouble() = 0;
    virtual std::string asString() = 0;
};

using Variant = std::unique_ptr<Variant_Type>;

/**************************************** Write Code Below ************************************************/
class myInt : public Variant_Type
{
    int x_;
public:
    myInt(int x) 

};

Variant make_variant(int x)
{
    return std::make_unique</*A TYPE*/>();
}

class myDouble : public Variant_Type
{
};

Variant make_variant(double x)
{
}

class myString : public Variant_Type
{
};

Variant make_variant(const std::string& x)
{
}

/************************************** End Writing Code ****************************************************/
int main()
{
    std::vector<Variant> bunchOStuff;
    bunchOStuff.push_back(make_variant(5));
    bunchOStuff.push_back(make_variant(2.34));
    bunchOStuff.push_back(make_variant("This is a string"));


    for (auto& x : bunchOStuff)
    {
        switch (x->getType())
        {
        case Variant_Type::Type::doubleType:
            std::cout << x->asDouble();
            break;
        case Variant_Type::Type::intType:
            std::cout << x->asInt();
            break;
        case Variant_Type::Type::stringType:
            std::cout << x->asString();
            break;
        }
        std::cout << "\n";
    }

    return 0;

}