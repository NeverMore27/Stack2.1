
#include <vector.hpp>
#include <catch.hpp>
SCENARIO("null")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	int val = Stack.pop();
	REQUIRE(Stack.count() == 1);
	REQUIRE(val == 7);
}

SCENARIO("null1")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	Stack.push(9);
	int val = Stack.pop();
	REQUIRE(Stack.count() == 2);
	REQUIRE(Stack.size() == 2);
	REQUIRE(val == 9);
}

SCENARIO("null2")
{
	stack<int> Stack;
	REQUIRE(Stack.count() == 0);
}
