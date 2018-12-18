#ifndef _ALEX_PARTITION_H__
#define _ALEX_PARTITION_H__

namespace alex {

	template<typename I, typename T, class P> // I models bidirectional iterator
	I 
	partition(I first, I last, T const& v, P cond) {
		while (true) {
			while (first != last && cond(*first, v))
				++first;
			if (first == last) return first;
			--last;
			while (last != first && !cond(*last, v)) {
				--last;
			}
			if (first == last) return first;

			std::iter_swap(first, last);
		}
	}
	/*
		returns point at which all the elements before it less than or equal to it
		all the elements beyond it are greater than it
	*/
	template<typename I, typename T> //I models bidirectional iterator
	I 
	partition(I first, I last, T const& v) {
		return partition(first, last, v, [](T const& first, T const& second) {
			return first <= second;
		});	
	}
	
	struct random_access;

	template<typename I, typename T> //I models random access iterator
	I
		partition(I first, I last, T const& v, random_access) {

	}

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

}//namespace alex


#endif//