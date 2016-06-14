#include "VectorInt.h"

VectorInt::iterator VectorInt::begin()
{
    return iterator{ this, 0 };
}

VectorInt::iterator VectorInt::end()
{
    return iterator{ this, size_ };
}

VectorInt::size_type VectorInt::size() const
{
    return size_;
}

void VectorInt::push_back(int x)
{
    if (capacity_ - size_ == 0)
    {
        grow();
    }
    array_[size_] = x;
    size_++;
}

int VectorInt::nextCapacity()
{
    if (capacity_ = 0)
        return 10;
    else
        return capacity_ * 2;
}

void VectorInt::grow()
{
    auto newsize = nextCapacity();
    std::unique_ptr<int[]> newArray = std::make_unique<int[]>(newsize);
    for (auto i = 0U; i < size_; ++i)
        newArray[i] = array_[i];
    array_ = std::move(newArray);
    capacity_ = newsize;
}

VectorInt::reference VectorInt::operator[](size_type index)
{
    return array_[index];
}

VectorInt::iterator& VectorIntIterator::operator++()
{
    pos_++;
    return *this;
}

VectorInt::iterator VectorIntIterator::operator++(int)
{
    auto copy = *this;
    pos_++;
    return copy;
}

VectorInt::iterator& VectorIntIterator::operator--()
{
    pos_--;
    return *this;
}

VectorInt::iterator VectorIntIterator::operator--(int)
{
    auto copy = *this;
    pos_--;
    return copy;
}

VectorInt::reference VectorIntIterator::operator*()
{
    if (nullptr == container_)
        throw std::runtime_error("VectorIntIterator Not Initialized");
    return container_->array_[pos_];
}

bool VectorIntIterator::operator!=(const VectorInt::iterator& it)
{
    return it.container_ != container_ || it.pos_ != pos_;
}

bool VectorIntIterator::operator==(const VectorInt::iterator& it)
{
    return !(*this != it);
}

