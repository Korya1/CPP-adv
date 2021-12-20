#include "Header.h"
#include "Common.h"


int main()
{
	std::ifstream file("War_and_Peace.txt");
	std::vector<std::string> str;
	if (file.is_open())
	{
		std::string temp;
		while (file >> temp)
		{
			str.push_back(temp);
		}
	}
	PrintUniqueElements(str.begin(), str.end());

	std::vector<int> i{2,23,2,3,1,31,2,31,23,6};
	PrintUniqueElements(i.begin(), i.end());

	
	task2();
	

	return 0;
}


