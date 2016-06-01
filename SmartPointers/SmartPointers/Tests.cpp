#include "defs.hpp"


bool test_one()
{
	std::shared_ptr<ListNode> head = nullptr;

	EXPECT("Count Test - No nodes", (uint32_t)0, get_count(head));
	add_node(head, 10);
	add_node(head, 20);
	
	EXPECT("Count Test - Some nodes", (uint32_t)2, get_count(head));

	for (uint32_t i = 0; i < 10; ++i) {
		add_node(head, i);
		EXPECT("Count Test - Values", i+3, get_count(head));
	}

	return true;
}

bool test_two()
{
	std::shared_ptr<ListNode> head = nullptr;

	for (uint32_t i = 100; i > 30; --i) {
		add_node(head, i);
	}

	{
		auto res = find_value(head, 40);
		EXPECT("Result Test - 1", true, !!res);
		EXPECT("Result Test - 2", res->data, (uint32_t)40);
	}

	{
		auto res = find_value(head, 300);
		EXPECT("Result Test - 3", false, !!res);
	}

	return true;
}

bool test_three()
{
	std::shared_ptr<ListNode> head = nullptr;

	for (uint32_t i = 100; i > 0; --i) {
		add_node(head, i);
	}

	EXPECT("Remove Node Test", (uint32_t)100, get_count(head));

	for (uint32_t i = 100; i > 0; --i) {
		auto res = remove_node(head);
		if(res)
			std::cout << "Removing Node: " << res->data << std::endl;

		EXPECT("Remove Node Test", i-1, get_count(head));
	}

	return true;
}
