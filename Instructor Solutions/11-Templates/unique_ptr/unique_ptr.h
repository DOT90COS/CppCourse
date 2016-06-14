#pragma once
#include <functional>

/**************************************************
This BONUS lab is to implement unique_ptr.

* unique_ptr can not be copied but only move. 
* unique_ptr takes a pointer to allocated memory in its constructor
  * this means you will need to use new and delete for this lab. 
* unique_ptr frees up memory with delete when it goes out of scope. 
* write unit test using catch.hpp

BONUS BONUS
* allow unique_ptr to take a custom deleter
* write make_unique see page 139 in Effective Modern C++. 

***************************************************/
template<typename T> 
void defaultDeleter(T* ptr)
{
    if(ptr != nullptr)
        delete ptr;
}

template<typename T>
class unique_ptr {
    T* ptr_{ nullptr };
    std::function<void(T*)> deleter_;

public:
    unique_ptr() = default;
    unique_ptr(T* ptr, std::function<void(T*)> deleter = defaultDeleter<T>) :ptr_(ptr),
                                                        deleter_(deleter)
    {
    }
    
    //1
    unique_ptr(const unique_ptr&) = delete;
    //2
    unique_ptr<T>& operator=(const unique_ptr&) = delete;
    //3
    unique_ptr(unique_ptr&& n):ptr_(n.ptr_) {
        //ptr_ = n.ptr_;
        n.ptr_ = nullptr;
    }

    //4
    unique_ptr<T>& operator= (unique_ptr&& n) {
        deleter_(ptr_);
        ptr_ = n.ptr_;
        n.ptr_ = nullptr;
        return *this;
    }

    //5
    ~unique_ptr() {
        deleter_(ptr_);
    }

    T& operator*() {
        return *ptr_;
    }

    T* release() {
        auto tmp = ptr_;
        ptr_ = nullptr;
        return tmp;
    }
};




