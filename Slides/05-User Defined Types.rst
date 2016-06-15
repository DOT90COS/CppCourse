.. title:: Objects

:css: CSS/course.css

----

Building Objects
================
.. image:: images/Douglas_McIlroy.jpeg

"Those types are not "abstract"; they are as real as ``int`` and ``float``. -- Doug McIlroy

----

structs and classes
===================

structs and classes are really the same things with slightly different meanings

* a ``struct`` has a default access-specifier of public
* a ``class`` has a default access-specifier of private

So a ``struct`` and a ``class`` are functionally equivalent.
**BUT** in real life it is generally accepted that a ``struct`` is a pile of bits with very little in the way of encapsulation or functionality, while a ``class`` generally has more intelligence and responsibility. This should become more clear as we look at more examples.

.. note::

  This really goes back to C++'s history. People tend to use structs like they would in C and classes for object oriented programming. 

----

Class Basics
============

* A class is a user-defined type.
* Consists of a set of members (data and functions).
* Member functions can define the meaning of:
  
  * initialization (creation)
  * copy
  * move
  * and cleanup (destruction)

* Members are accessed using ``.`` for objects and ``->`` for pointers.
* Operators, such as ``+``, ``!``, and ``[]``, can be defined for a class.
* A class is a namespace containing its members.
* The ``public`` members provide the class interface.
* The ``private`` members provide the implementation.
* A ``struct`` is a ``class`` where members are by default public.

----

A Simple Class
==============

.. code:: C++

    class X {
        public:  // The user interface
          X(int i = 0):m_(i) {} // A constructor (initializes member m_)

          int member_function(int i) // A Member Function
          {
            int old = m_;
            m_ = i;                  // sets the new value
            return old;              // returns the old value
          }

        private:  // the representation (implementation) is private
          int m_;
    };

    X var {7};

    int user(X var, X* ptr)
    {
        int x = var.member_function(7);  // Access using . (dot)
        int y = ptr->member_function(9); // Access using -> (arrow)
        int z = var.m_; // ERROR can't access private member variable. 
    }

----

Initialization Methods
======================

There are four ways to initialize objects in C++11.

* with ``()``
* with ``= (This is not an assignment)``
* with ``{}`` 
* and with ``= {}`` (C++ usually, treats this the same as just ``{}``)

* List initialization (curly braces ``{ }``) is preferred as it does not allow narrowing. 
  
.. code:: C++ 

    void fun(double val, int val2) {
        int x2 = val; //if val==7.98, x2 becomes 7 (bad)
        char c2 = val2; //if val2 == 1025, c2 becomes 1 (bad)
        int x3 {val}; //error: possible truncation (good)
        char c3 {val2}; //error: possible narrowing (good)
        char c4 {24}; //OK: 24 can be represented exactly as a char (good)
        char c5 {264}; //Error (assuming 8-bit char): 264 cannot be represented as a char (good)
        int x4 {2.0}; //error: no double to int value conversion (good)
    }

.. note::
  Look at Effective Modern C++ Item 7 for more information. 

----

When to not use list initialization
===================================

* With ``auto`` types

  * When initializing ``auto`` with braces the deduced type is std::initializer_list

* When a constructor of a type takes an std::initializer_list and that isn't what you want. 
  
  * The initializer_list is a more specific match and therefore uses that. 

.. code:: C++

    class Widget {
        public: 
          Widget(int i, bool b);
          Widget(std::initializer_list<long double> il);
          };

          Widget w1(4, true); // Calls Widget(int i, bool b);
          Widget w2(w1); //Calls copy constructor (not shown)
          Widget w3{w1}; //Calls the copy constructor
          auto w4 = {4, true}; //w4 is now an std::initializer_list unrelated to Widget.
          auto w5 = Widget{5, true}; //w5 will be a Widget initialized with initializer list.
          auto w6 = Widget{1, 2}; //w6 will be a Widget initialized with initializer list. 
          auto w7 = Widget{w4}; //Copy or move constructor

}

note:: 

  Do the initialization exercise and go over the results. 

----

Construction
============

* A class can have as many constructors as it wants. 
* If a class doesn't supply a copy or move constructor the compiler will try to make one for you. 
  
  * If the class is simply a plain old data type then the ``default`` constructor will be more efficient. 

