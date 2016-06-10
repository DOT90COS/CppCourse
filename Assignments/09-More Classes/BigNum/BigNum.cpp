#include "BigNum.h"

//Implement BigNum

BigNum BigNum::operator+(const BigNum& n) const
{
    //BigNum a + BigNum b;
    BigNum tmp(*this);
    tmp += n;
    return tmp;
}

BigNum&  BigNum::operator+=(const BigNum& n)
{
    //Implment Add to self Here:

    //When done
    return *this;
}
