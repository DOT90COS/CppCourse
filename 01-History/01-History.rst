.. title:: History 

:css: CSS/course.css

----

A Brief History of C++
======================
“There are only two kinds of languages; the ones people complain about and the ones nobody uses.” 
― Bjarne Stroustrup

.. note::
  When we take about C++ we have to really specify what iteration of C++ we are talking about. 
  C++ has changed dramatically over the years and even through recent times. It is important to 
  understand the evolution of C++ and the state of the standards, libraries, and compilers that 
  you will depend on to do your jobs. You will find many projects that are built on top of old runtimes
  for various reasons. The standard process has be revolutionized and moves quickly now. In this decade 
  there have been two standards release that dramatically changed the language and there will be one more
  with C++17. This is why we have a section on the history of C++. 

----

Current State of C++
====================

.. image:: images/wg21-timeline.png
  :width: 900px
  :align: left
  :alt: C++ standards timeline.

----

.. image:: images/dennis_richie.gif

**In 1970 Dennis Ritchie Introduces C**

Prior to this:
  * Systems programmers were expected to master machine language
  * Systems programmers wrote in assembly
  * Fortran and Cobol existed for domain specialist not "systems" programming

C gave systems programmers:
  * A high level language that was portable. 
  * Enough control to do most systems programming 

.. note::
  What were Cobol and Fortran domain languages for?

  COmmon Business Oriented Language - as the expanded acronym indicates, COBOL is designed for 
  developing business, typically file-oriented, applications. 

  Fortran "Formula Translation" - numeric computation and scientific computing. 


----

C with Classes
==============

**Bjarne Stroustrup** at Bell Labs develops his own language.

  * Motivated by higher-level programming languages like Simula

    * Simula supports object-oriented programming.
  * Based on C because of the power of C
  * C with classes ultimately turns into C++
  * C++ was a superset of C but had higher level objects 

    * This allowed users to create their own types. 

.. note:: 
  "Bjarne Stroustrup, a Dane with a Ph.D. from Cambridge University (England), had used the Simula 
  language for distributed systems simulations in his research. He was disappointed with its poor 
  performance, however, and in 1979 when his new employer, AT&T Bell Labs, said "Do something interesting", 
  he decided to infuse the C language with some Simula features he had grown accustomed to -- most notably classes -- 
  and thus "C with Classes" was born. It caught on within AT&T, was dubbed C++, and then proceeded to become a support 
  burden for its inventor.  -- taken from http://www.stroustrup.com/cuj_interview.html

----

Factoids 
========

  * First C with classes compiler was called "Cfront" which was derived from a C compiler called CPre
  * Cfront was written mostly in C with Classes, making it a compiler that could compile itself. 
  * The name C with classes was changed in 1983 to C++ and new features were added

    * virtual functions
    * function overloading
    * references
    * const
    * single-line comments


----

Road to Standardization
=======================

* 1985 "The C++ Programming Language" first edition is released
* Popularity soars into the 90s largely credited to OOP and GUI programming
* A decision to standardize the language is made and group has first meeting in 1989

  * The language will be controlled by a group of people instead of one member.
  * Stroustrup remains an influential member to the ISO C++ committee to this day. 
  * First goals were to standardize iostreams, add templates, and exceptions.

.. note::
  * The 1985 was a very important reference as the language wasn't standardized yet. 

----

Lack of standard library
========================
  
* 1993 Standard was almost complete.
* Committee felt there wasn't a good enough standard library. 
* Alex Stepanov gave a presentation on generic programming which put templates to good use. 
* By the next meeting Stepanov had refined the "Standard Template Library".
* The committee liked it even if it delayed the completion of the standard. 
* It wasn't until 1998 that the C++ standard was finalized. 

.. note::
  This were winding down in 1993 but uneasiness about a lack of robustness in the standard library cause . 

----

Boost
=====

* Also in 1998 Beman Dawes with Library Working Group chair, set up the Boost Libraries. 
* Libraries that might be candidates for standardization could be vetted and popularize.
* Boost is separate from the standards process. 
* Library writers don't have to submit their libraries to boost but is usually happens that way.

