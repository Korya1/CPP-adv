#include "Header.h"

template<class T>
void printCont(const T& cont)
{
	for (const auto& el : cont)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

//task 1
template<class C, class T>
void insert_sorted(C& container, T value)
{
	auto it{ lower_bound(container.begin(), container.end(), value) };
	container.insert(it, value);
}

//task 2
void task2()
{
	const size_t SIZE{ 100 };

	std::vector<double> a(SIZE, 0.0);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> d{ 0.0, 7.0 };

	std::generate(a.begin(), a.end(), [&]() {return d(gen); });

	printCont(a);

	std::vector<int> b(SIZE, 0);
	std::transform(a.begin(), a.end(), b.begin(), [](const auto& el) {return static_cast<int>(el); });

	printCont(b);

	std::cout << "Error = " <<
		std::inner_product(a.begin(), a.end(), b.begin(), 0.,
			[](const auto& a, const auto& b)
			{return a + b; },
			[](const auto& a, const auto& b)
			{return (a - b) * (a - b); })
		<< std::endl;
}