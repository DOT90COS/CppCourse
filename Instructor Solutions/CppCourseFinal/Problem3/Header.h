#pragma once

//write a template function that takes a container and computes the size
// of all the elements in it using sizeOf.
template<typename Container> 
int sizeOfAll(const Container& container) {
    int size = 0;
    for (auto& x : container)
        size += sizeof(x);
    return size;
}

//write an accumulate function: a Accumulate is one that takes a begin and end iterator and an iterator::value_type
//and adds the iterator::value_type to all of the elements in the range of the iterators. 
template<typename T>
void accumulate(T begin, T end, typename T::value_type x)
{
    for (auto itr = begin; itr != end; ++itr)
    {
        *itr += x;
    }
}

//write an accumulate that works on C-Style Arrays
template<typename T> 
void accumulate(T* begin, T* end, T x)
{
    for (auto itr = begin; itr != end; ++itr)
    {
        *itr += x;
    }
}