
#include "Student.hpp"
#include <iostream>
Student::Student(std::string name, std::string surname, std::string address, std::string indexNumber, std::string pesel, bool sex)
	: Person(name, surname, address, pesel, sex)
	  ,IHasIndexNumber(indexNumber)
{
}
std::string Student::getIndexNumber() const
{
	return indexNumber_;
}
void Student::setIndexNumber(std::string indexNumber)
{
	indexNumber_ = indexNumber;
}


void Student::displayData()const
{
	std::cout << "Name: " << name_ << "\nSurname: " << surname_ << "\nAddress: " << address_ << "\nIndex number: " << indexNumber_
			  << "\nPesel: " << pesel_ << "\nSex: ";
	if (sex_ == true)
		std::cout << "Male" << std::endl;
	else
		std::cout << "Female" << std::endl;
}
