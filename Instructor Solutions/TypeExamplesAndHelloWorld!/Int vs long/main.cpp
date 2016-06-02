#include <iostream>

/******************************************************************************
The fact that this compiles shows that the compiler treats ints and longs as 
different types (even when they are the same size). This is because they aren't 
garanteed to be the same size. Microsoft picked machine architectures that cause 
them to be the same. 
*******************************************************************************/

void test(int a)
{
	std::cout << "a is an int!\n";
}


/* 

This function won't compile.

It has the same signature as one of the other functions. 

Does it overwrite void test(int) or void test(long)?

How can you tell?
*/

/*
void test(long int a)
{
	std::cout << "a is a long int\n";
}
*/


void test(long a)
{
	std::cout << "a is a long!\n";
}

int main()
{
	int a = 1;
	long b = 2;
	test(a);
	test(b);
	test(1);
	test(2L);
	return 0;
}