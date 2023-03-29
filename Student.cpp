
#include "Student.hpp"
#include <iostream>
Student::Student (std::string name, std::string surename, std::string address, std::string indexNumber, std::string pesel, bool sex)
:name_(name),
 surename_(surename),
 address_(address),
 indexNumber_(indexNumber),
 pesel_(pesel),
 sex_(sex)
{}
void Student::displayStudent()
{
		std::cout<<"Name: "<<name_<<"\nSurename: "<<surename_<<"\nAddress: "<<address_<<"\nIndex number: "<<indexNumber_
				<<"\nPesel: "<<pesel_<<"\nSex: "<<pesel_<<std::endl;
}

