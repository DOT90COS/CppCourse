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

class myInt : public Variant_Type
{
    int x_;
public:
    myInt(int x) :x_(x) {}
    Type getType() override { return Variant_Type::Type::intType; }
    int asInt() { return x_; }
    double asDouble() { return x_; }
    std::string asString() { return std::to_string(x_); }
};

Variant make_variant(int x)
{
    return std::make_unique<myInt>(x);
}

class myDouble : public Variant_Type
{
    double x_;
public:
    myDouble(double x) :x_{ x } {}
    Type getType() override { return Variant_Type::Type::doubleType; }
    int asInt() { return static_cast<int>(x_); }
    double asDouble() { return x_; }
    std::string asString() { return std::to_string(x_); }
};

Variant make_variant(double x)
{
    return std::make_unique<myDouble>(x);
}

class myString : public Variant_Type
{
    std::string x_;
public:
    myString(const std::string& x) :x_{ x } {}
    Type getType() override { return Variant_Type::Type::stringType; }
    int asInt() { return std::stoi(x_); }
    double asDouble() { return std::stod(x_); }
    std::string asString() { return x_; }
};

Variant make_variant(const std::string& x)
{
    return std::make_unique<myString>(x);
}

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