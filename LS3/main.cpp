//#include "Header.h"
#include "Common.h"

template<class C, class T>
void insert_sorted(C& container, T value)
{
	auto it{ lower_bound(container.begin(), container.end(), value) };
	container.insert(it, value);
}


int main()
{
	std::vector<int> cont{ 1,2,3,4,5,6,7 };
	insert_sorted(cont, 3);
	insert_sorted(cont, 8);

	for (const auto& el : cont)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;



	return 0;
}

