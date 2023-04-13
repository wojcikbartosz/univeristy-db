
#include "Student.hpp"
#include <iostream>
Student::Student(std::string name, std::string surname, std::string address, std::string indexNumber, std::string Id, std::string sex)
	: Person(name, surname, address, Id, sex)
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
	std::cout<<"--------------\n";
	std::cout << "Name: " << name_ << "\nSurname: " << surname_ << "\nAddress: " << address_ << "\nIndex number: " << indexNumber_
			  << "\nId: " << Id_ << "\nSex: "<<sex_<<std::endl;
	std::cout<<"--------------\n";
}
