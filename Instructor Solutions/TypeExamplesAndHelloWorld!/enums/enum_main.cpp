#include <iostream>
#include <string>
/*
enum Color { red, yellow, green, blue, brown, white, black, purple, orange };

enum Light { red, green, yellow };

*/

enum class Light : char { red='R', green='g', yellow='y'};

enum class Color : int { red=100, yellow, green, blue, brown, white, black, purple, orange };

int main()
{
	Color color = Color::red;
	Light light = Light::red;
	return 0;
}
