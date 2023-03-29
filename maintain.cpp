#include "maintain.hpp"


void displayDB(std::vector<std::shared_ptr<Student>>& vec)
{
	for(std::shared_ptr<Student> s: vec)
	{
		s->displayStudent();
	}
}

void addNewStudents(std::vector<std::shared_ptr<Student>>& vec)
{
	std::string name_;
	std::string surename_;
	std::string address_;
	std::string indexNumber_;
	std::string pesel_;
	std::string sex_;
	
	std::cout<<"Enter name: ";
	std::getline(std::cin, name_);
	std::cout<<"\nEnter surename: ";
	std::getline(std::cin, surename_);
	std::cout<<"\nEnter address: ";
	std::getline(std::cin, address_);
	std::cout<<"\nEnter index number: ";
	std::getline(std::cin, indexNumber_);
	std::cout<<"\nEnter pesel: ";
	std::getline(std::cin, pesel_);
	std::cout<<"\nEnter sex [m/f]: ";
	std::getline(std::cin, sex_);
	std::cout<<std::endl;
	vec.push_back(std::make_shared<Student>(Student(name_,surename_,address_, indexNumber_,pesel_,false)));
}

void searchBySurename(std::vector<std::shared_ptr<Student>>& vec)
{
	std::string surename;
	std::cout<<"Enter surename: ";
	std::getline(std::cin, surename);
	std::cout<<std::endl;
	for(std::shared_ptr<Student> s : vec)
	{
		if(s->getSurename().compare(surename) == 0)
			s->displayStudent();
		else
			std::cout<<"Nothing found\n";
	}
}