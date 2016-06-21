#include "ScaledNum.h"

ScaledNum::ScaledNum(double num, double factor):num_(num), factor_(factor)
{
}

ScaledNum::ScaledNum(const ScaledNum & n):num_(n.num_), factor_(n.factor_)
{
}

double ScaledNum::getFactor() const
{
    return factor_;
}

void ScaledNum::setFactor(double factor)
{
    factor_ = factor;
}

std::pair<double, double> ScaledNum::getVals() const
{
    return std::make_pair(num_, factor_);
}

ScaledNum& ScaledNum::operator=(double num)
{
    num_ = num;
    return *this;
}

ScaledNum& ScaledNum::operator=(const ScaledNum & n)
{
    num_ = n.num_;
    factor_ = n.factor_;
    return *this;
}

bool ScaledNum::operator==(const ScaledNum & n)
{
    return (num_*factor_) == (n.num_*n.factor_);
}

bool ScaledNum::operator!=(const ScaledNum & n)
{
    return !(*this == n);
}

ScaledNum & ScaledNum::operator-=(const ScaledNum & n)
{
    auto x = (num_*factor_) - (n.num_*n.factor_);
    num_ = x / factor_;
    return *this;
}

ScaledNum ScaledNum::operator-(const ScaledNum & n)
{
    return ScaledNum(*this)-=n;
}

ScaledNum & ScaledNum::operator+=(const ScaledNum & n)
{
    auto x = (num_*factor_) + (n.num_*n.factor_);
    num_ = x / factor_;
    return *this;
}

ScaledNum ScaledNum::operator+(const ScaledNum & n)
{
    return ScaledNum(*this)+=n;
}

ScaledNum & ScaledNum::operator/=(const ScaledNum & n)
{
    auto x = (num_*factor_) / (n.num_*n.factor_);
    num_ = x / factor_;
    return *this;
}

ScaledNum ScaledNum::operator/(const ScaledNum & n)
{
    return ScaledNum(*this)/=n;
}

ScaledNum & ScaledNum::operator*=(const ScaledNum & n)
{
    auto x = (num_*factor_) * (n.num_*n.factor_);
    num_ = x / factor_;
    return *this;
}

ScaledNum ScaledNum::operator*(const ScaledNum & n)
{
    return ScaledNum(*this)*=n;
}

std::ostream & operator<<(std::ostream & os, const ScaledNum & n)
{
    os << n.num_ * n.factor_;
    return os;
}
