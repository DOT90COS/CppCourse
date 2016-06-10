#pragma once
#include <functional>

class Guard {
    //Make this.
    std::function<void()> fun_;
public:
    Guard(const std::function<void()>& fun):fun_(fun) {}
    ~Guard() { fun_(); }
};