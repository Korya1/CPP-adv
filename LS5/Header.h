#pragma once
#include "Common.h"

template<class T>
void PrintUniqueElements(T first, T last)
{
	std::set<typename T::value_type> words(first, last);
	std::for_each(words.begin(), words.end(), [](const auto& i) {
		std::cout << i << "\n";
		});
}


void task2()
{
	std::multimap<int, std::string> lines;
	std::string input;
	int repeat;
	std::cout << "How many lines do you want to enter: ";
	std::cin >> repeat;
	std::cin.ignore();

	for (size_t i = 0; i < repeat; ++i)
	{
		std::cout << "\nEnter a line: \n";
		std::getline(std::cin, input);
		lines.insert({ input.size(), input });
	}


	std::for_each(lines.rbegin(), lines.rend(), [](std::pair<int, std::string> item) {
		std::cout << "Length: " << item.first << " - " << item.second << std::endl;
		});
}