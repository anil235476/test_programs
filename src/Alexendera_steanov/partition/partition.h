#ifndef _ALEX_PARTITION_H__
#define _ALEX_PARTITION_H__
#include <algorithm>

namespace alex {

	namespace util {
		template<typename I>
		I successor(I i) {
			return ++i;
		}
	}

	namespace detail {

		template<typename I, //I models bidirectional iterator
				typename P //P models uniary iterator
		>
		I
			partition_bidirectional_unguarded(I first, I last, P pred) {
			//assert(!std::all_of(first, last, pred));
			//assert(!std::none_of(first, last, pred));

			while (true) {
				while (pred(*first)) ++first;
				do --last; while (!pred(*last));
				if (last == first) return first;
				std::iter_swap(first, last);
				++first;
			}
		}



		template<typename I, class P>
		I 
			partition_bidirectional(I first, I last, P pred) {
			while (true) {
				while (first != last && pred(*first))
					++first;
				if (first == last) return first;
				--last;
				while (last != first && !pred(*last)) {
					--last;
				}
				if (first == last) return first;

				std::iter_swap(first, last);
			}
		}

		

		template<typename I, class P>
		I
		find_backward(I first, I last, P pred) {
			while (true) {
				if (first == last) return first;
				--last;
				if (pred(*last)) return util::successor(last);
			}
		}

		template<typename I, class P>
		I
			partition_bidirectional_shorter_version(I first, I last, P pred) {
			while (true) {
				first = std::find_if_not(first, last, pred);
				last = detail::find_backward(first, last, pred);
				if (first == last) return first;
				--last;
				std::iter_swap(first, last);
				++first;
			}
		}
	}//namespace detail
	

	template<typename I, class P> // I models bidirectional iterator, P models uniary operator
	I 
	partition_with_pred(I first, I last, P cond) {
		return detail::partition_bidirectional_shorter_version(first, last, cond);
	}



	/*
		returns point at which all the elements before it less than or equal to it
		all the elements beyond it are greater than it
	*/
	template<typename I, typename T> //I models bidirectional iterator
	I 
	partition(I first, I last, T const& v) {
		return partition_with_pred(first, last, [v](T const& a) {
			return a <= v;
		});	
	}
	
	/*
	struct random_access;

	template<typename I, typename T> //I models random access iterator
	I
		partition(I first, I last, T const& v, random_access) {

	}
	*/

	template<typename I, typename P> // I models forward iterator
	I partition_forward(I first, I last, P pred) {
		I m = first;
		while (first != last) {
			if (pred(*first)) {
				std::iter_swap(m, first);
				++m;
			}
			++first;
		}
		return m;
	}

	template<typename I, //I models bidirectional iterator
		typename P	//P models uniary op
	> 
		I partition_bidirectional_optimized(I first, I last, P p) {
		while (true) {
			while (p(*first)) ++first;
			do --last; while (!p(*last));
			if (util::successor(last) == first) return first;
			std::iter_swap(first, last);
			++first;
		}
	}

}//namespace alex


#endif//