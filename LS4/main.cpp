#include "Header.h"
#include "Common.h"


int main()
{
	std::vector<int> cont{ 1,2,3,4,5,6,7 };
	printCont(cont);
	insert_sorted(cont, 3);
	insert_sorted(cont, 8);
	printCont(cont);

	task2();

	return 0;
}


