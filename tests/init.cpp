
#include <vector.hpp>
#include <catch.hpp>
SCENARIO("NULL") 
{
	int a[5] = { 8,1,5,7 8 };
	int b[5]={8, 8, 7, 5, 1}
	ItSort(&a[0], &a[6]);
	for (int i = 0; i < 5; i++)
	REQUIRE(a[i]==b[i]);
	
}