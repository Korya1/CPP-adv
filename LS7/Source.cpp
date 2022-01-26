#include "Header.h"

StudentsGroup::StudentsGroup(const std::string& path) : path(path) {};

void StudentsGroup::addNewStudent(lesson::Student student)
{
	*group.add_students() = student;
};

void StudentsGroup::Open()
{
	std::ifstream in(path, std::ios_base::binary);
	if (in.is_open())
	{
		group.ParseFromIstream(&in);

		in.close();
	}
	else
	{
		std::cout << "Error open!";
	}
};

void StudentsGroup::Save()
{
	std::ofstream out(path, std::ios_base::binary);
	if (out.is_open())
	{
		group.SerializePartialToOstream(&out);
		out.close();
	}
	else
	{
		std::cout << "Error open!";
	}
};

double StudentsGroup::GetAverageScore(const lesson::FullName& name)
{
	for (auto el : group.students())
	{
		if (el.fullname().firstname() == name.firstname() &&
			el.fullname().secondname() == name.secondname() &&
			el.fullname().patronymic() == name.patronymic()
			)
		{
			return el.averagescores();
		}
	}

	return 0.;
}

std::string StudentsGroup::GetAllInfo(const lesson::FullName& name)
{
	std::stringstream allData{}, scrData{};
	for (auto el : group.students())
	{
		if (el.fullname().firstname() == name.firstname() &&
			el.fullname().secondname() == name.secondname() &&
			el.fullname().patronymic() == name.patronymic()
			)
		{
			for (auto e : el.scores())
			{
				scrData << e << " ";
			}

			allData << "Student: " << el.fullname().firstname() << " " << el.fullname().secondname() << " " << el.fullname().patronymic() << "\n";
			allData << "Scores: " << scrData.str() << "\n";
			allData << "Average score: " << el.averagescores() << "\n\n";
		}
		else
		{
			allData << "Not found";
		}
	}

	return allData.str();
}

std::string StudentsGroup::GetAllInfo()
{
	std::stringstream allData{};
	size_t i{ 1 };

	for (auto el : group.students())
	{
		std::stringstream scrData{};

		for (auto e : el.scores())
		{
			scrData << e << " ";
		}

		allData << "Student #" << i << " " << el.fullname().firstname() << " " << el.fullname().secondname() << " " << el.fullname().patronymic() << "\n";
		allData << "Scores: " << scrData.str() << "\n";
		allData << "Average score: " << el.averagescores() << "\n\n";

		++i;
	}

	return allData.str();
}

int randomVal(int min, int max)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(min, max);

	return uni(rng);
}