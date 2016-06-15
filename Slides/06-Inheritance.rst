.. title:: Inheritance

:css: CSS/course.css

----

Object Inheritance and Polymorphism
===================================

.. image:: images/stdExceptions.png

Abstraction is a selective ignorance. -- Andrew Koenig

.. note::

  The image is taken from The C++ Standard Library: A Tutorial and Reference (2nd Edition).

----

Introduction
============

The primary focus of this section is to outline some design techniques, rather than just language features. Designs of class hierarchies can often be a good way of simplifying a complex problem. Computer Science heavily utilizes abstractions to solve real problems and inheritance is one type of abstraction mechanism provided by C++.

Hierarchies offer two kinds of benefits

* Interface inheritance: Provides a contract that can allow for various types to be derived and access through. 
* Implementation inheritance: Simplifies the implementation of derived classes. 

----  

Implementation of Inheritance
=============================

.. code:: C++

    #include <string>
    #include "timepoint.h"

    class Person
    {
        std::string first_name_;
        std::string last_name_;
        std::chrono::system_clock::time_point birthday_;

    public:
        Person(std::string first_name, std::string last_name);
        ~Person();

        void setBirthday(int year, int mon, int day, int hour = 0, int min = 0, int sec = 0);

        std::string getBirthday() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getName() const;
    };

----

Implementation of Inheritance
=============================

.. code:: C++

    #include "Person.h"
    class Employee :
        public Person
    {
        int employeeNumber_;
    public:
        Employee(std::string first, std::string last, int employeeNumber);
        ~Employee();

        int getEmployeeNumber() const;

        void getEmployeeNumber(int num);
    };

----

Implementation of Inheritance
=============================

.. code:: C++

    void printPeople(const Person& person)
    {
        std::cout << person << std::endl;
    }

    int main()
    {
        Person me("Jeff", "Scaparra");
        me.setBirthday(1984, 2, 25, 3, 34);

        printPeople(me);

        Employee aaron("Aaron", "Bray", 42 );
        aaron.setBirthday(1987, 3, 2, 10, 30);

        printPeople(aaron);

        return 0;
    }

----

Access Controls
===============

* *private*: can only be accessed by member functions and friends of the class
* *protected*: can only be acceess by member functions and freidns of the class and of derived classes. 
* *public*: its name can be used by any function

.. image:: images/accessControl.png

----

Inheritance Types
=================

