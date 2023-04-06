
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
void Student::displayStudent()
{
	std::cout << "Name: " << name_ << "\nSurname: " << surname_ << "\nAddress: " << address_ << "\nIndex number: " << indexNumber_
			  << "\nPesel: " << pesel_ << "\nSex: ";
	if (sex_ == true)
		std::cout << "Male" << std::endl;
	else
		std::cout << "Female" << std::endl;
}

std::string Student::getSurname() const
{
	return surname_;
}
std::string Student::getPesel() const
{
	return pesel_;
}
void Student::setPesel(std::string pesel)
{
	pesel_ = pesel;
}
