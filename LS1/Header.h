#pragma once
#include "Common.h"

struct Person
{
	std::string secondName{};
	std::string firstName{};
	std::string patronymic{};

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

