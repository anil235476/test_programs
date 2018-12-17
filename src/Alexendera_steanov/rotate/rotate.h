#ifndef _ALEX_ROTATE_H__
#define _ALEX_ROTATE_H__

namespace alex {

	namespace detail {
		template<typename I>
		void rotate_void_return(I first, I mid, I last) {
			auto second = mid;
			while (true) {
				while (first != mid && second != last) {
					std::iter_swap(first, second);
					++first;
					++second;
				}
				if (first == mid && second == last)
					break;
				if (first == mid)
					mid = second;
				else if (second == last) {
					second = mid;
				}
			}
		}
	}//namespace detail
	

	/*
	return I-> new rotation point.
	three cases:-
	(1) both sides ranges are of equal size. ( then new rotation point would be same as old point.
	(2) when first range is less in size in second range, then new point
			point would pass old mid point
	(3) when second range is less in size than first range, then new point would be before
			old mid point.
				
	*/
	template<typename I> // I models input iterator
	I
	our_rotate(I first, I mid, I  last) {

		auto second = mid;
		while (true) {
			while (first != mid && second != last) {
				std::iter_swap(first, second);
				++first;
				++second;
			}

			if (first == mid && second == last)//case 1 or 2.
				return first;

			if (first == mid) //case 2.
				mid = second;
			else /*if (second == last)*/ {//case 3.
				detail::rotate_void_return(first, mid, last);
				return first;
			}
		}
	}


}//namespace alex

#endif//_ALEX_ROTATE_H__