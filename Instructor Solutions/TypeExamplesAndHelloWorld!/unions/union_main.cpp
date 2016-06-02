#include <cstdint>
#include <iostream>

typedef union ARGB
{
	uint32_t color;
	struct componentsTag
	{
		uint8_t a; 
		uint8_t b;
		uint8_t g;
		uint8_t r;
	}components;
}pixel;


int main()
{
	pixel p;
	p.color = 0x334455AA;
	std::cout << std::hex;
	std::cout << "R: 0x" << static_cast<short>(p.components.r) << "\n";
	std::cout << "G: 0x" << static_cast<short>(p.components.g) << "\n";
	std::cout << "B: 0x" << static_cast<short>(p.components.b) << "\n";
	std::cout << "A: 0x" << static_cast<short>(p.components.a) << "\n";

	return 0;
}