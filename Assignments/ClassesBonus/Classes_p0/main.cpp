#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Classes.hpp"


TEST_CASE("Classes Test", "[Classes]") {
	auto stack = make_stack();

	REQUIRE(stack->count() == 0);
	
	auto x = make_value(10);

	REQUIRE(((*x) + 10) == 20);
	REQUIRE(x->getInt() == 20);
	stack->push(std::move(x));

	REQUIRE(stack->count() == 1);
	auto y = make_value(1.23);

	REQUIRE(((*y) + 2.34) == 3.57);
	REQUIRE(y->getDouble() == 3.57);
	stack->push(std::move(y));

	REQUIRE(stack->count() == 2);

	std::string s = "asdkfj";
	std::string m = "derp";
	auto z = make_value(s);

	REQUIRE(z->getString() == s);
	REQUIRE(((*z) + m) == (s + m));
	stack->push(std::move(z));

	REQUIRE(stack->count() == 3);
	stack->pop();
	REQUIRE(stack->count() == 2);
	stack->pop();
	REQUIRE(stack->count() == 1);
	stack->pop();
	REQUIRE(stack->count() == 0);

}

