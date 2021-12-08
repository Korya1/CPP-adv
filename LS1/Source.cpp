#include "Header.h"

// struct Person
bool operator<(const Person& p1, const Person& p2)
{
	return tie(p1.secondName, p1.firstName, p1.patronymic) <
		tie(p2.secondName, p2.firstName, p2.patronymic);
};

bool operator==(const Person& p1, const Person& p2)
{
	return tie(p1.secondName, p1.firstName, p1.patronymic) ==
		tie(p2.secondName, p2.firstName, p2.patronymic);
};

std::ostream& operator<<(std::ostream& stream, Person obj)
{
	short int reservedSpace = 15;
	stream.setf(std::ios::right);
	stream << std::setw(reservedSpace) << std::setfill(' ');

	stream << obj.secondName;
	std::cout << std::setw(reservedSpace) << std::setfill(' ');
	stream << obj.firstName;

	if (obj.patronymic != "")
	{
		std::cout << std::setw(reservedSpace) << std::setfill(' ');
		stream << obj.patronymic << "\t";
	}
	else
	{
		stream << "\t\t\t";
	}

	return stream;
};

// struct PhoneNumber
std::ostream& operator<<(std::ostream& stream, PhoneNumber obj)
{
	if (obj.idAdditional < 0) {
		stream << "+" << obj.idCountry << "(" << obj.idCity << ")" << obj.number;
	}
	else
	{
		stream << "+" << obj.idCountry << "(" << obj.idCity << ")" << obj.number << " " << obj.idAdditional.value();
	}
	return stream;
};

bool operator<(const PhoneNumber& p1, const PhoneNumber& p2)
{
	return tie(p1.idCountry, p1.idCity, p1.number, p1.idAdditional) <
		tie(p2.idCountry, p2.idCity, p2.number, p2.idAdditional);
};

bool operator==(const PhoneNumber& p1, const PhoneNumber& p2)
{
	return tie(p1.idCountry, p1.idCity, p1.number, p1.idAdditional) ==
		tie(p2.idCountry, p2.idCity, p2.number, p2.idAdditional);
};

// class PhoneNumber
PhoneBook::PhoneBook(std::ifstream& file)
{
	if (file.is_open())
	{

		for (std::string line; std::getline(file, line);)
		{
			std::stringstream str(line);
			std::vector<std::string> rowData;

			for (std::string s; std::getline(str, s, ' ');)
			{
				rowData.push_back(s);
			}

			std::pair<Person, PhoneNumber> fill;

			for (size_t i = 0; i < rowData.size(); ++i)
			{

				switch (i)
				{
				case 0:
					fill.first.secondName = rowData[i];
					break;
				case 1:
					fill.first.firstName = rowData[i];
					break;
				case 2:
					fill.first.patronymic = rowData[i];
					break;
				case 3:
					fill.second.idCountry = std::stoi(rowData[i]);
					break;
				case 4:
					fill.second.idCity = std::stoi(rowData[i]);
					break;
				case 5:
					fill.second.number = rowData[i];
					break;
				case 6:
					fill.second.idAdditional = std::stoi(rowData[i]);
					break;
				}
			}

			data.push_back(fill);
		}

		file.close();
	}
};

std::ostream& operator<<(std::ostream& stream, PhoneBook obj)
{
	for (const auto& [first, second] : obj.data)
	{
		stream << first << second << "\n";
	}
	return stream;
};

void PhoneBook::SortByName()
{
	auto sort = [](const auto& left, const auto& right) {		
		return left.first < right.first;
	};

	std::sort(data.begin(), data.end(), sort);
};

void PhoneBook::SortByPhone()
{

	auto sort = [](const auto& left, const auto& right) {
		return left.second < right.second;
	};

	std::sort(data.begin(), data.end(), sort);
};

std::pair<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& sn)
{
	bool check{ false };
	PhoneNumber num{};

	for (const auto& [secondN, phoneNum] : data)
	{
		if (secondN.secondName == sn)
		{
			if (check)
			{
				return { "found more than 1", {} };
			}
			check = true;
			num = phoneNum;
		}
	}

	if (!check)
	{
		return { "not found", {} };
	}
	else
	{
		return { "", num };
	}

};
void PhoneBook::ChangePhoneNumber(const Person& name, const PhoneNumber& phone)
{
	auto find = std::find_if(data.begin(), data.end(), [&name](const auto& find)
		{
			return find.first == name;
		});

	if (find != data.end()) { find->second = phone; }
};