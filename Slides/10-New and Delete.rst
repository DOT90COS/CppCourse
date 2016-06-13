.. title:: New and Delete

:css: CSS/course.css

----

Working with Dynamic Memory
===========================

Using ``new`` and ``delete``
----------------------------

.. code:: C++

    int* ptr = new int;

    delete ptr;

----

Allocating arrays
=================

.. code:: C++ 

    int* ptr = new int[25];

    delete[] ptr;

----

Initializing Allocation
=======================

.. code:: C++

    int* ptr = new int(30); //Initializes the value pointed to with 30
    int* ptr = new int[30](); //Initializes a int array of 30 elements to 0

* There is no way to initialize an array with anything other than 0. 

----

Avoid naked "new" and "delete"
==============================

* Avoid allocations in general code
   
   * Keep allocations buried inside the implementation of "well-behaved abstractions"

* Makes code far less error-prone 

