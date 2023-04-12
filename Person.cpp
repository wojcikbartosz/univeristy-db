#include "Person.hpp"
Person::Person(std::string name, std::string surname, std::string address, std::string pesel, bool sex)
: name_(name),
	  surname_(surname),
	  address_(address),
	  pesel_(pesel),
	  sex_(sex)
{
}

std::string Person::getSurname() const
{
	return surname_;
}
std::string Person::getPesel() const
{
	return pesel_;
}
std::string Person::getAddress() const
{
	return address_;
}
std::string Person::getName() const
{
	return name_;
}
bool Person::getSex() const
{
	return sex_;
}
void Person::setName(std::string name)
{
	name_ = name;
}
void Person::setSurname(std::string surname)
{
	surname_ = surname;
}
void Person::setAddress(std::string address)
{
	address_ = address;
}
void Person::setPesel(std::string pesel)
{
	pesel_ = pesel;
}
void Person::setSex(bool sex)
{
	sex_ = sex;
}