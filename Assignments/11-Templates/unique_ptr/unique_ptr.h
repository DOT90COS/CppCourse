#pragma once


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