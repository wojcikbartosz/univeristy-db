#include "maintain.hpp"

void addNewStudents(std::vector<std::shared_ptr<Student>>& vec)
{
	std::string name_;
	std::string surename_;
	std::string address_;
	std::string indexNumber_;
	std::string pesel_;
	bool sex_;
	
	std::cout<<"Enter name: ";
	std::cin>>name_;
	std::cout<<"\nEnter surename: ";
	std::cin>>surename_;
	std::cout<<"\nEnter address: ";
	std::cin>>address_;
	std::cout<<"\nEnter index number: ";
	std::cin>> indexNumber_;
	std::cout<<"\nEnter pesel: ";
	std::cin>>pesel_;
	std::cout<<"\nEnter sex [m/f]: ";
	std::cin>>sex_;
	std::cout<<std::endl;
	vec.push_back(std::make_shared<Student>(Student(name_,surename_,address_, indexNumber_,pesel_,false)));
}