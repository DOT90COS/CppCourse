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
    using uint = unsigned int;
    std::unique_ptr<int[]> array_;
    uint size_ = 0;
    uint capacity_ = 0;
    friend class VectorIterator;

    void grow();
    int nextCapacity();

public:
    //Items that we might have to have for some STL functions (i.e. back_inserter)
    using iterator = VectorIterator;
    using difference_type = ptrdiff_t;
    using size_type = uint;
    using value_type = int;
    using pointer = int*;
    using reference = int&;
    
    
    
    int& operator[](size_type index);
    size_type size() const;
    iterator begin();
    iterator end();
    void push_back(int x);


};

template<typename T>
class VectorIterator 
{
protected:
    Vector<T>* container_ = nullptr;
    Vector<T>::size_type pos_;

public:
    VectorIterator() {}
    explicit VectorIterator(Vector<T>* vi, Vector<T>::size_type pos) : container_(vi), pos_(pos) {}
    Vector<T>::iterator& operator++(); //pre-increment
    Vector<T>::iterator operator++(int); //post-increment
    Vector<T>::iterator& operator--();
    Vector<T>::iterator operator--(int);
    Vector<T>::reference operator*();
    bool operator!=(const Vector<T>::iterator& vi);
    bool operator==(const Vector<T>::iterator& vi);
};