
#include "Student.hpp"
#include <iostream>
Student::Student(std::string name, std::string surname, std::string address, std::string indexNumber, std::string pesel, bool sex)
	: name_(name),
	  surname_(surname),
	  address_(address),
	  indexNumber_(indexNumber),
	  pesel_(pesel),
	  sex_(sex)
{
}
void Student::displayStudent()const
{
	std::cout << "Name: " << name_ << "\nSurname: " << surname_ << "\nAddress: " << address_ << "\nIndex number: " << indexNumber_
			  << "\nPesel: " << pesel_ << "\nSex: ";
	if (sex_ == true)
		std::cout << "Male" << std::endl;
	else
		std::cout << "Female" << std::endl;
}

void Student::SwapData(Student& student)
{
	std::string name, surname, address, indexNumber, pesel;
	bool sex;
	name = student.name_;
	surname = student.surname_;
	address = student.address_;
	pesel = student.pesel_;
	indexNumber = student.indexNumber_;
	sex = student.sex_;

	student.name_ = name_;
	student.surname_ = surname_;
	student.address_ = address_;
	student.pesel_ = pesel_;
	student.indexNumber_ = indexNumber_;
	student.sex_ = sex_;

	name_ = name;
	surname_ = surname;
	address_ = address;
	pesel_ = pesel;
	indexNumber_ = indexNumber;
	sex_ = sex;

}


std::string Student::getSurname() const
{
	return surname_;
}
std::string Student::getPesel() const
{
	return pesel_;
}
std::string Student::getaddress() const
{
	return address_;
}
std::string Student::getIndexNumber() const
{
	return indexNumber_;
}
std::string Student::getName() const
{
	return name_;
}
bool Student::getSex() const
{
	return sex_;
}
void Student::setName(std::string name)
{
	name_ = name;
}
void Student::setSurname(std::string surname)
{
	surname_ = surname;
}
void Student::setAddress(std::string address)
{
	address_ = address;
}
void Student::setIndexNumber(std::string indexNumber)
{
	indexNumber_ = indexNumber;
}
void Student::setPesel(std::string pesel)
{
	pesel_ = pesel;
}
void Student::setSex(bool sex)
{
	sex_ = sex;
}