.. code:: C++

    class Employee :
        public Person
    {

* public 
* private
* virtual 

----

Is-A Inheritance
================

Public inheritance is "Is-A" Inheritance. In the previous example:

* an Employee object could be used where a Person was because an Employee is a Person. 
* a Person could *NOT* be used where an Employee was because not all Persons are Employees.

This sounds simple but can be problematic. 

----

Is-A Inheritance
================

Can a penguin fly?

.. code:: C++

    class Bird {
        public: 
        virtual void fly();
        ...
    };

    class Penguin: public Bird {
        ...
    };

.. note::

    This example is taken from Item 32 of Effective C++
    Now we have a problem. This hierarchy says that penguins can fly, which we know is not true.
    There are a few ways to fix this problem

    *  If your application doesn't need birds to fly (Maybe you only care about beaks and wings) then you can remove fly and get on with your life.
    *  You could a Bird base class without fly and derive a FlyingBird class from that for flying birds and use the base Bird for non-flying birds. 
    * You could override fly and have it be a run-time error for Penguin. 

----

Is-A Inheritance
================

.. code:: C++ 

    class Bird {
        ...
    };

    class FlyingBird : public Bird {
        public:
        virtual void fly();
        ...
    };

    class Penguin: public Bird {
        ...
    };

----

Is-A Inheritance
================

.. code:: C++ 

    class Bird {
        public: 
        virtual void fly();
        ...
    };

    class Penguin: public Bird {
        public:
        virtual void fly() {error("Attempt to make a penguin fly!");}
        ....
    };

Which way is better?

.. code:: C++ 

    Penguin p;
    p.fly();

.. note:: C++ 

  In most cases you should prefer compiler errors over runtime errors. 

----

Virtual
=======

Virtual functions allow for polymorphism. When we say a function is virtual this means that it can be overridden by a derived class. 

.. code:: C++ 

    class Base {
    public:
        void foo() { std::cout << "Base::foo\n"; }
        virtual void bar() { std::cout << "Base::bar\n"; }
    };

    class foobar : public Base
    {
    public:
        void foo() { std::cout << "foobar::foo\n"; }
        void bar() { std::cout << "foobar::bar\n"; }
    };

    int main()
    {
        foobar a;
        Base b = a;
        Base& c = a;

        a.foo(); //foobar::foo
        b.foo(); //Base::foo
        c.foo(); //Base::foo
        a.bar(); //foobar::bar
        b.bar(); //Base::bar
        c.bar(); //foobar::bar
    }

----

Virtual
=======

* Functions that ``override`` a ``virtual`` function become ``virtual`` and don't have to be declared ``virtual``
* To be explicit that your overriding a ``virtual`` function use the ``override`` keyword
* To get polymorphic behavior objects must be accessed through a pointer or reference
* ``virtual`` functions work through a virtual function table
* Use ``final`` to describe a virtual function that shouldn't be ``override`` by another object. 

Use Virtual
-----------

* When defining and interface
* When we want derived classes to be able to change the function

----

override
========

* Note that override can do multiple things

  * Protects against typos
  * Makes it clear that a function is virtual
  * Clarifies a programmers intent

* ``override`` is not a keyword; it is a contextual keyword

  * Please don't be clever and use override for variable names. This was done for backwards compatibility not for modern use. 

.. code:: C++

    class base {
    public:
      virtual int makeMoney();
    }

    //This class should be marked as a defect in a code review. 
    class foo : public base{
    public:
      // A Typo (I forgot it was makeMoney)
      int getMoney(); //This doesn't override makeMoney but the programmer gets no error
    }

    class bar: public base {
    int override; //Showing that override can be used elsewhere.
    public: 
      int getMoney() override; //ERROR!!!
      //After getting the compiler error I fix the code
      int makeMoney() override; //clearly shows intent, OK!
    }

----

final
=====

In the rare case where we inherit from a virtual base class and answer no to:

* Can we imagine the need for further derived classes?
* Does a designer of a derived class need to redefine the function to achieve a plausible aim?
* Is correctly overriding a function straightforward.

After using final any attempt to override is an error.

.. code:: C++ 

    class X : public base {
        ...
        int foo() final;
    };

    class Y : public X {
        ...
        int foo() override; //ERROR
    };

* If the class should never be derived from we can apply the final keyword to the whole class

.. code:: C++

    class X final : public base {
        ...
        int foo() override; //overrides and is final
    };

.. note:: 

  One reason people use final is because of the optimization that it allows the compiler to do in some unique situations. (I.E. passing pointers or references to the Derived Class can be optimized away.)

----

Abstract Class (Interface)
==========================

This is another use for virtual where we don't provide a default implementation and these functions are known as pure virtual. 

Classes with pure virtual functions:
------------------------------------

* Cannot be instantiated.
* Can be used as pointers to store derived classes.  
* Is how we construct interfaces in C++

.. code:: C++

    class Slogan {
        virtual std::string slogan() const = 0; // A pure virtual function
    };

    class Trump : Slogan {
        ...
        std::string slogan() const override { return "Make America Great Again!"; }
    };

    class Clinton : Slogan {
        ...
        std::string slogan() const override { return "Hillary for America"; }
    };

.. note:: 

  Slogans taken from 
  * http://presidential-candidates.insidegov.com/stories/6557/campaign-slogans-presidential-candidate#5-Hillary-Clinton-Democrat
  * http://presidential-candidates.insidegov.com/stories/6557/campaign-slogans-presidential-candidate#20-Donald-Trump-Republican

----

Construction and Destruction 
============================

When we derive objects we often want to call the constructors of the base classes. 

.. code:: C++ 

    class Base {
        int x_ = 0;
    public:
        Base() = default;
        Base(int x):x_{x} {}
        virtual ~Base() {std::cout << "Base DTOR\n";}
        ...
    };

    class Derived : Base {
        int y_ = 0;
    public:
        Derived() = default;
        Derived(int x, int y):Base(x), y_(y) {}
    };

    int main() {
        Base b1;
        Derived d1;
    }

.. note:: 
    Show in VS2015

----

Inheriting Constructors
=======================

std::vector doesn't guarantee range checking. If I want to have all the same functionality as std::vector I may do something like:

.. code:: C++

    template<class T>
    struct Vector : public std::vector<T> {
        using size_type = typename std::vector<T>::size_type; // use vector's size type

        T& operator[](size_type i) { return this->at(i);} //use checked access
        const T& operator[](size_type i) const {return this->at(i)};
    }

    Vector <int> v {1,2,3,4,5}; //Error no initializer constructor

We don't inherit the constructors for Vector this way... :( 

----

Inheriting Constructors
=======================

.. code:: C++

    template<class T>
    struct Vector : public std::vector<T> {
        using size_type = typename std::vector<T>::size_type; // use vector's size type

        using std::vector<T>::vector //inherit vectors constructors

        T& operator[](size_type i) { return this->at(i);} //use checked access
        const T& operator[](size_type i) const {return this->at(i)};
    }

    Vector <int> v {1,2,3,4,5}; //OK uses std::vector initializer-list constructor. 

----

Inheriting Constructors
=======================

They can be problematic if you define new member variables that need explicit initialization. 

.. code:: C++

    struct B1 {
        B1(int) {}
    };

    struct D1 : B1 {
        using B1::B1; // implicitly declares D1(int)
        std::string s; //string has a default constructor
        int x; //we "forgot" to provide for initialization of x
    }

    struct D2 : B1 {
        using B1::B1; // implicitly declares D1(int)
        std::string s; //string has a default constructor
        int x {0}; //x is initialized
    }

    int main(){
        D1 d1a{6}; //d1a.x not initialized
        D1 d1b; //ERROR no default constructor
        D2 d2a{6}; //ok d2a.x is 0;
        D2 d2b; //Still an Error
    }

It is usually best to avoid being clever and restrict the use of inheriting constructors to times where you don't add any data members. 

----

Multiple Inheritance
====================


.. code:: c++

    class Animal {
     public:
      virtual void eat();
    };

    class Mammal : public Animal {
     public:
      virtual void breathe();
    };

    class WingedAnimal : public Animal {
     public:
      virtual void flap();
    };

    // A bat is a winged mammal
    class Bat : public Mammal, public WingedAnimal {
    };

    Bat bat;

----

Diamond Pattern 
===============

The code in the previous slide outlines a problem. 
If we want to call `bat.eat();` both of of base classes have an eat that they inherited from Animal.
Which do we call?

We could disambiguate:

.. code:: c++

    Bat b;
    Animal &mammal = static_cast<Mammal&> (b); 
    Animal &winged = static_cast<WingedAnimal&> (b);
    mammal.eat();
    winged.eat();

----

Diamond Pattern 
===============

A better solution is to use virtual inheritance which will guarantee that we only have one Animal class. 

.. code:: c++


    class Animal {
     public:
      virtual void eat();
    };

    class Mammal : public virtual Animal {
     public:
      virtual void breathe();
    };

    class WingedAnimal : public virtual Animal {
     public:
      virtual void flap();
    };

    // A bat is a winged mammal
    class Bat : public Mammal, public WingedAnimal {
    };

    Bat bat;

The animal portion of Bat::WingedAnimal and Bat::Mammal is now the same.

----

The END 
=======

