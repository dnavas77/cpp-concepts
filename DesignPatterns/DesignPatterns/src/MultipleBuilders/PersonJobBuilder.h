#pragma once

#include <string>
#include "PersonBuilder.h"

class PersonJobBuilder : public PersonBuilder {
	typedef PersonJobBuilder Self;

public:
	PersonJobBuilder(Person& person) : PersonBuilder(person) {}

	Self& at(std::string companyName) {
		person.companyName = companyName;
		return *this;
	}

	Self& asA(std::string position) {
		person.position = position;
		return *this;
	}

	Self& earning(int anualIncome) {
		person.anualIncome = anualIncome;
		return *this;
	}
};