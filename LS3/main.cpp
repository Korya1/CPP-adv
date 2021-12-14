#include "Header.h"
#include "Common.h"

int main()
{
	//================== task 1
	std::list<double> nums{ 1.76, 2.34, 1.2 };

	for (auto const& el : nums)
	{
		std::cout << el << " ";
	}

	addAverage(nums); ///foo

	std::cout << std::endl << "----------------" << std::endl;

	for (auto const& el : nums)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl << std::endl;
	//================== task 2


	Matrix matrix(3);
	matrix.FillValues();
	matrix.PrintMatrix();
	int d = matrix.getDeterminant(matrix.getData(), matrix.getSize());
	std::cout << d << std::endl;

	//================== task 3
	MyCont<int> cont{ 2,3,4,6,12,2 };

	for (auto& j : cont) {
		std::cout << j << " ";
	}


	return 0;
}

