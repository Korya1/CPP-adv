#include "pch.h"

class TestPerson : public testing::Test
{
protected:
	void SetUp() override
	{
		person = new Person("Davidov", "Saveiliy", "Petrovich");
	}

	void TearDown() override
	{
		delete person;
	}

	Person* person;
};


TEST_F(TestPerson, get_methods)
{
	ASSERT_EQ(person->firstName, "Davidov");
	ASSERT_EQ(person->secondName, "Saveiliy");
	ASSERT_EQ(person->patronymic, "Petrovich");
}

TEST_F(TestPerson, get_methods_ne)
{
	ASSERT_NE(person->firstName, "Maksym");
	ASSERT_NE(person->secondName, "Afonasiev");
	ASSERT_NE(person->patronymic, "Andreevich");
}

TEST_F(TestPerson, set_methods)
{
	person->firstName = "Maksym";
	ASSERT_EQ(person->firstName, "Maksym");
	person->secondName = "Afonasiev";
	ASSERT_EQ(person->secondName, "Afonasiev");
	person->patronymic = "Andreevich";
	ASSERT_EQ(person->patronymic, "Andreevich");
}

class TestPhoneNumber : public testing::Test
{
protected:
	void SetUp() override
	{
		phone = new PhoneNumber(81, 8281, "7420182", 2);
	}

	void TearDown() override
	{
		delete phone;
	}

	PhoneNumber* phone;
};

TEST_F(TestPhoneNumber, get_methods)
{
	ASSERT_EQ(phone->idCountry, 81);
	ASSERT_EQ(phone->idCity, 8281);
	ASSERT_EQ(phone->number, "7420182");
	ASSERT_EQ(phone->idAdditional, 2);
}

TEST_F(TestPhoneNumber, get_methods_ne)
{
	ASSERT_NE(phone->idCountry, 23);
	ASSERT_NE(phone->idCity, 12312);
	ASSERT_NE(phone->number, "21332");
	ASSERT_NE(phone->idAdditional, 7);
}

TEST_F(TestPhoneNumber, set_methods)
{
	phone->idCountry = 23;
	ASSERT_EQ(phone->idCountry, 23);
	phone->idCity = 12312;
	ASSERT_EQ(phone->idCity, 12312);
	phone->number = "21332";
	ASSERT_EQ(phone->number, "21332");
	phone->idAdditional = 7;
	ASSERT_EQ(phone->idAdditional, 7);
}


std::ifstream file("PhoneBook.txt");
class TestPhoneBook : public testing::Test
{

protected:
	void SetUp() override
	{
		book = new PhoneBook(file);
	}

	void TearDown() override
	{
		delete book;
	}

	PhoneBook* book;
};

TEST_F(TestPhoneBook, get_methods)
{
	std::stringstream s, f;
	auto value1 = book->GetPhoneNumber("Zaytseff");
	s << value1.second;
	ASSERT_EQ(s.str(), "+125(44)4164751");

	auto value2 = book->GetPhoneNumber("Dubinin");
	f << value2.second;
	ASSERT_EQ(f.str(), "+7(473)7449054");
}

std::ifstream file2("PhoneBook.txt");
class TestPhoneBook2 : public testing::Test
{

protected:
	void SetUp() override
	{
		book = new PhoneBook(file2);
	}

	void TearDown() override
	{
		delete book;
	}

	PhoneBook* book;
};

TEST_F(TestPhoneBook2, get_methods_ne)
{
	std::stringstream s;
	auto value = book->GetPhoneNumber("Dubinin");
	s << value.second;
	ASSERT_NE(s.str(), "+55(23)1231231");
}

std::ifstream file3("PhoneBook.txt");
class TestPhoneBook3 : public testing::Test
{

protected:
	void SetUp() override
	{
		book = new PhoneBook(file3);
	}

	void TearDown() override
	{
		delete book;
	}

	PhoneBook* book;
};

TEST_F(TestPhoneBook3, get_methods_more_than_one)
{
	std::stringstream s;
	auto value = book->GetPhoneNumber("Igorov");
	s << value.first;
	ASSERT_EQ(s.str(), "found more than 1");
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}