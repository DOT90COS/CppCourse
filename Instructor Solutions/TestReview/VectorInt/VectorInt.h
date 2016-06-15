#pragma once
#include <memory>
#include <iterator>
#include <stdexcept>

class VectorIntIterator;

class VectorInt
{
    using uint = unsigned int;
    std::unique_ptr<int[]> array_;
    uint size_ = 0;
    uint capacity_ = 0;
    friend class VectorIntIterator;

    void grow();
    int nextCapacity();

public:
    //Items that we might have to have for some STL functions (i.e. back_inserter)
    using iterator = VectorIntIterator;
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

class VectorIntIterator 
{
protected:
    VectorInt* container_ = nullptr;
    VectorInt::size_type pos_;

public:
    VectorIntIterator() {}
    explicit VectorIntIterator(VectorInt* vi, VectorInt::size_type pos) : container_(vi), pos_(pos) {}
    VectorInt::iterator& operator++(); //pre-increment
    VectorInt::iterator operator++(int); //post-increment
    VectorInt::iterator& operator--();
    VectorInt::iterator operator--(int);
    VectorInt::reference operator*();
    bool operator!=(const VectorInt::iterator& vi);
    bool operator==(const VectorInt::iterator& vi);
};