#pragma once
#include "Common.h"

class Pcout
{
private:
	std::mutex m;
public:

	Pcout() { std::lock_guard lg(m); };
	~Pcout() = default;
	std::ostream& operator<< (const std::string& p)
	{
		return std::cout << p << "\n";
	}
};

std::string readFile(const std::string& f);

void stopFunc();

void owner(std::vector<int>& nums);

void robber(std::vector<int>& nums);

void returnPrimeNum(const int num, int& prime);