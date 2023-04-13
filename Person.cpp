#include "Person.hpp"
Person::Person(std::string name, std::string surname, std::string address, std::string Id, std::string sex)
: name_(name),
	  surname_(surname),
	  address_(address),
	  Id_(Id),
	  sex_(sex)
{
}




std::string Person::getSurname() const
{
	return surname_;
}
std::string Person::getId() const
{
	return Id_;
}
std::string Person::getAddress() const
{
	return address_;
}
std::string Person::getName() const
{
	return name_;
}
std::string Person::getSex() const
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
void Person::setId(std::string Id)
{
	Id_ = Id;
}
void Person::setSex(std::string sex)
{
	sex_ = sex;
}