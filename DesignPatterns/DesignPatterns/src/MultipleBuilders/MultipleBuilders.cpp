#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <sstream>

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

int main() {
	Person p = Person::create()
		.lives().at("999 Some Street")
		.withPostCode("9889-777")
		.works().at("Merck & Co")
		.asA("Accountant")
		.earning(444444);

	std::cout << p << '\n';

	std::cin.get();
	return 0;
}