* C++11 Defines copy constructors as well as move constructors. 

  * Copy constructors are called when the object passed in is an L-Value
  * Move constructors are called when the object passed in is an R-Value

* A default constructor is one that can be called with no arguments. (In some cases this doesn't make since, so don't give your class one.)

* Constructors can be ``default`` ed or even ``delete`` ed.

----

Plain Old Data-Type (POD)
=========================

C++11 relaxes the rules for PODs and further splits them into two categories. 

* Supports static initialization (Trivial Class)
* Same memory layout as a struct compiled in C. (Standard-layout)

----

Trivial Classes
===============

* has no non-trivial copy constructors
* has no non-trivial move constructors
* has no non-trivial copy assignment operators
* has no non-trivial move assignment operators
* has a trivial destructor

Benefits

* static initialization and ok to memcpy

----

Trivial Examples
================

.. code:: C++

    struct Trivial1{}; //empty classes are trivial

    struct Trivial2 {
        int x;
    };

    struct Trivial3 : Trivial2 {
        Trivial3() = default; //not user provided
        int y;
    };

    struct Trivial4 { //no restrictions on access modifiers
        public: 
        int a;
        private: 
        int b
    };

    struct Trivial5 {
        Trivial1 a;
        Trivial2 b;
        Trivial3 c;
        Trivial4 d;
    };

    struct Trivial6 {
        Trivial5 a;
        void f(); //Its ok to have non-virtual functions. 
    };

----

Standard Layout
===============

These are types that are useful for communicating with other languages. This is because they have the same memory layout as a struct or union in C. 

* Has no non-static data members of type non-standard-layout class or reference
* Has no virtual functions and no virtual base classes
* Has no non-standard-layout base classes
* Has the same access control for all non-static data members. 
* Either has no non-static data members in the most derived class and at most one base class with non-static data members, or has no base classes with non-static data member
* Has no base classes of the same type as the first non-static data member. 

---- 

Standard Layout Examples
========================

.. code:: C++

    // empty classes have standard-layout
    struct StandardLayout1 {};

    struct StandardLayout2 {
        int x;
    };

    struct StandardLayout3 {
    private: // both are private, so it's ok
        int x;
        int y;
    };

    struct StandardLayout4 : StandardLayout1 {
        int x;
        int y;

        void f(); // perfectly fine to have non-virtual functions
    };

    struct StandardLayout5 : StandardLayout1 {
        int x;
        StandardLayout1 y; // can have members of base type if they're not the first
    };

    struct StandardLayout6 : StandardLayout1, StandardLayout5 {
        // can use multiple inheritance as long only
        // one class in the hierarchy has non-static data members
    };

    struct StandardLayout7 {
        int x;
        int y;
        StandardLayout7(int x, int y) : x(x), y(y) {} // user-provided ctors are ok
    };

----

Standard Layout Examples 
========================

.. code:: C++ 

    struct StandardLayout8 {
    public:
        StandardLayout8(int x) : x(x) {} // user-provided ctors are ok
    // ok to have non-static data members and other members with different access
    private:
        int x;
    };

    struct StandardLayout9 {
        int x;
        static NonStandardLayout1 y; // no restrictions on static members
    };

    struct NonStandardLayout1 {
        virtual f(); // cannot have virtual functions
    };

    struct NonStandardLayout2 {
        NonStandardLayout1 X; // has non-standard-layout member
    };

    struct NonStandardLayout3 : StandardLayout1 {
        StandardLayout1 x; // first member cannot be of the same type as base
    };

    struct NonStandardLayout4 : StandardLayout3 {
        int z; // more than one class has non-static data members
    };

    struct NonStandardLayout5 : NonStandardLayout3 {}; // has a non-standard-layout base class

----

Constructors
============

Basic constructors are written with the name of the class as a function with no return type. 

.. code:: C++

    class MyClass {
    public:
        MyClass() {} //sets x_ to 0 
        MyClass(int x): x_(x) {} //sets x_ to x

    private:
        int x_ = 0; //Default initialization
    };

----

Initialization list in constructors
===================================

What was that funny ``: x_(x)`` in the previous example. It was an initialization list. 

