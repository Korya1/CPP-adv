#pragma once
#include "Common.h"

//task 1
void addAverage(std::list<double>& list);

//task 2
class Matrix
{
private:
	int** ppArr = nullptr;
	int size{ 0 };
public:
	Matrix(const int s);

	void FillValues();

	int** getData();
	int getSize();


	int getDeterminant(int** ppArr, int size);
	

	void PrintMatrix();

	~Matrix();
};

//task 3
template<typename T>

class MyIterator : public std::iterator<std::input_iterator_tag, T> {
private:
	T* ptr;
public:
	MyIterator(T* p) : ptr{ p } {}
	MyIterator(const MyIterator& p) : ptr{ p.ptr } {}
	bool operator!=(MyIterator const& other) const { return ptr != other.ptr; }
	typename MyIterator::reference operator*() const { return *ptr; }
	MyIterator& operator++() { ++ptr;	return *this; }
};

template <typename T>
class MyCont {
private:

	const size_t size;
	T* data;

public:

	MyCont(size_t s) : size(s)
	{
		data = new T[size];
	}

	MyCont(const std::initializer_list<T>& lst) : MyCont(lst.size())
	{
		size_t i{ 0 };
		for (auto& el : lst) {
			data[i++] = el;
		}
	}

	MyIterator<T> begin() { return MyIterator<T>(data); }
	MyIterator<T> end() { return MyIterator<T>(data + size); }

	~MyCont() { delete[] data; }
};