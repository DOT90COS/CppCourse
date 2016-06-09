#pragma once
#include <vector>
#include <cstdint>
#include <iostream>
#include <string>
/**********************************************************
Implement

operator+
operator+=
operator-
operator-=
operator==
operator!=
operator<=
operator>=
operator>
operator<
operator*
operator*=
operator/
operator/=
operator%
operator%=
***************************************************************/

class BigNum //Class to hold absurdly large numbers.
{
    //EASY MODE Store each digit as a seperate entry in the vector below...
    //HARD MODE Replace this and be more efficient.
    //HARD MODE Let your numbers be negative. 
    std::vector<short> nums_;

    friend std::ostream& operator<<(std::ostream& os, const BigNum& num);

public:
    BigNum(uint64_t num);
    BigNum(const std::string aBigNum);
//    BigNum(const BigNum& n);


    std::string toString() const;
    BigNum operator+(const BigNum& n) const;
    BigNum& operator+=(const BigNum& n);

    //Be Awesome
};

std::ostream& operator<<(std::ostream& os, const BigNum& num);
