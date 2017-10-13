
#include <vector.hpp>
#include <catch.hpp>
SCENARIO("null")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	int val = Stack.pop();
		REQUIRE(Stack.count() == 2);
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
	REQUIRE(val == 9);
}

SCENARIO("null2")
{
	stack<int> Stack;
	REQUIRE(Stack.count() == 0);
}
SCENARIO("null3")
{
	stack<int> Stack;
	Stack.push(5);
	Stack.push(7);
	Stack.push(9);
	stack<int> s(Stack);
	REQUIRE(s.count() == 3);
	int val = s.pop();
	REQUIRE(val == 9);
	val = s.pop();
	REQUIRE(val == 7);
	val = s.pop();
	REQUIRE(val == 5);
}
