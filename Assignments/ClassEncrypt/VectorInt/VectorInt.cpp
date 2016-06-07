#include "VectorInt.h"
#include <stdexcept>

////////////////////////////////////////VectorInt
int& VectorInt::operator[](VectorInt::size_type pos)
{
    return array_[pos];
}

VectorInt::size_type VectorInt::size() const
{
    return size_;
}

VectorInt::iterator VectorInt::begin()
{
    return VectorInt::iterator(this, 0);
}

VectorInt::iterator VectorInt::end()
{
    return VectorInt::iterator(this, size_);
}

void VectorInt::push_back(int x)
{
    if (size_ == capacity_)
    {
        grow();
    }
    array_[size_] = x;
    size_++;
}

int VectorInt::back() const
{
    if (size_ == 0)
        throw std::runtime_error("ARRAY IS EMPTY YOU IDIOT!!!");
    return array_[size_ - 1];
}

void VectorInt::pop_back()
{
    if (size_ == 0)
        throw std::runtime_error("ARRAY IS EMPTY YOU IDIOT");
    size_--;
}

void VectorInt::grow()
{
   
    if (capacity_ == 0)
    {
        capacity_ = 10;
    }
    else
    {
        capacity_ *= 2;
    }

    auto tmp = std::make_unique<int[]>(capacity_);
    for (auto i = 0U; i < size_; ++i)
        tmp[i] = array_[i];
    array_ = std::move(tmp);
}



////////////////////////////////////////Iterator
VectorIntIterator::VectorIntIterator(VectorInt* ptr, VectorInt::size_type pos):container_(ptr), pos_(pos) {}

VectorInt::iterator& VectorIntIterator::operator++()
{
    pos_++;
    return *this;
}

VectorInt::iterator VectorIntIterator::operator++(int)
{
    VectorIntIterator tmp = *this;
    pos_++;
    return tmp;
}

VectorInt::iterator& VectorIntIterator::operator--()
{
    pos_--;
    return *this;
}

VectorInt::iterator VectorIntIterator::operator--(int)
{
    VectorIntIterator tmp = *this;
    pos_--;
    return tmp;
}

VectorInt::reference VectorIntIterator::operator*()
{
    return (*container_)[pos_];
}

bool VectorIntIterator::operator!=(const VectorInt::iterator& n)
{
    return container_ != n.container_ || pos_ != n.pos_;
}

bool VectorIntIterator::operator==(const VectorInt::iterator& n)
{
    return !(*this != n);
//    return !operator!=(n);
}



