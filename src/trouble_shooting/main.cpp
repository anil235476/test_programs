#include <iostream>
#include <exception>
#include <cassert>
#include <future>
#include <initializer_list>
using namespace std;

void problem_function() {
	while (true) {
		int* ptr = new int[200];
		cout << "allocating memory\n";
		int *tmp = nullptr;// new int;
		//delete tmp;
		int v = *tmp;
		cout << *tmp << '\n';
		throw runtime_error{ "just fun" };
	}
}


/*
default capture problem
*/
struct S {
	int x;
	void f() {
		// The following lambda captures are currently identical
		auto a = [&]() { x = 42; }; // OK: transformed to (*this).x
		auto b = [=]() { x = 43; }; // OK: transformed to (*this).x
		a();
		assert(x == 42);
		b();
		assert(x == 43);
	}
};

//problem or issues may occur in concurrency use case
class Work {
private:
	int value;
public:
	Work() : value(42) {}
	std::future<int> spawn()
	{
		return std::async([=]()->int { return value; });
	}
};

std::future<int> 
foo()
{
	Work tmp;
	return tmp.spawn();
	// The closure associated with the returned future
	// has an implicit this pointer that is invalid.
}

int main() {
	//problem_function();
	//S{}.f();
	auto f = foo();
	f.wait();
	cout<<" future value = "<<f.get()<<'\n';
	// The following fails due to the
	// originating class having been destroyed
	assert(42 == f.get());
	cout << "return from main\n";
}