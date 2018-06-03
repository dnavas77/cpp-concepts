#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <sstream>

struct Address {
	std::string* houseName = nullptr;
};

struct Person {
	Address* address = nullptr;
};

template<typename T> struct Maybe;
template<typename T> Maybe<T> maybe(T* context) {
	return Maybe<T>(context);
}

template<typename T> struct Maybe {
	T* context;

	Maybe(T* context) : context(context) { }

	template <typename TFunc> auto With(TFunc evaluator) {
		return context != nullptr ? maybe(evaluator(context)) : nullptr;
	}

	template <typename Func> auto Do(Func action) {
		if (context != nullptr) action(context);
		return *this;
	}
};


void printHouseName(Person* p) {
	auto z = maybe(p)
		.With([](auto x) { return x->address; })
		.With([](auto x) { return x->houseName; })
		.Do([](auto x) { std::cout << *x << '\n'; });
}

int main() {

	Person p;
	p.address = new Address;
	p.address->houseName = new std::string("my castle");

	printHouseName(&p);

	delete p.address->houseName;
	delete p.address;

	std::cin.get();
	return 0;
}
