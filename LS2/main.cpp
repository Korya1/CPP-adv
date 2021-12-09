#include "Header.h"
#include "Common.h"

int main()
{
	//task 1
	int* a = new int{ 1 };
	int* b = new int{ 2 };
	std::cout << "a = " << a << " value a = " << *a << "\n";
	std::cout << "b = " << b << " value b = " << *b << "\n";
	Swap(&a, &b);
	std::cout << "a = " << a << " value a = " << *a << "\n";
	std::cout << "b = " << b << " value b = " << *b << "\n\n";
	delete a;
	delete b;

	//task 2
	const int ARR_LEN = 6;
	int arr[ARR_LEN] = {5,4,2,1,6,3};
	std::vector<std::int32_t*> ptrs;

	for (size_t i = 0; i < ARR_LEN; i++)
	{
		ptrs.emplace_back(&arr[i]);
	}

	printVec(ptrs);
	SortPointers(ptrs);
	printVec(ptrs);

	//task 3
	std::ifstream file("War_and_Peace.txt");
	if (file.is_open())
	{
		file.seekg(0, std::ios::end);
		size_t size = file.tellg();
		file.seekg(0);
		std::string s(size, ' ');
		file.read(&s[0], size);
		std::string_view vowels{ "AEIOUYaeiouy" };

		countType1(s, vowels);
		countType2(s, vowels);
		countType3(s, vowels);
		countType4(s, vowels);
	}
	return 0;
}

