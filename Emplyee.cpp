#include "Employee.hpp"
Employee::Employee(std::string name, std::string surname, std::string address, std::string salary, std::string pesel, bool sex)
	: Person(name, surname, address, pesel, sex)
	  ,IHasSalary(salary)
{
}
std::string Employee::getSalary() const
{
	return salary_;
}

void Employee::setSalary(std::string salary)
{
	salary_ = salary;
}


void Employee::displayData()const
{
	std::cout << "Name: " << name_ << "\nSurname: " << surname_ << "\nAddress: " << address_ << "\nSalary: " << salary_
			  << "\nPesel: " << pesel_ << "\nSex: ";
	if (sex_ == true)
		std::cout << "Male" << std::endl;
	else
		std::cout << "Female" << std::endl;
}