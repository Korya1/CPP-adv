#include "Header.h"
#include "Common.h"


int main()
{
	//========== task 1

	std::thread th1([]() {Pcout{} << readFile("File_01.txt"); });
	std::thread th2([]() {Pcout{} << readFile("File_02.txt"); });
	th1.join();
	th2.join();

	//========== task 2

	int num;
	std::cout << "Write number to check: ";
	std::cin >> num;

	int prime{ 0 };

	std::thread th3([&]() {
		try
		{
			returnPrimeNum(num, prime);
			std::cout << "Prime number #" << num << " is = " << prime << "\n";
		}
		catch (const int ex)
		{			
			std::cout << "Something happened! We didn't find #" << num << " prime number\n";
			std::cout << "Last prime number which we calculated is " << prime << " - #" << ex << "\n";
		}
		});

	th3.join();

	//========== task 3

	std::srand(unsigned(std::time(nullptr)));
	std::vector<int> nums(5);

	std::generate(nums.begin(), nums.end(), []() {return rand() % 100; });
	for (auto el : nums)
	{
		std::cout << el << "\n";
	}

	std::cout << "---------------" << "\n";

	// work until std::thread th5 work
	std::thread th4(owner, ref(nums));
	th4.detach(); 

	// work until the vector "!nums.empty()"
	std::thread th5(robber, ref(nums));	
	th5.join();

	return 0;
}

