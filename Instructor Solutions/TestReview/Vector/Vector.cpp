#include "Vector.h"
/*******************************************************
////////////////////////////////////////////////////////

 WARNING WARNING WARNING

 TEMPLATES SHOULD BE WRITEN ENTIRELY IN THE HEADER
 THIS IS HERE FOR REFERENCE
 ////////////////////////////////////////////////////////
 *******************************************************/

/*

Vector::iterator Vector::begin()
{
    return iterator{ this, 0 };
}

Vector::iterator Vector::end()
{
    return iterator{ this, size_ };
}

Vector::size_type Vector::size() const
{
    return size_;
}

void Vector::push_back(int x)
{
    if (capacity_ - size_ == 0)
    {
        grow();
    }
    array_[size_] = x;
    size_++;
}

int Vector::nextCapacity()
{
    if (capacity_ = 0)
        return 10;
    else
        return capacity_ * 2;
}

void Vector::grow()
{
    auto newsize = nextCapacity();
    std::unique_ptr<int[]> newArray = std::make_unique<int[]>(newsize);
    for (auto i = 0U; i < size_; ++i)
        newArray[i] = array_[i];
    array_ = std::move(newArray);
    capacity_ = newsize;
}

Vector::reference Vector::operator[](size_type index)
{
    return array_[index];
}

Vector::iterator& VectorIterator::operator++()
{
    pos_++;
    return *this;
}

Vector::iterator VectorIterator::operator++(int)
{
    auto copy = *this;
    pos_++;
    return copy;
}

Vector::iterator& VectorIterator::operator--()
{
    pos_--;
    return *this;
}

Vector::iterator VectorIterator::operator--(int)
{
    auto copy = *this;
    pos_--;
    return copy;
}

Vector::reference VectorIterator::operator*()
{
    if (nullptr == container_)
        throw std::runtime_error("VectorIntIterator Not Initialized");
    return container_->array_[pos_];
}

bool VectorIterator::operator!=(const Vector::iterator& it)
{
    return it.container_ != container_ || it.pos_ != pos_;
}

bool VectorIterator::operator==(const Vector::iterator& it)
{
    return !(*this != it);
}
*/
