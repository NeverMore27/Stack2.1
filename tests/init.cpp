
#include <vector.hpp>
#include <catch.hpp>
SCENARIO("ini")
{
	stack<int> Stack;
	REQUIRE(Stack.count() == 0);
	REQUIRE(Stack.size() == 0);
}
	
SCENARIO("push")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	int val = Stack.pop();
	REQUIRE(Stack.count() == 1);
	REQUIRE(val == 7);
}

SCENARIO("count and size")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	REQUIRE(Stack.count() == 2);
	REQUIRE(Stack.size() == 2);
}

SCENARIO("pop")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	int val = Stack.pop();
	REQUIRE(Stack.count() == 2);
	REQUIRE(val == 7);
	REQUIRE(Stack.size() == 1);
}

