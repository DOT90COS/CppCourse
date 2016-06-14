.. title: Introduction

:css: CSS/course.css

----

Functions, Lambdas, and std::function
=====================================

.. image:: images\\quote-the-only-way-to-learn-a-new-programming-language-is-by-writing-programs-in-it.jpg


.. note::

  TODO...

----

Functions in C++
================

Functions in C++ are very similar to functions in C and other languages. 

* Can be overloaded
* Parameters can be defaulted
* Can be inlined at the choice of the compiler. 

.. code:: C++

    int foo(int, double&); // declaration

    int foo(int arg1, double& arg2) // definition
    {
        //does stuff and returns an int.
    }

----

Function Overloading
====================

Functions can have the same name so long as the signature is different

.. code:: C++
  
   int foo( );
   void foo(); //error impossible to differentiate between a call to foo() and a call to foo();
   void foo(double a);
   void foo(const double a); //error foo(double) already defined.
   void foo(double& a); //error impossible to differentiate between a call to foo(2.0); 
   int foo(signed int); 
   int foo(int); //int's are by default signed and therefore this is the same function as above. 


----

Default Parameters
==================

In the declaration you can specify a default.

.. code:: C++
  
  int foo(int x = 4)
  {
    std::cout << x << std::endl;
  }

  int main()
  {
     foo(); //prints 4
     foo(1); //prints 1
  }

----

Default Parameters with overloading
===================================

The compiler must be able to tell the difference between two functions. Defaulting parameters can affect this. 

.. code:: C++
  
  int foo(int x, int y = 0)
  {
     std::cout << "1\n";
  }  

  int foo(int x = 0)
  {
     std::cout << "2\n";
  }

  int main()
  {
     foo(1,2); //prints 1
     foo(1); //???
     foo(); //prints 2

     return 0;
  }

  
----

inline
======
* serves as a indicator to the optimizer.
* non binding.
* compilers are free to inline any function not marked inline.
* compilers are free to use a function calls for functions marked inline. 
* should be placed in a header file. 
* increases the size of the code.

  * for very small functions in-lining may reduce size. 

* often the compiler will be able to apply context specific optimizations to code it couldn't do otherwise. 

.. code:: C++

  //HEADER FILE
  inline int foo(int x) {return x+1;} //explicit inlining 
  int bar(int x) {return x+1;} //implicit inlining because this is in a header.

----

Use of auto
===========

There are currently proposals for using auto for function parameters (i.e. that may be in C++17)
Currently you can use auto for the return type. 

* Auto can be used as parameters to lambdas in C++14
* Auto is the default return type for a lambda.  

----

trailing return type
====================

.. code:: C++

  //JUST BECAUSE YOU CAN DO THIS DOESN'T MEAN YOU SHOULD!!!

  auto foo(int x) -> int
  {
     return x+1;
  }

  auto main() -> int 
  {
    auto x = 0;
    while( x < 10 )
    {
      x = foo(x);
    }
    return 0;
  }

----

Calling conventions
===================

.. code:: C++

  //by value
  void foo(int x);

  //by reference
  void foo(int& x);

  //by const reference
  void foo(const int& x);

  //by pointer
  void foo(int * x);

.. note::

    Talk about why const ref isn't that valuable for fundamental types but for objects it is a good improvement. 

----

Calling Conventions
===================

From CppCoreGuidelines
----------------------

.. image:: images/param-passing-advanced.png
  :height: 500

----

Where to define variables
=========================

C89/90 Requires programmers to declare variables "at the top of the function" 

**Why you shouldn't do this**

* Encourages variable reuse.
* Hard to initialize with reasonable values.
* Item 26 in the Effective C++ says not to do this.
* Often you pay for construction twice. (once to initialize and once to give it a meaningful value)
* Often you may not need to pay for the construction. (return or exception thrown before use)


----

Lambda
======

