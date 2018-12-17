#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
#include "rotate/rotate.h"

//using namespace std;

using std::vector;


TEST_CASE("test rotate", "[rotate]") {
	
	{
		vector<int> arr = { 1,2,3,4,5,6,7 };// rotate at 4, then result = {5,6,7,1,2,3,4}
	
		vector<int> const result = { 3,4,5,6,7,1,2 };
		auto r = alex::our_rotate(arr.begin(), arr.begin() + 2, arr.end());
		REQUIRE(result == arr);

		REQUIRE(r == arr.begin() + 5);
	}
	{
		vector<int> arr = { 1,2,3,4,5,6,7 };
		vector<int> const result = { 6,7, 1,2,3,4,5 };
		auto r = alex::our_rotate(arr.begin(), arr.begin() + 5, arr.end());
		REQUIRE(result == arr);
		REQUIRE(r == arr.begin() + 2);
	}

	{
		vector<int> arr = { 1,2,3,4,5,6,7,8 };
		vector<int> const result = { 5, 6,7,8, 1,2,3,4 };
		auto r = alex::our_rotate(arr.begin(), arr.begin() +4, arr.end());
		REQUIRE(result == arr);
		REQUIRE(r == arr.begin() + 4);
	}
}
