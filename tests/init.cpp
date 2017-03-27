
#include <vector.hpp>
#include <catch.hpp>
SCENARIO("NULL") 
{
	vector_t vector;
	REQUIRE(vector.size() == 0);
	REQUIRE(vector.capacity() == 0);
	for (i; i <size_;i++)
	{
		REQUIRE(ptr_[i] == 0);
	}
}
SCENARIO("NULL")
{
	vector_t vector;
	REQUIRE(vector.size() == 0);

}
SCENARIO("param") 
{
	vector_t vector(3);
	REQUIRE(vector.size() == 3);
	REQUIRE(vector.capacity() == 3);
}

SCENARIO("element") 
{
	vector_t vector(3);
	vector.push_back(2) ;
	REQUIRE(vector[3]==2);
	REQUIRE(vector.size() == 4);
	REQUIRE(vector.capacity() == 8);
}
SCENARIO("=") 
{
	vector_t vector1(3), vector;
	vector1.push_back(2) ;
	vector=vector1;
	REQUIRE(vector[3]==2);
	REQUIRE(vector.size()==4);
	REQUIRE(vector.capacity()==8);
}
SCENARIO("Copy") 
{
	vector_t v (3);
	vector_t vector(v);
	REQUIRE(vector.size() == v.size());
	REQUIRE(vector.capacity() == v.capacity());
}
