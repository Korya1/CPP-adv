#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "task2.pb.h"
#include <random>
#include <numeric>
#include <tuple>

class IRepository {
	virtual void Open() = 0;
	virtual void Save() = 0;
};


class IMethods {
	virtual double GetAverageScore(const lesson::FullName& name) = 0;
	virtual std::string GetAllInfo(const lesson::FullName& name) = 0;
	virtual std::string GetAllInfo() = 0;
};

class StudentsGroup : public IRepository, public IMethods
{
private:
	std::string path{ "" };
	lesson::StudentsGroup group;
	lesson::Student student;
public:

	StudentsGroup(const std::string& path);

	void addNewStudent(lesson::Student student);

	virtual void Open() override;

	virtual void Save() override;

	virtual double GetAverageScore(const lesson::FullName& name) override;

	virtual std::string GetAllInfo(const lesson::FullName& name) override;

	virtual std::string GetAllInfo() override;
};


int randomVal(int min = 1, int max = 5);