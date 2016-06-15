#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <deque>
#include <stdexcept>
#include <memory>
#include <list>

struct BurntPizza : std::runtime_error {
    BurntPizza(const std::string& message) :std::runtime_error(message) {}
};

//or
/*
class BurntPizza : public std::runtime_error {
public:
    BurntPizza(const std::string& message) :std::runtime_error(message) {}
};*/

class BasePizza {
public:
    enum Size { Small, Medium, Large, XL, HallaLarge};
    enum Toppings {
        Cheese, Pepperoni, Jalapenos, GreenPeppers,
        Mushrooms, Onion
    };

protected:
    std::deque<Toppings> toppings_;
    Size size_ = Size::Small;
    std::function<int(int)> bakeFun_;
    inline double basePrice() const {
        switch (size_)
        {
        case Small:
            return 7.0;
        case Medium:
            return 8.0;
        case Large:
            return 10.50;
        case XL:
            return 15.00;
        case HallaLarge:
            return 25.00;
        } 

        //should never get here... 
        throw std::runtime_error("WHAT?!?!");
    }

    

public:
    BasePizza() = default;
    BasePizza(Size size, 
        const std::deque<Toppings>& toppings = {}) :size_(size), 
                    toppings_(toppings) 
    {
    }
    virtual ~BasePizza() = default;
    virtual void addTopping(Toppings topping) = 0;
    virtual double getCost() const = 0;
    virtual void setSize(Size size) {
        size_ = size;
    }
    virtual int bake(int x) {
        return bakeFun_(x);
    }

};

std::ostream& operator<<(std::ostream& os, BasePizza::Toppings topping){
    switch (topping) {
    case BasePizza::Pepperoni:
        os << "Pepperoni";
        break;
    case BasePizza::Cheese:
        os << "Cheese";
        break;
    case BasePizza::Mushrooms:
        os << "Mushrooms";
        break;
    case BasePizza::GreenPeppers:
        os << "Green Peppers";
        break;
    case BasePizza::Onion:
        os << "Onion";
        break;
    default:
        os << "Undefined Topping";
    }
    return os;
}

class PepperoniPizza : public BasePizza {
    int bakingTime_ = 16;
public:
    PepperoniPizza() :BasePizza(Size::Small, 
        { Toppings::Pepperoni, Toppings::Cheese }) {}
    
    PepperoniPizza(Size size):BasePizza(size,
        { Toppings::Pepperoni, Toppings::Cheese }) 
    {
        int& localBake = bakingTime_;
       //Capturing the this pointer by value so that we can use bakingTime_
        bakeFun_ = [this](int x)->int {
            this->bakingTime_ -= x;
            if (this->bakingTime_ == 0)
                std::cout << "DONE!\n";
            else if (this->bakingTime_ < 0)
                throw BurntPizza("YOU BURNT IT\n");
            return this->bakingTime_;
        };
    }

    void addTopping(Toppings topping) override {
        std::cerr << "NO " << topping << " for you!!\n";
    };

    double getCost() const override {
        auto cost = basePrice();
        return cost - 1.0;
    }
};

class CustomPizza : public BasePizza {
    int bakingTime_ = 20;
public:
    CustomPizza() = default;
    CustomPizza(Size size):BasePizza(size)
    {
        int& localBake = bakingTime_;
       //Capturing the this pointer by value so that we can use bakingTime_
        bakeFun_ = [this](int x)->int {
            this->bakingTime_ -= x;
            if (this->bakingTime_ == 0)
                std::cout << "DONE!\n";
            else if (this->bakingTime_ < 0)
                throw BurntPizza("YOU BURNT IT\n");
            return this->bakingTime_;
        };
    }

    void addTopping(Toppings topping) override {
        toppings_.push_front(topping);
    };

    double getCost() const override {
        auto cost = basePrice();
        cost += 1.00 * toppings_.size();
        return cost;
    }
};

void printMenu()
{
    std::cout <<
        " Welcome to CppPizza \n"
        " Please enter the number of the pizza you would like:\n"
        " 1. Pepperoni\n"
        " 2. Custom Pizza\n";
}

void printSizeMenu()
{
    std::cout <<
        " Please enter the number of the size you would like:\n"
        " 1. Small\n"
        " 2. Medium\n"
        " 3. Large\n"
        " 4. XL\n"
        " 5. HALLALarge\n";
}

BasePizza::Size getSize()
{
    auto option = 0;
    while (option < 1 || option > 5)
    {
        printSizeMenu();
        std::cin >> option;
        switch (option)
        {
        case 1:
            return BasePizza::Small;
        case 2:
            return BasePizza::Medium;
        case 3: 
            return BasePizza::Large;
        case 4: 
            return BasePizza::XL;
        case 5: 
            return BasePizza::HallaLarge;
        }
    }
}

std::unique_ptr<BasePizza> makePepperoni(BasePizza::Size size)
{
    return std::make_unique<PepperoniPizza>(size);
}

std::unique_ptr<BasePizza> makeCustom(BasePizza::Size size,
    const std::deque<BasePizza::Toppings>& toppings)
{
    std::unique_ptr<BasePizza> pizza =  std::make_unique<CustomPizza>(size);
    for (auto x : toppings)
        pizza->addTopping(x);
    return pizza;
}

void printToppings()
{
    std::cout <<
        "Pizza Toppings:\n"
        "1. Pepperoni\n"
        "2. Cheeses\n"
        "3. Mushrooms\n"
        "4. Green Peppers\n"
        "5. Onions\n"
        "6. No more toppings\n";
}

std::deque<BasePizza::Toppings> getToppings()
{
    std::deque<BasePizza::Toppings> toppings;
    auto choice = 0;
    while (choice != 6)
    {
        std::cout << "Current Toppings: ";
        for (auto x : toppings)
            std::cout << x << " ";
        std::cout << "\n";
        printToppings();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            toppings.push_back(BasePizza::Pepperoni);
            break;
        case 2:
            toppings.push_back(BasePizza::Cheese);
            break;
        case 3:
            toppings.push_back(BasePizza::Mushrooms);
            break;
        case 4:
            toppings.push_back(BasePizza::GreenPeppers);
            break;
        case 5:
            toppings.push_back(BasePizza::Onion);
            break;
        }
    }
    return toppings;
}

std::unique_ptr<BasePizza> takeOrder()
{
    int option = 0;
    while (option != 1 || option != 2)
    {
        printMenu();
        std::cin >> option;
        switch (option)
        {
        case 1:
            return makePepperoni(getSize());
        case 2:
            return makeCustom(getSize(), getToppings());
        }
    }

}

int main() 
{
    std::list<std::unique_ptr<BasePizza>> orders;
    while (true) {
        try
        {
            orders.push_back( takeOrder());
        }
        catch (const BurntPizza& bp)
        {
            std::cerr << "YUCK BURNT PIZZA!" << bp.what() << std::endl;
            exit(-1);
        }
    }
}
