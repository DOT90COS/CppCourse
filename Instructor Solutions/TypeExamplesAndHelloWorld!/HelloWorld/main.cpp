
// This is a #include... notice there is no .h at the end. 
// The standard doesn't say that the standard library include files have to have 
// the .h. Additionally they don't even have to be on disk. This is really up to
// the implementer. The most common compilers typically do have files on disk with 
// the library names. Your headers will have a .h and will look more like your used
// to if your fimilar with C.
#include <iostream>

//We can also utilize C headers but should use the standard libraries implementation. 
//The standard library will overload functions so that they are more useful for template 
//programming as well as include them in the std namespace. 
#include <cstdio>

//See http://en.cppreference.com/w/cpp/header for a list of headers in the standard library. 

// typically I won't use using namespace... but I haven't talked about them.
// For now ignore. 
using namespace std;

// Below is the definition for main.
// Main is a special program in C++.
// From http://en.cppreference.com/w/cpp/language/main_function
// 1. main cannot be used anywhere in the program
//    a. in particular, it cannot be called recursively
//    b. its address cannot be taken
// 2. It cannot be predefined and cannot be overloaded:...
// 3. It cannot be defined as deleted or declared inline, static, or constexpr (since C++17)
// 4. The body of the main function does not need to contain the return statement: if control 
//    reaches the end of main without encountering a return statement, the effect is that of 
//    executing 'return 0;'.
// 5. ... long way to say stuff gets destroyed and then std::exit with the return value is called. 
// 6. ... destructors throwing if main is wrapped with try catch don't actually throw. 
// 7. (since C++14) The return type of the main function cannot be deduced... no auto main(). 

int main(int argc, char* argv[])
{
   //Print out command line args.
    for (auto i = 0U; i < argc; ++i) //unsigned int 
        std::cout << argv[i] << std::endl;

	cout << "Hello World once!\n";
   
	cout.flush();

	//or
	cout << "Hello World twice!" << std::endl;

	//We can use printf too... We did include cstdio after all. 
	printf("Hello World and a third time!\n");

	//This is the exit code of the program...
	//In linux with bash you can see the exit code of the previous program with 'echo $?'
	//In windows echo %errorlevel%
	//In windows with gui applications use 'start /wait guiapp.exe' to launch the application 
	//and then 'echo %errorlevel%' to see the error code. 
	return 0;
}