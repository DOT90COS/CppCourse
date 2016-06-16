#pragma once
#include <iostream>

/*************************************
A ScaledNum is a type that I just made up!
It holds a number that is represented by two parts. 
* A number 
* and a factor that gets multiplied with the number to get the real number. 
* For this problem you will implement ==, !=, +, +=, -, -+, *, *=, /, and /= for ScaledNum.

The EASIEST way to do the calculations is to 
- get the number (num*factor) of both operands
- do the calculation
- store the number component back into the class by dividing the calculated number by the factor.
*************************************/

class ScaledNum {
    double num_ = 0;
    double factor_ = 1.0;
    friend std::ostream& operator<<(std::ostream& os, const ScaledNum& n);
public:
    ScaledNum() = default;
    ScaledNum(double num, double factor);
    ScaledNum(const ScaledNum& n);
    double getFactor()const;
    void setFactor(double factor);
    std::pair<double, double> getVals() const;
    ScaledNum& operator=(double num);
    ScaledNum& operator=(const ScaledNum& n);

 



};

std::ostream& operator<<(std::ostream& os, const ScaledNum& n);