.. image:: images/boost.jpg
 
----

C++ as a superset of C
======================

* **Pros**

  * Instant access to all libs written in C
  * Introduce safer ways to deal with resources RAII
  * Higher-level concepts (Generic but most of this class will be teaching this.)

* **Cons**
  
  * Inherits all of C's baggage
  * Making more powerful user-defined types of C++ integrate
    with C so that they behave the same was also difficult.   

.. note::
  I thought this was the appropriate place for this because before C++11 this is largely how 
  C++ was thought of. 

  C baggage... 
  Memory management... 
  Non-safe functions... 
  Redundant non-generic code. 
  Unsafe returned values. 
  Uninitialized variables. 
  Unsafe arrays. 

----

C++03
=====

Not much changed...

Really. 

The differences are so few and so technical that they ought not concern users [1]_. 


.. [1] ftp://ftp.research.att.com/pub/c++std/WP/CD2

----

C++0x
=====

"C++0x is a relict of the days where I and other, hoped for a C++08 or C++09. Think of 'x' as 
hexadecimal (i.e., C++0B == C++11)" - Stroustrup

  * C++11 incorporates a lot of new features and getting all of that in took time. 

  * Concepts were voted out in 2009 because of their complexity and the fact that they would have further delayed the release of the standard [2]_.

.. [2] http://www.drdobbs.com/cpp/the-c0x-remove-concepts-decision/218600111

.. note:: 
  C++0x was the original name of the next version of the standard. It was labeled C++0x because it was supposed to be done sometime in the 2000s.


----

C++11 Language Features
=======================

**"Surprisinglly, C++11 feels like a new language" - Stroustrup**

Some of the `features`_:

* `initializer-list`_
* `uniform initialization`_
* `template aliases`_
* `rvalue references`_ and move semantics
* `defaulted and deleted functions`_
* `variadic templates`_
* `auto`_
* `inherited constructors`_
* `decltype`_

.. _features: http://www.stroustrup.com/C++11FAQ.html#language
.. _initializer-list: http://www.stroustrup.com/C++11FAQ.html#init-list
.. _uniform initialization: http://www.stroustrup.com/C++11FAQ.html#uniform-init
.. _template aliases: http://www.stroustrup.com/C++11FAQ.html#template-alias
.. _rvalue references: http://www.stroustrup.com/C++11FAQ.html#rval
.. _defaulted and deleted functions: http://www.stroustrup.com/C++11FAQ.html#default
.. _variadic templates: http://www.stroustrup.com/C++11FAQ.html#variadic-templates
.. _auto: http://www.stroustrup.com/C++11FAQ.html#auto
.. _inherited constructors: http://www.stroustrup.com/C++11FAQ.html#inheriting
.. _decltype: http://www.stroustrup.com/C++11FAQ.html#decltype

.. note::
  IMHO the best feature and the one that added the most performance was rvalue references and move semantics. 

----

C++14 Language Features
=======================

* Return type deduction for functions
* Generic lambdas
* Extended capturing in lambdas
* Revised restrictions on constexpr functions
* constexpr variable templates

http://cpprocks.com/an-overview-of-c14-language-features/

.. note::

  not as much stuff as C++11 but didn't take as long to get out. Notice concepts still aren't in the language and were voted out of C++17 as well. 

----

State of the compiler
=====================

There are three dominant compilers

* MSVC - Microsoft Visual C++ 
* G++ - Gnu C++ compiler
* clang - An opensource frontend, part of the LLVM compiler Infrastructure. 
 
.. note::
  Add links... 

  Add information about each and how they related (maybe a link to a comparison with a break down of supported features)

  I didn't want to put the features supported of each in this slide as that will change over time. 

----

Resources
=========

* `cppreference.com`_
* `C++ Core Guidelines`_ and the `talk on them`_

.. _cppreference.com: http://en.cppreference.com
.. _C++ Core Guidelines: https://github.com/isocpp/CppCoreGuidelines
.. _talk on them: https://www.youtube.com/watch?v=1OEu9C51K2A
