#include "Header.h"

std::string readFile(const std::string& f)
{
	std::ifstream file(f);
	if (file.is_open())
	{
		file.seekg(0, std::ios::end);
		size_t size = file.tellg();
		file.seekg(0);
		std::string s(size, ' ');
		file.read(&s[0], size);
		return s;
	}
}

void stopFunc()
{
	short i;
	std::cin >> i;
}

void owner(std::vector<int>& nums)
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		int v = rand() % 100;
		std::cout << "Add: " << v << "\n";
		nums.emplace_back(v);
	}
}

void robber(std::vector<int>& nums)
{
	while (!nums.empty())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		auto e = std::max_element(nums.begin(), nums.end());
		std::cout << "erase: " << *e << "\n";
		nums.erase(e);
	}
}

void returnPrimeNum(const int num, int& prime)
{
	bool done = false;
	std::thread th6([&done]() { stopFunc(); done = true; });
	th6.detach();

	int count{ 1 };
	size_t i = 3;

	if (num == 1)
	{
		prime = 2;
		throw 5;
	}
	else
	{
		std::cout << "2 is prime #" << count << "\n";
		while (num != count)
		{
			bool check = true;
			for (size_t j = 3; j <= i / 2; j += 2)
			{
				if ((i % j) == 0)
				{
					check = false;
					break;
				}
			}
			std::cout << i;
			if (check)
			{
				++count;
				prime = i;
				std::cout << " is prime #" << count;
			}
			std::cout << "\n";
			i += 2;
			if (done) { throw count; }
		}
	}
}