These initialize your member data and are more efficient than copying them to the stack and then setting the data inside of the constructor. In other words it allows the compiler to do some optimization. 

The order that the member variables appear in the initialization list must be in the same order that they are defined in the class or struct. 

.. code:: C++

    class MyClass {
    public:
        MyClass(int a, int c, int d): a_(a), 
                                      // I skipped b_ but that is ok we are still in order. 
                                      c_(c), 
                                      d_(d) 
        {

        } 

    private:
        int a_ = 0;
        int b_ = 0; 
        int c_ = 0; 
        int d_ = 0; 
    };

----

Copy Construction
=================

This is a special constructor that allow for a new object to be built from a similar one. 

.. code:: C++

    Class MyClass {
        MyClass() {} //default constructor

        //Copy constructor. 
        MyClass(const MyClass& n) { //do what is needed to make a copy} 
    };

.. note:: 
  I specifically say similar here because it is possible to build a base class object from a derived class object so long as the base class isn't pure virtual. 

----

Move Constructor
================

With C++11 and beyond there is a new type of constructor specifically for R-Values that has the ability to greatly speed up code.
That is the move constructor. Because the object being moved from is a temporary there is no need to keep any of its state valid. This means that pointers to dynamically allocated memory for example can just be moved over and not necessarily the data. 

.. code:: C++

    Class X {
        int* v_;
        int size_;

    public:
        X():v_(new int[42]), size_(42) { }
        X(const X& n):v_(new int[n.size_]), size_(n.size_) {
            for( auto i = 0U; i < size_; ++i )
                v_[i] = n.v_[i]; //copy each element. 
        }
        X(X&& n):v_(n.v_), size_(n.size_) { n.v_ = nullptr; } //Much simplier.
        ~X(){if(v_) delete[] v_;}
    };

----

Delegating Constructor
======================

If you want two constructors to do similar things pre-C++11, you could repeat yourself or write an initialization function to preform the common actions. 

.. code:: C++ 

    class X 
    {
        int a_; 
        validate(int x) { if (0 < x && x <= k_max) a_ = x; else throw Bad_X(x); } 
    public:
        X(int x) {validate(x);}
        X() {validate(42);}
        X(const std::string& s){int x=to<int>(s); validate(x);} 
    };

.. note::
    This is the better of the two options. Copy Pasta is bad because often times one will get a bug fix while the other will be forgotten about. It is just hard to maintain. 

----

Delegating Constructor Cont...
==============================

In C++11 we can do better with delegating constructors.

* A constructor can not delegate and explicitly initialize a member.
* Delegating by calling another constructor in a constructors member is most likely an error.

.. code:: C++

    class X 
    {
        int a_;
        double b_;
    public:
        X(int a):b_(0) {if (0<x && x<k_max) a_ = x; else throw Bad_X(x);}
        X(double b) : X{42}, b_(b) {} // ERROR Can't delegate and explicitly initialize another variable. 
        
        // ERROR: This creates a X object with the X(int) constructor inside of the X() constructor 
        // as a temporary on the stack!!!
        X() { X{42}; } 

        X(): X{42} //GOOD! no problems in C++11. 
    };

----

In class Initializers
=====================

* The () operator cannot be used in an in class initializer. 
  * This is due to how parsing and name lookup occur. 

.. code:: C++

    class X 
    {
        int a_ {42};
        int b_ = 12;
    public:
        X() {}; //initializes a_ to 42
        X(int a): a_(a) {}; //initializes a_ to a instead. 
    };

----

DTOR (Destructor)
=================

* Can automatically generated if you don't need any special clean up. 
* Can be used to free memory
* Can be used to free resources
* Likely shouldn't throw exceptions, otherwise:
 
  * Your object can't be used in standard containers
  * A throw will call std::terminate in C++11

.. code:: C++ 

    class Widget {
    public:
        Widget() { a_ = new int[4]; }
        ~Widget() { delete [] a_; }

    private:
        int* a_;
    };

----

Resource Acquisition is Initialization (RAII)
=============================================

One of the more powerful concepts in C++. 
This is a C++ technique that ties a resource (memory allocation, threads, sockets, files, database connection) lifetime to the lifetime of an object. 

* The constructor acquires the resource.
* The destructor releases the resource.  

----

RAII Example
============

.. code:: C++

    class File
    {
        HANDLE file_ = INVALID_HANDLE;
        File(const std::string& filename){
          file_ = openFile(filename);
        }

        ~File() {closeFile(file_);}
    };

.. note:: 

  This is all made up to be platform agnostic. 

----

Member Functions
================

They really aren't that special other than they have access to all of the member variables. 

.. code:: C++ 

    class Point {
        int x_ = 0;
        int y_ = 0;
        int z_ = 0;
    public:
        void move(int x, int y, int z){x_ += x; y_ += y; z_ += z;}
        int x() {return x_;}
        int y() {return y_;}
        int z() {return z_;}
    };

----

Operator Overloading 
====================

To overload operators we use special member functions that start with operator followed by the operator symbol we want to overload. 

.. code:: C++

    Complex {
        double r_; 
        double i_; 

    public:
        ...

        Complex& operator=(const Complex& num); //copy assignment.
        Complex& operator=(Complex&& num); //move assignment. 
    };

----

Generating Default Operations
=============================

The compiler can and will generate:

* A default constructor: ``X()``
* A copy constructor: ``X(const X&)``
* A copy assignment: ``X& operator=(const X&)``
* A move constructor: ``X(X&&)``
* A move assignment: ``X& operator=(X&&)``
* A destructor: ``~X()``

By default the compiler will generate each of these if a program uses them. However if the programmer takes control by defining one or more of these operations, the generation of related operations is suppressed. 

* declares a constructor for a class, the default is not generated for that class. 
* declares a copy operation, a move operation, or a destructor for a class, then no copy operation, move operation, or destructor is generated. 

----

Default and Delete
==================

In order to get the suppressed operations back we can use the ``default`` keyword. 
In order to ensure that a operation is not generated we can use the ``delete`` keyword.

.. code:: C++

    //A Class that can only be moved and not copied. 
    class Thing
    {
        std::array<42, int> a_;
    public:
        Thing() = default;
        Thing(const Thing&) = delete;
        Thing(Thing&&) = default;
        Thing& operator=(const Thing&) = delete;
        Thing& operator=(Thing&&) = default;
    };

----

Rule of Three
=============

C++ (pre 11) If a class requires a user-defined destructor, a user-defined copy constructor, or a user-defined copy assignment operator, it almost certainly requires all three. 

These special member functions if not specifically defined will be implicity defined by the compiler. The compiler will copy them by value resulting in a shallow copy of pointers, handles and other non-trivially copyable types. 

.. code:: C++

    class rule_of_three
    {
        char* cstring; // raw pointer used as a handle to a dynamically-allocated memory block
     public:
        rule_of_three(const char* arg)
        : cstring(new char[std::strlen(arg)+1]) // allocate
        {
            std::strcpy(cstring, arg); // populate
        }
        ~rule_of_three()
        {
            delete[] cstring;  // deallocate
        }
        rule_of_three(const rule_of_three& other) // copy constructor
        {
            cstring = new char[std::strlen(other.cstring) + 1];
            std::strcpy(cstring, other.cstring);
        }
        rule_of_three& operator=(const rule_of_three& other) // copy assignment
        {
            char* tmp_cstring = new char[std::strlen(other.cstring) + 1];
            std::strcpy(tmp_cstring, other.cstring);
            delete[] cstring;
            cstring = tmp_cstring;
            return *this;
        }
    };

----

Rule of Five
============

C++ complicates the rule of three because of move constructors and move assignment operators. These must also be added to the list. 


Code too big ... next slide.

----

.. code:: C++

    class rule_of_five
    {
        char* cstring; // raw pointer used as a handle to a dynamically-allocated memory block
     public:
        rule_of_five(const char* arg)
        : cstring(new char[std::strlen(arg)+1]) // allocate
        {
            std::strcpy(cstring, arg); // populate
        }
        ~rule_of_five()
        {
            delete[] cstring;  // deallocate
        }
        rule_of_five(const rule_of_five& other) // copy constructor
        {
            cstring = new char[std::strlen(other.cstring) + 1];
            std::strcpy(cstring, other.cstring);
        }
        rule_of_five(rule_of_five&& other) : cstring(other.cstring) // move constructor
        {
            other.cstring = nullptr;
        }
        rule_of_five& operator=(const rule_of_five& other) // copy assignment
        {
            char* tmp_cstring = new char[std::strlen(other.cstring) + 1];
            std::strcpy(tmp_cstring, other.cstring);
            delete[] cstring;
            cstring = tmp_cstring;
            return *this;
        }
        rule_of_five& operator=(rule_of_five&& other) // move assignment
        {
            delete[] cstring;
            cstring = other.cstring;
            other.cstring = nullptr;
            return *this;
        }
    };

----

Make Data Members Private
=========================

This has to do with the ability to maintain an invariance in your types. 

* An invariance is defined by the set of valid values for data members.
* Keeping the implementation separate from the design allows for easier refactoring of that implementation in the future. 

.. code:: C++

    class Date {
        int month_ = 0; //valid (00 .. 11)
        int day_ = 0; //valid (00 .. 31) 
        int year_ = 0; //valid (00 .. 2050)

    public : //Things that are public define the interface to the user. 
       Date() {}
       Date(int month, int day, int year):month_(month), day_(day), year_(year) {}

       int getMonth() const { return month_; }
       int getDay() const {return day_; }
       int getYear() const {return year_; }
       void setYear(int year) {
         year_ = year >= 00 && year <= 2050 ? year : throw std::runtime_error("Bad Year");
       }
       void setDay(int day) {
         day_ = day >= 0 && day <= 31 ? day : throw std::runtime_error("Bad Day");
       }
       void setMonth(int month) {
         month_ = month >= 0 && month <= 31 ? month : throw std::runtime_error("Bad Month");
       }
    };

This code doesn't maintain its invariance correctly. How can it be fixed?

.. note:: 

    The constructor for Date allows for invalid values to make it into the objects data members.
    By keeping the data members private we can also add things in the future and adapt the type more easily. One such example would be to add the ability to make this object thread safe if we started to use this code in multi-threaded code.  

----

Make Interfaces That Are Easy To Use
====================================

The goal is "if an attempted use of an interface won't do what the client expects, the code won't compile; and if the code does compile it will do what the client wants" - Scott Meyer Item 18 Effective C++

.. code:: C++

  Date(30, 03, 1999); //opps wrong order.
  Date(03, 30, 1999);

One way to prevent client errors is by introducing new types:
* Make Month, Day, Year their own types?

  * enum class
  * structs
  * classes

----

Date
====

.. code:: C++

    struct Day {
        explicit Day(int d):val_{d}{}
        int val_;
    };

    struct Month {
        explicit Day(int d):val_{d}{}
        int val_;
    };

    struct Year {
        explicit Day(int d):val_{d}{}
        int val_;
    };

    class Date {
        Day day_{0};
        Month month_{0};
        Year year_{0};

    public:
        Date(const Month& month, const Day& day, const Year& year):
            month_{month}, day_{day}, year_{year} {}
            ...
    };

    Date d(30,3,1995); //ERROR wrong types
    Date d(Day{30}, Month{3}, Year{1995}); //Error, wrong types (cause of order)
    Date d(Month{3}, Day{30}, Year{1995}); //Works.

.. note:: 

  This could be made better yet if we somehow relate the days, months, and year all together. This way we can correctly check the number of days and on those leap years now if February has 28 or 29 days. For now lets say this check should be done at run time but we may be able to do something with inheritance. 

  

----



Treat Class Design as Type Design
=================================

* How should object of your new type be created and destroyed? 
    * How this is done will influence your constructors and destructors.
    * This could also involve how you handle memory allocation if you used that. 
* How should object initialization differ from object assignment?
    * The behavior of constructors compared to assignment will answer this question.
* What does it mean for objects of your type to be passed by value?
  * Need to consider by value for both R-Values and L-Values.
  * This means both the copy and move constructors
* What are the restrictions on legal values for your new types?
  * Usually, only some values of a class's data members are valid. 
  * The combination of valid values defines the invariance that your class will have to maintain
* What standard functions should be disallowed?
  * Those should be deleted (C++11 and beyond), or made private (pre C++11)
* Who should have access to the members of your new type?
  * This determines friendships and which members are public, protected, or private as well as whether or not to nest a class inside another. 
* How general is your new type? 
  * Perhaps it would be better as a template?

----

The End
=======

