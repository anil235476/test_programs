#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
#include "rotate/rotate.h"
#include "partition/partition.h"

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


std::string
to_string(vector<int> const& v) {
	std::string result;
	std::for_each(v.begin(), v.end(),
		[&result](int a) {
		result += std::to_string(a) + " " ;
		});
	return result;
}


TEST_CASE("test_partition", "[partition]") {
	{
		vector<int> arr = { 8,7,1,3,5,0,2,1 };

		auto r = alex::partition(arr.begin(), arr.end(), 6);
		REQUIRE(r == arr.begin() + 6);
		REQUIRE_FALSE(arr == vector<int>{ 8, 7, 1, 3, 5, 0, 2, 1 });
		const auto str = to_string(arr);
		std::cout << str;
		INFO("changed arr" << str);
	}
	{
		vector<int> arr = { 1,2,3,4,5,6,7,8,8,80 };
		auto r = alex::partition(arr.begin(), arr.end(), 6);
		REQUIRE(r == arr.begin() + 6);
		vector<int> const expected_arr = { 1,2,3,4,5,6,7,8,8,80 };
		REQUIRE(arr == expected_arr);
	}
}

TEST_CASE("test_forward_partition", "[partition_forward]") {
	vector<int> arr = { 8,7,1,3,5,0,2,1 };

	auto r = alex::partition_forward(arr.begin(), arr.end(), [](auto a) {
		return a <= 6;});
	REQUIRE(r == arr.begin() + 6);
}
