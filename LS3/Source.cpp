#include "Header.h"

//task 1
void addAverage(std::list<double>& list)
{
	double countVal{ 0.0 };

	for (auto const& el : list)
	{
		countVal += el;
	}

	list.emplace_back((countVal / list.size()));
}

//task 2
Matrix::Matrix(const int s) : size(s)
{
	ppArr = new int* [size];

	for (size_t i = 0; i < size; i++)
	{
		ppArr[i] = new int[size];
	}
};

void Matrix::FillValues()
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			ppArr[i][j] = rand() % 10 - 5;
		}
	}
}

int** Matrix::getData() { return ppArr; };
int Matrix::getSize() { return size; };


int Matrix::getDeterminant(int** ppArr, int size)
{
	int det__;
	int sub_j, s;
	int** subT;
	switch (size)
	{
	case 1:
		return ppArr[0][0];
		break;
	case 2:
		return ppArr[0][0] * ppArr[1][1] - ppArr[0][1] * ppArr[1][0];
		break;
	default:
		if (size < 1) { return 1; };
		subT = new int* [size - 1];
		det__ = 0;
		s = 1;
		for (int i = 0; i < size; i++)
		{
			sub_j = 0;

			for (int j = 0; j < size; j++)
			{
				if (i != j)
				{
					subT[sub_j++] = ppArr[j] + 1;
				}
			}

			det__ = det__ + s * ppArr[i][0] * getDeterminant(subT, size - 1);
			s = -s;
		};
		delete[] subT;
		return det__;
	};
};

void Matrix::PrintMatrix() {

	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			std::cout << ppArr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] ppArr[i];
	}
	delete[] ppArr;
};

