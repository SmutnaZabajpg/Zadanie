#pragma once
#include <iostream>
#include <ctime>

struct Date
{
	int day, month, year;
};

class Person
{
	std::string firstName, lastName;
	Date dateBirth;
	int height;
	//1 - Male
	//0 - Female
	bool gender;

	void CheckBirthDate()
	{
		time_t now = time(0);

		tm* ltm = new tm;
		localtime_s(ltm, &now);

		if (dateBirth.year < 1900 || dateBirth.year > ltm->tm_year + 1900)
			dateBirth.year = 2000;

		if (dateBirth.month < 1 || dateBirth.month > 12)
			dateBirth.month = 1;
	}

	void SetGender()
	{
		if (firstName.back() == 'a' || firstName.back() == 'e' || firstName.back() == 'y')
			gender = false;
		else
			gender = true;
	}

public:
	Person(std::string firstName, std::string lastName)
	{
		time_t now = time(0);

		tm* ltm = new tm;
		localtime_s(ltm, &now);

		this->firstName = firstName;
		this->lastName = lastName;

		dateBirth.year = 1900 + ltm->tm_year;
		dateBirth.month = 1 + ltm->tm_mon;
		dateBirth.day = ltm->tm_mday;

		height = 180;

		SetGender();

		delete ltm;
	}

	Person(std::string firstName, std::string lastName, Date date)
	{
		this->firstName = firstName;
		this->lastName = lastName;

		this->dateBirth.year = date.year;
		this->dateBirth.month = date.month;
		this->dateBirth.day = date.day;

		CheckBirthDate();

		height = 180;

		SetGender();
	}

	Person(std::string firstName, std::string lastName, Date date, int height)
	{
		this->firstName = firstName;
		this->lastName = lastName;

		this->dateBirth.year = date.year;
		this->dateBirth.month = date.month;
		this->dateBirth.day = date.day;

		CheckBirthDate();
		
		if (height < 300 && height > 0)
			this->height = height;
		else
			this->height = 180;

		SetGender();
	}

	void ShowPersonInfo()
	{
		time_t now = time(0);

		tm* ltm = new tm;
		localtime_s(ltm, &now);

		std::cout << "**********************************" << std::endl;
		std::cout << "First Name: " << firstName << std::endl;
		std::cout << "Last Name: " << lastName << std::endl;
		std::cout << "**********************************" << std::endl;

		std::cout << "Height: " << height << std::endl;
		std::cout << "Gender: ";

		if (gender == true)
			std::cout << "Male" << std::endl;
		else
			std::cout << "Female" << std::endl;

		std::cout << "Birth Date: " << dateBirth.year << "/" << dateBirth.month << "/" << dateBirth.day << std::endl;

		int age = ltm->tm_year + 1900 - dateBirth.year;
		std::cout << "Age: " << age << std::endl;
		std::cout << "**********************************" << std::endl;

		delete ltm;
	}

	void Majority()
	{
		time_t now = time(0);

		tm* ltm = new tm;
		localtime_s(ltm, &now);

		int age = ltm->tm_year + 1900 - dateBirth.year;

		std::cout << "Majority: ";
		if (age < 18)
			std::cout << "No" << std::endl;
		else if (dateBirth.month - (ltm->tm_mon + 1) < 0)
			std::cout << "No" << std::endl;
		else if(dateBirth.day - ltm->tm_mday < 0)
			std::cout << "No" << std::endl;
		else 
			std::cout << "Yes" << std::endl;
		delete ltm;
	}

	void InfoUpdate(std::string firstName, std::string lastName)
	{
		this->firstName = firstName;
		this->lastName = lastName;
	}

	void InfoUpdate(int height)
	{
		if (height > 0 && height < 300)
			this->height = height;
	}
};

