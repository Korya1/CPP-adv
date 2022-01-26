//
// pch.h
//

#pragma once

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <utility>
#include <fstream>
#include <sstream>
#include <optional>
#include <algorithm>
#include <tuple>

struct Person
{
	std::string firstName{};
	std::string secondName{};
	std::string patronymic{};

	Person() = default;
	Person(const std::string& f, const std::string& s, const std::string& p)
		:
		firstName(f),
		secondName(s),
		patronymic(p)
	{};


	friend std::ostream& operator<<(std::ostream& stream, Person obj);
	friend bool operator<(const Person& p1, const Person& p2);
	friend bool operator==(const Person& p1, const Person& p2);
};

struct PhoneNumber
{
	std::int32_t idCountry{ 0 };
	std::int32_t idCity{ 0 };
	std::string number{};
	std::optional<int> idAdditional{ -1 };

	PhoneNumber() = default;
	PhoneNumber(std::int32_t iCoun, std::int32_t iCit, const std::string& num, std::optional<int> iAdd)
		:
		idCountry(iCoun),
		idCity(iCit),
		number(num),
		idAdditional(iAdd)
	{}

	friend std::ostream& operator<<(std::ostream& stream, PhoneNumber obj);
	friend bool operator<(const PhoneNumber& p1, const PhoneNumber& p2);
	friend bool operator==(const PhoneNumber& p1, const PhoneNumber& p2);
};


class PhoneBook
{
private:
	std::vector<std::pair<Person, PhoneNumber>> data;
public:

	PhoneBook(std::ifstream& file);
	void SortByName();
	void SortByPhone();
	std::pair<std::string, PhoneNumber> GetPhoneNumber(const std::string& sn);
	void ChangePhoneNumber(const Person& name, const PhoneNumber& phone);
	friend std::ostream& operator<<(std::ostream& stream, PhoneBook obj);
};

