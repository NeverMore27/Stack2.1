
#include <stack.hpp>
#include <catch.hpp>
SCENARIO("ini")
{
	stack<int> Stack;
	REQUIRE(Stack.size() == 0);
	REQUIRE(Stack.empty());
}
	
SCENARIO("push")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	int val = Stack.top();
	REQUIRE(val == 7);
	REQUIRE(Stack.size() == 1);
}

SCENARIO("count and size")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	REQUIRE(Stack.size() == 2);
}

SCENARIO("pop")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	int val = Stack.top();
	REQUIRE(val == 7);
	REQUIRE(Stack.size() == 1);
}

