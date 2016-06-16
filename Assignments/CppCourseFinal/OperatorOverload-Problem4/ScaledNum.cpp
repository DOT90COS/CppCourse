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


std::ostream & operator<<(std::ostream & os, const ScaledNum & n)
{
    os << n.num_ * n.factor_;
    return os;
}
