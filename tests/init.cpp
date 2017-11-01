
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
	auto sp = std::make_shared<int>();
	Stack.push(5);
	Stack.push(7);
	Stack.push(12);
	sp=Stack.pop();
	REQUIRE(Stack.size() == 2);
	REQUIRE(*sp == 12);
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
	REQUIRE(Stack.size() == 2);
}

