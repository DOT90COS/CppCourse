.. title:: Introduction

:css: CSS/course.css

----

Introduction.cpp
================
“C makes it easy to shoot yourself in the foot; C++ makes it harder, but when you do it blows your whole leg off.” 
― Bjarne Stroustrup

----

Sylabus.cpp
-----------

.. code:: C++

  void main()
  {
    if(!prerequisites())
      exit(ERROR_NOT_READY);
    if(!expectations())
      exit(ERROR_NOT_MOTIVATED);
    if(!content())
      exit(ERROR_WRONG_CONTENT);
    if(!references())
      exit(ERROR_NEEDS_SAFARI_ACCOUNT);
  }

----

:data-y: r800
:data-x: r0

.. code:: C++

  bool prerequisites()
  {
    return knowsAnotherLanguage();
  }

----

:data-y: r-800
:data-x: r0

----

:data-y: r1600
:data-x: r0

.. code:: C++

  bool expectations()
  {
    auto meetsExpectations = true;
    meetsExpectations = willingToTryNewThings() ? meetsExpectations : false;
    meetsExpectations = canUseGoogle() ? meetsExpectations : false;
    meetsExpectations = notExpert() ? meetsExpectations : false;
    return meetsExpectations;
  }

----

:data-y: r-1600
:data-x: r0

----

:data-y: r2400
:data-x: r0

.. code:: C++

  bool content()
  {
    auto hours = 8 * 5 * 3; //8 hours a day, 5 days a week, 3 weeks
    Course cppClass(hours);
    Section fundamentals;
    fundamentals.addLecture("History of C++");
    fundamentals.addLecture("The Basics... a refresher")
    fundamentals.addLecture("Types"); 
    fundamentals.addLecture("User defined types");
    fundamentals.addLecture("Exceptions");
    fundamentals.addLecture("Concrete Classes");
    fundamentals.addLecture("Abstract Classes");
    fundamentals.addLecture("Templates");
    cppClass.addSection(fundamentals);

    Section stdLib;
    stdLib.addLecture("Overview");
    stdLib.addLecture("STL Containers");
    stdLib.addLecture("std::memory");
    stdLib.addLecture("std::string");
    stdLib.addLecture("std::thread");
    stdLib.addLecture("regex")
    cppClass.addSection(stdLib);
    
    Section advanced;
    advanced.addLecture("Template Metaprogramming by Example");
    advanced.addProject("????")
    cppClass.addSection(advanced);
  }

----

:data-y: r-2400
:data-x: r0

----

:data-y: r0
:data-x: r1600

Gitlab
======

* Make sure everyone has an account. 
* Course wiki
* Benchmarking Library
* Unit Test Library
* CppCoreGuidelines.  

----

:data-y: r0
:data-x: r1600

Code of Conduct
===============

* Everyone is expected to do their own work. 
* Everyone is expected to not share their work with their neighbor until after an assignment is done. 
* If you get code off the internet put a comment in the code saying where you got it. 
* Ask Questions!
* My personal books do not leave the classroom (unless it is with me!)

----

:data-y: 0
:data-x: r1600

Instructor: Jeff Scaparra
=========================

Jeff@Scaparra.com
------------------
