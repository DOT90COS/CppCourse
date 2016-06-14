#include "Test.h"



Test::Test()
{
    a_ = new int[4];
}


Test::~Test()
{
    delete[] a_;
}
