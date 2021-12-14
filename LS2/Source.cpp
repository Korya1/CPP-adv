#include "Header.h"

void countType1(const std::string_view& string, const std::string_view vowels)
{
	Timer timer("Counting type 1");
	size_t count = std::count_if(string.begin(), string.end(), [&](const auto& c)
		{
			return (vowels.find(c) != std::string::npos);
		});
	std::cout << "Vowels = " << count << std::endl;
	timer.print();
}

void countType2(const std::string_view& string, const std::string_view vowels)
{
	Timer timer("Counting type 2");
	size_t count = std::count_if(string.begin(), string.end(), [&](const auto& c)
		{
			for (size_t i = 0; i < vowels.size(); ++i)
			{
				if (vowels[i] == c) { return true; }
			}
			return false;
		});
	std::cout << "Vowels = " << count << std::endl;
	timer.print();
}

void countType3(const std::string_view& string, const std::string_view vowels)
{
	Timer timer("Counting type 3");
	size_t count{ 0 };

	for (size_t i = 0; i < string.size(); ++i)
	{
		if (vowels.find(string[i]) != std::string::npos)
		{
			++count;
		}
	}

	std::cout << "Vowels = " << count << std::endl;
	timer.print();
}

void countType4(const std::string_view& string, const std::string_view vowels)
{
	Timer timer("Counting type 4");
	size_t count{ 0 };

	for (size_t i = 0; i < string.size(); ++i)
	{
		for (size_t j = 0; j < vowels.size(); ++j)
		{
			if (vowels[j] == string[i])
			{
				++count;
			}
		}
	}

	std::cout << "Vowels = " << count << std::endl;
	timer.print();
}