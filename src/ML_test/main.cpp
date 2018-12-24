#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
#include "ml_test.h"

//using namespace std;

using std::vector;

TEST_CASE("rectangle_overlap", "[overlap]") {
	ml::rectangle first{ 0,0, 12, 14 };
	ml::rectangle second{ 1,2, 34, 43 };
	REQUIRE(ml::is_rectangle_intersect(first, second));
}

TEST_CASE("anagram test", "[anagram]") {
	{
		std::string const first = "bcacd";
		std::string const second = "dcbac";
		REQUIRE(ml::get_minimum_deletion_count_for_anagram(first, second) == 0);
	}
	{
		std::string const first = "bacdc";
		std::string const second = "dcbad";
		REQUIRE(ml::get_minimum_deletion_count_for_anagram(first, second) == 2);
	}

	{
		std::string const first = "allergy";
		std::string const second = "allergic";
		REQUIRE(ml::get_minimum_deletion_count_for_anagram(first, second) == 3);
	}

	/*{
		std::string const first = "triangle";
		std::string const second = "allergic";
		REQUIRE(ml::get_minimum_deletion_count_for_anagram(first, second) == 3);
	}*/

}

TEST_CASE("sum_pair", "[sum]") {
	int count = 0;
	ml::print_unique_sum_pair(std::vector<int>{1, 2, 3, 4, 5, 6, 7}, 8, [&count](int a, int b) {
		std::cout << "pair " << a << ',' << b << '\n';
		count++;
	});
	REQUIRE(count == 3);
}

TEST_CASE("test_lexicographical", "[Lexicographical]") {
	{
		std::string input = "abc";
		std::string expected = "abd";
		auto const r = ml::get_lexicographical_next_str(input);
		REQUIRE(r == expected);
	}

	{
		std::string input = "abz";
		std::string expected = "aca";
		auto const r = ml::get_lexicographical_next_str(input);
		REQUIRE(r == expected);
	}

	{
		std::string input = "z";
		std::string expected = "aa";
		auto const r = ml::get_lexicographical_next_str(input);
		REQUIRE(r == expected);
	}

	{
		std::string input = "zz";
		std::string expected = "aaa";
		auto const r = ml::get_lexicographical_next_str(input);
		REQUIRE(r == expected);
	}

	{
		std::string input = "zzb";
		std::string expected = "zzc";
		auto const r = ml::get_lexicographical_next_str(input);
		REQUIRE(r == expected);
	}
	
}
