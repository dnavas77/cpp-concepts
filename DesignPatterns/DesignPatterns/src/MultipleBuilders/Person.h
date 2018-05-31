#pragma once
#include <string>
#include <boost/lexical_cast.hpp>

using namespace std::string_literals;

class PersonBuilder;

class Person {
	// Address
	std::string streetAddress, postCode, city;

	// Employment
	std::string companyName, position;
	int anualIncome = 0;

	Person() { };

public:
	static PersonBuilder create();

	Person(Person&& other)
		: streetAddress{ move(other.streetAddress) },
		postCode{ std::move(other.postCode) },
		city{ move(other.city) },
		companyName{ std::move(other.companyName) },
		position{ move(other.position) },
		anualIncome{ other.anualIncome}
	{
	}

	Person& operator=(Person&& other)
	{
		if (this == &other)
			return *this;
		streetAddress = std::move(other.streetAddress);
		postCode = std::move(other.postCode);
		city = move(other.city);
		companyName = std::move(other.companyName);
		position = move(other.position);
		anualIncome = other.anualIncome;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Person& obj)
	{
		return os
			<< "street_address: "s << obj.streetAddress
			<< " post_code: "s << obj.postCode
			<< " city: "s << obj.city
			<< " company_name: "s << obj.companyName
			<< " position: "s << obj.position
			<< " annual_income: "s << boost::lexical_cast<std::string>(obj.anualIncome);
	}

	friend class PersonBuilder;
	friend class PersonAddressBuilder;
	friend class PersonJobBuilder;
};