.. code:: C++

    #include <vector>
    #include <algorithms>

    int main()
    {
        using uint = unsigned int;
        std::vector<unsigned int> data = {100, 0xDEADBEEF, ... }; //a bunch of "data";

        //LAMBDA TIME!
        std::sort(data.begin(), data.end(), [](uint a, uint b){return a < b;});

        //do stuff with your sorted data!
        return 0;
    }

----

Lambda Captures
===============

I want to use something that is in my local scope... 

* ``[ ]`` capture nothing
* ``[&]`` capture anything I use by reference
* ``[=]`` capture anything I use by value
* ``[x]`` capture x by value (value is the default)
* ``[&y]`` capture y by reference
* ``[x, &y]`` capture x by value and y by reference
* By value captures are treated as r-values. (unless lambda is declared mutable.)

.. note::
  Specifically ask, "Is there any reason the ones with the variables would be preferable to 2 and 3?". 

  The Lambdas project under the Functions solution can show some examples of these in use, but
  the next slide covers some stuff that is in that file so tell them you will show examples by wait for now. 

----

Lambda Gotcha?
==============

What does this print?

.. code:: C++

  std::function<int()> foo(int x)
  {
    static int y = 0; //important to note this is static (i.e. won't get cleaned up off the stack)
    static int z = 0;
    switch(x)
    {
      case 0: return [](){return 0;}; //return type is auto by default. 
      case 1: return [=](){return y++;}; //capture by value
      case 2: return [&](){return y++;}; //capture by reference

      default: return [&x](){return z++;}; //capture named by reference
    }
  }

  int main()
  {
    auto a = foo(0);
    auto b = foo(1);
    auto c = foo(2);
    auto d = foo(50);

    std::cout << a() << b () << c() << b() << d() << b() << c() << std::endl;
  }

.. note::
  static variables can't be captured... It is using the real static variables in the lambda. 
  ``[](){return y++}`` would to the same thing. 

----

Storage Classes
===============

* **Automatic**: All variables defined in a block that aren't one of the others. 
* **extern**: An object or variable in another translation unit. 
* **static**: Persist for the lifetime of the program, can be global, namespace, class or local scope

  * static variable retain their state

* **thread_local**: A variable that is only accessible on the thread which it is created. 

.. note:: 

  all lambda captures must be automatic. 

----

#include <functional>
=====================

Lots of neat things here. 
-------------------------

* ``std::bind`` - creates a function wrapper and lets you "bind" parameters to certain values. 
* ``std::function`` - creates a polymorphic function pointer. 
* Function objects for doing stuff
 
  * Arithmetic ``plus``, ``minus``, ``multiplies``, ``divides``, ``modulus``, ``negate``
  * Comparisons ``equal_to``, ``not_equal_to``, ``greater``, ``less``, ``greater_equal``, ``less_equal``
  * Logical ``logical_and``, ``logical_or``, ``logical_not``
  * Bitwise ``bit_and``, ``bit_or``, ``bit_xor``, ``bit_not``

.. note:: 
  Not really going to talk about the funciton object just know they are there and pretty cool. 

----

std::bind
=========

.. code:: C++

  std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};

  // std::multiplies<int>(a, b) takes two arguments. The transform function can only take one.
  // Here we are using multiplies to double each number.
 
  std::transform(vec.being(), vec.end(), vec.begin(), 
    std::bind(std::multiplies<int>(), std::placeholders::_1, 2));

.. note:: 

  what are some other ways we can get the same results?
  
  [](int a){
    return std::multiplies<int>(2, a); }

  Because of this there is really only a difference before C++14. This is because lambdas prior to C++14 are not polymorphic while bind is. I.E. bind is templated and can bind templated parameters so that the bind can be used with different types. 

---- 

std::function
=============

* Can hold more than functions

  * functors (You don't know what these are yet, although you have used them :) )
  * lambdas (really a special case of functors)

* Functions don't have the have the exact same signature... Just need to be compatible. 

.. code:: C++
 
  int foo(double x, int y);

  struct foo_functor {
    void operator()(float x, short y) const {}
  };

  std::function<int(double, int)> fn = foo;
  fn = foo_functor();