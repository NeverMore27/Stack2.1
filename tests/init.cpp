
#include <vector.hpp>
#include <catch.hpp>
SCENARIO("NULL") 
{
	vector_t vector;
	REQUIRE(vector.size() == 0);
	REQUIRE(vector.capacity() == 0);
}
SCENARIO("size")
{
	vector_t vector;
	REQUIRE(vector.size() == 0);
	vector.push_back(2) ;
	REQUIRE(vector.size() == 1);

}
SCENARIO("capacity")
{
	vector_t vector;
	REQUIRE(vector.capacity() == 0);
	vector.push_back(2) ;
	REQUIRE(vector.capacity() == 2);

}
SCENARIO("param") 
{
	vector_t vector(3);
	REQUIRE(vector.size() == 3);
	REQUIRE(vector.capacity() == 3);
}

SCENARIO("push") 
{
	vector_t vector(3);
	vector.push_back(2) ;
	REQUIRE(vector[3]==2);
	REQUIRE(vector.size() == 4);
	REQUIRE(vector.capacity() == 5);
}
SCENARIO("element") 
{
	vector_t vector(3);
	vector.push_back(2) ;
	REQUIRE(vector[3]==2);
}
SCENARIO("=") 
{
	vector_t vector1(3), vector;
	vector1.push_back(2) ;
	vector=vector1;
	REQUIRE(vector[3]==2);
	REQUIRE(vector.size()==4);
	REQUIRE(vector.capacity()==5);
}
SCENARIO("Copy") 
{
	vector_t v (3);
	vector_t vector(v);
	REQUIRE(vector.size() == v.size());
	REQUIRE(vector.capacity() == v.capacity());
}
SCENARIO("del") 
{
	vector_t v={1,2,3,5,7,8,1,2,4};
	vector_t vector={1,2,3,5,7,8,1};
	v.pop_back();
	v.pop_back();
	REQUIRE(v==vector);
}
