#ifndef __RECTANGLE_OVERLAP__
#define __RECTANGLE_OVERLAP__
#include <cstddef> //std::size_t
#include <string>
#include <map>

namespace ml {
	struct rectangle {
		int x;
		int y;
		std::size_t w;
		std::size_t h;
	};

	bool
		is_rectangle_intersect(rectangle const& first, rectangle const& second) {
		//check if one rectangle lies on left
		if (
			(first.x + first.w) < (second.x)
			||
			(second.x + second.w) < (first.x)
			)
			return false;

		//check if one rectangle lies above the other

		if (
			(first.y + first.h) < (second.y)
			||
			(second.y + second.h) < (first.y)
			)
			return false;

		return true;
	}


	//Anagram

	/*
	two alphanumerical character sequences(strings) are considered anagrams if by rearranging one of them we get 
	a string equal to the second string. strings "bcacd" and "dcbac" are anagrams, whele "bacdc" and 
	"dcbad" aren't. Your task is to write a function which receives two strings and returns the minimal
	number of characters you have to delete from the first, second or both strings so they become anagrams.
	*/
	int 
	get_minimum_deletion_count_for_anagram(
			std::string const& first, 
			std::string const& second) {
		std::map<char, int> table_;
		for (const auto a : first) {
			table_[a]++;
		}

		int deletion_count = 0;
		for (const auto a : second) {
			auto iter = table_.find(a);
			if (iter != table_.end()) {
				table_[a]--;
				if (table_[a] == 0)
					table_.erase(a);
			}
			else {
				deletion_count++;
			}
		}

		for (const auto i : table_) {
			deletion_count += i.second;
		}

		return deletion_count;
	}

	namespace detail {
		template<typename R>
		void
		_find_unique_from_set(std::vector<int> const& arr,
			const int S, R r) {
			std::set<int> table;
			for (const auto i : arr) {
				auto iter = table.find(S - i);
				if (iter != table.end()) {
					r(*iter, i);
				}

				table.insert(i);
			}
		}

		template<typename R>
		void 
			_find_unique_with_sort(std::vector<int> arr,
				const int S, R r) {
			std::sort(arr.begin(), arr.end());
			auto first = arr.begin();
			auto last = arr.end();
			if (first == last) return;
			while (true) {
				--last;
				while (*first + *last < S && first != last) first++;
				if (first == last) return;
				if (*first + *last == S) {
					r(*first, *last);
				}
			}
		}
	}//namespace detail

	/*
	You are given a sequence of integers A = (a1, a2, . . . , an) and integer X . Use standard
output to write all unique integer pairs, (ai, aj), ai, aj E A, whose sum equals :X ai + aj = X .
	*/
	template<typename R>
	void
	print_unique_sum_pair(std::vector<int> const& arr,
			const int S, R r) {
		//detail::_find_unique_from_set(arr, S, r);
		detail::_find_unique_with_sort(arr, S, r);
	}


	/*
	Write a function that receives a std::string, containing only lowercase letters from the
English alphabet, and returns a std::string which follows after it, in lexicographical order.
	*/

	std::string 
	get_lexicographical_next_str(std::string input) {
		auto N = input.size();
		bool z_replaced = false;
		while(N--) {
			if (input[N] == 'z') {
				input[N] = 'a';
				z_replaced = true;
			}
			else {
				input[N]++;
				z_replaced = false;
				break;
			}
		}

		return z_replaced ? 'a' + input : input;
	}




}//namepsace ml
#endif//__RECTANGLE_OVERLAP__