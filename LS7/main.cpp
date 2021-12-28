#include <iostream>
#include <sstream>
#include <fstream>
#include "task2.pb.h"
#include <random>
#include <numeric>
#include <tuple>
#include "Header.h"



int main()
{
	StudentsGroup gr("data.bin");

	lesson::FullName person1, person2, person3;
	person1.set_firstname("Petr");
	person1.set_secondname("Morozov");
	person1.set_patronymic("Andreevich");

	person2.set_firstname("Ivan");
	person2.set_secondname("Arizonov");

	person3.set_firstname("Maryna");
	person3.set_secondname("Kostun");
	person3.set_patronymic("Andreeva");

	lesson::Student student1, student2, student3;

	*student1.mutable_fullname() = person1;
	*student2.mutable_fullname() = person2;
	*student3.mutable_fullname() = person3;

	for (size_t i = 0; i <= 5; ++i) {
		student1.add_scores(randomVal());
		student2.add_scores(randomVal());
		student3.add_scores(randomVal());
	}

	student1.set_averagescores(std::accumulate(student1.scores().begin(), student1.scores().end(), 0.) / student1.scores().size());
	student2.set_averagescores(std::accumulate(student2.scores().begin(), student2.scores().end(), 0.) / student2.scores().size());
	student3.set_averagescores(std::accumulate(student3.scores().begin(), student3.scores().end(), 0.) / student3.scores().size());

	gr.addNewStudent(student1);
	gr.addNewStudent(student2);
	gr.Save();

	gr.Open();
	std::cout << gr.GetAllInfo();

	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";

	gr.addNewStudent(student3);
	gr.Save();

	gr.Open();
	std::cout << gr.GetAllInfo();

	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";

	std::cout << gr.GetAllInfo(person1);

	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";

	std::cout << "Average score persnon #1: " << gr.GetAverageScore(person1) << "\n\n";

	return 0;
}
