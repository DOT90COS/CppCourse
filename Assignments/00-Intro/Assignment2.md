# Thing to value:

* Don't copy and paste code around, It makes it hard to maintain. (Fix a bug in one place and forget the other)
* Utilize types that do clean up for you when possible!

# Assignment 2.0:

1. Modify your Hello World program so that it can take a command line argument. Allow a user to pass a filename into the program. If the user supplies a command line argument "hello world" should output to a file.

2. Ask the user "What is your name?", when the program starts up. Allow the user to input a string and store their name in a std::string. Then instead of outputting "Hello, World!" output "Hello, < USER NAME >!"

* Program should always print to stdout but only sometimes print to a file. 
* Program should deal with being fed a file that doesn't exist. (printing a warning and exit is good). 

# Assignment 2.1:

Write a program called max that can read in 32 bit integers from a comma separated file. To make things a little easier files will contain 256 numbers or less. Store the numbers in an array and use a range-for to iterate through them looking for the Max number. Once you have found the max number print it to stdout. 

* Free all dynamically allocated memory. 
* Use functions to structure your code as needed. 
* An example data input is provided below. 
* Don't worry about dealing with malformed data files. 

# Bonuses

* Make max take an arbitrary number of elements and provide the Min, Max, and Median. 
  * Don't use any data structure to hold all the elements. Process them as you read them in. 

* Write a program that can take a Max Input file and sorts the elements writing them back out to a file with ".sorted" appended to the original name. (i.e. <input file name>.sorted ).

* Write a program to generate the random data for Max and the bonuses. 
  * Bonus Bonus - Look up the random functions in the standard library and use those.  (I didn't even do this!)
  

