#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <iostream>
#include "Person.hpp"
#include "IHasSalary.hpp"
#include <string>
class Employee : public Person, public IHasSalary
{
    public:
    Employee(std::string name, std::string surname, std::string address, std::string indexNumber, std::string pesel, bool sex);
	Employee(){}
	~Employee() override {}

	std::string getSalary() const override;

	void setSalary(std::string salary)override;

	void displayData()const override;

};


#endif