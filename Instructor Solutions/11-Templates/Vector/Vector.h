#pragma once
#include <memory>
#include <iterator>
#include <stdexcept>
/******************************************************
Take the vector class below and make it templated. 

Bonus. Add an initializer list constructor and uncomment the 
initializer list test in main.cpp.
******************************************************/
template<typename T>
class VectorIterator;

template<typename T>
class Vector
{
    std::unique_ptr<T[]> array_;
    unsigned int size_ = 0;
    unsigned int capacity_ = 0;
    friend class VectorIterator<T>;

    void grow() {
        auto newsize = nextCapacity();
        std::unique_ptr<T[]> newArray = std::make_unique<T[]>(newsize);
        for (auto i = 0U; i < size_; ++i)
            newArray[i] = array_[i];
        std::swap(array_, newArray);
        capacity_ = newsize;
    }
    int nextCapacity() {
        if (capacity_  == 0)
            return 10;
        else
            return capacity_ * 2;
    }

public:
    //Items that we might have to have for some STL functions (i.e. back_inserter)
    using iterator = VectorIterator<T>;
    using difference_type = ptrdiff_t;
    using size_type = unsigned int;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    
    
    T& operator[](size_type index) {
        return array_[index];
    }
    size_type size() const {
        return size_;
    }
    iterator begin() {
        return iterator(this, 0);
    }
    iterator end() {
        return iterator(this, size_);
    }
    void push_back(const T& x) {
        if (capacity_ - size_ == 0)
        {
            grow();
        }
        array_[size_] = x;
        size_++;
    }


};

template<typename T>
class VectorIterator 
{
protected:
    Vector<T>* container_ = nullptr;
    typename Vector<T>::size_type pos_;

public:
    VectorIterator() {}
    explicit VectorIterator(Vector<T>* vi, typename Vector<T>::size_type pos) : container_(vi), pos_(pos) {}
    typename Vector<T>::iterator& operator++() { //pre-increment
        pos_++;
        return *this;
    }
    typename Vector<T>::iterator operator++(int) { //post-increment
        auto copy = *this;
        pos_++;
        return copy;
    }
    typename Vector<T>::iterator& operator--() {
        pos_--;
        return *this;
    }
    typename Vector<T>::iterator operator--(int) {
        auto copy = *this;
        pos_--;
        return copy;
    }
    typename Vector<T>::reference operator*() {
        if (nullptr == container_)
            throw std::runtime_error("VectorIterator Not Initialized");
        return container_->array_[pos_];
    }
    bool operator!=(const typename Vector<T>::iterator& it) {
        return it.container_ != container_ || it.pos_ != pos_;
    }
    bool operator==(const typename Vector<T>::iterator& it) {
        return !(*this != it);
    }
};