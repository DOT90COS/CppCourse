#pragma once

#include <memory>
#include <cstdint>
#include <sstream>
#include <iostream>

struct ListNode {
	std::shared_ptr<ListNode> next;
	uint32_t data;
};


void add_node(std::shared_ptr<ListNode>& head, uint32_t value);
uint32_t get_count(std::shared_ptr<ListNode> head);
std::shared_ptr<ListNode> find_value(std::shared_ptr<ListNode> head, uint32_t needle);
std::shared_ptr<ListNode> remove_node(std::shared_ptr<ListNode>& head);

template<typename T>
auto compare_vals(T& a, T& b) -> bool
{
	return a == b;
}

template<typename T>
auto compare_vals(T a, T b) -> bool
{
	return a == b;
}

#define EXPECT(name, x, y)\
	do {\
		std::stringstream ss;\
		ss << "[" << __COUNTER__ << "]" << " Test: " << name << " : " << __FUNCTION__ << " : " << __LINE__ <<\
			  " - Results: \n";\
		if (compare_vals(x,y))\
			ss << "[*] Success!";\
		else\
			ss << "[x] Failed! Values " << x << ", " << y << " are not equal!";\
		std::cout << ss.str() << std::endl;\
	} while(0)

bool test_one();
bool test_two();
bool test_three();
