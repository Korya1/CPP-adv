#include "Header.h"
#include "Common.h"


int main()
{
	std::ifstream file("PhoneBook.txt");
	PhoneBook book(file);
	std::cout << book;

	std::cout << "------SortByName-------\n";
	book.SortByName();
	std::cout << book;

	std::cout << "------SortByPhone-------\n";
	book.SortByPhone();
	std::cout << book;

	std::cout << "------GetPhoneNumber-------\n";

	auto print_phone_number = [&book](const std::string& surname) {
		std::cout << surname << "\t";
		auto answer = book.GetPhoneNumber(surname);
		if (std::get<0>(answer).empty())
			std::cout << std::get<1>(answer);
		else
			std::cout << std::get<0>(answer);
		std::cout << std::endl;
	};

	print_phone_number("Ivanov");
	print_phone_number("Petrov");
	print_phone_number("Kim");


	std::cout << "----ChangePhoneNumber----" << std::endl;
	book.ChangePhoneNumber(Person{ "Davidov", "Saveiliy", "Petrovich" }, PhoneNumber{ 1, 1, "11111112", std::nullopt });
	book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
	std::cout << book;

	return 0;
}

