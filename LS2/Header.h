#pragma once
#include "Common.h"

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::string m_name;
	std::chrono::time_point<clock_t> m_beg;
	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}

public:
	Timer() : m_beg(clock_t::now()) { }
	Timer(std::string name) : m_name(name), m_beg(clock_t::now()) { }

	void start(std::string name) {
		m_name = name;
		m_beg = clock_t::now();
	}
	void print() const {
		std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
	}
};



template<typename T>
void Swap(T* const f_value, T* const s_value)
{
	T temp = *f_value;
	*f_value = *s_value;
	*s_value = temp;
}

template<typename T>
void SortPointers(T& const ptr)
{
	auto sort = [](const auto* left, const auto* right) { return (*left < *right); };

	std::sort(ptr.begin(), ptr.end(), sort);
}

template<typename T>
void printVec(const T& ptr)
{
	for (size_t i = 0; i < ptr.size(); ++i)
	{
		std::cout << *ptr[i] << " ";
	}
	std::cout << std::endl;
}

void countType1(const std::string_view& string, const std::string_view vowels);
void countType2(const std::string_view& string, const std::string_view vowels);
void countType3(const std::string_view& string, const std::string_view vowels);
void countType4(const std::string_view& string, const std::string_view vowels);