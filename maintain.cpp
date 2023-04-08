#include "maintain.hpp"

void displayDB(std::vector<std::shared_ptr<Student>> &vec)
{
	for (std::shared_ptr<Student> s : vec)
	{
		s->displayStudent();
	}
}

void addNewStudents(std::vector<std::shared_ptr<Student>> &vec)
{
	std::string name_;
	std::string surname_;
	std::string address_;
	std::string indexNumber_;
	std::string pesel_;
	std::string sex_;
	bool correctInputData = true, sexFlag;

	std::cout << "Enter name: ";
	std::getline(std::cin, name_);
	std::cout << "\nEnter surname: ";
	std::getline(std::cin, surname_);
	std::cout << "\nEnter address: ";
	std::getline(std::cin, address_);
	std::cout << "\nEnter index number: ";
	do
	{
		correctInputData = true;
		std::getline(std::cin, indexNumber_);
		try{
			std::cout<<std::stoll(indexNumber_);
		}
		catch(std::invalid_argument const &ex)
		{
			std::cout<<"wrong value, try again\nEnter index number: ";
			correctInputData = false;
		}
		
	} while (correctInputData == false);
	
	
	std::cout << "\nEnter pesel: ";
	do
	{
		correctInputData = true;
		std::getline(std::cin, pesel_);
		try{
			std::cout<<std::stoll(pesel_);
		}
		catch(std::invalid_argument const &ex)
		{
			std::cout<<"wrong input, try again\nEnter pesel: ";
			correctInputData = false;
		}
		
	} while (correctInputData == false);

	std::cout << "\nEnter sex [m/f]: ";
	while(true)
	{
		std::getline(std::cin, sex_);
		if(sex_ == "m" || sex_ == "f")
			break;
		std::cout<<"wrong input, try again\nEnter sex: ";
	}
	if(sex_ == "m")
		sexFlag = true;
	else
		sexFlag = false;
	
	std::cout << std::endl;
	vec.push_back(std::make_shared<Student>(name_, surname_, address_, indexNumber_, pesel_, sexFlag));
}

void searchBySurname(std::vector<std::shared_ptr<Student>> &vec)
{
	std::string surname;
	std::cout << "Enter surname: ";
	std::getline(std::cin, surname);
	std::cout << std::endl;
	for (std::shared_ptr<Student> s : vec)
	{
		if (s->getSurname().compare(surname) == 0)
			s->displayStudent();
		else
			std::cout << "Nothing found\n";
	}
}
void searchByPesel(std::vector<std::shared_ptr<Student>> &vec)
{
	std::string pesel;
	std::cout << "Enter pesel: ";
	std::getline(std::cin, pesel);
	std::cout << std::endl;
	for (std::shared_ptr<Student> s : vec)
	{
		if (s->getPesel().compare(pesel) == 0)
		{
			s->displayStudent();
			break;
		}
		else
			std::cout << "Nothing found\n";
	}
}

void sortByPesel(std::vector<std::shared_ptr<Student>> &vec)
{
	bool sorted = false;
	std::vector<std::shared_ptr<Student>>::iterator it;
	while (sorted == false)
	{
		sorted = true;

		for (it = vec.begin(); (it + 1) != vec.end(); it++)
		{
			if (stoll((*it)->getPesel()) > stoll((*(it + 1))->getPesel()))
			{
				(*it)->SwapData(*((*(it+1)).get()));
				sorted = false;
			}
		}
	}
}
void sortBySurname(std::vector<std::shared_ptr<Student>> &vec)
{
	std::string surname1, surname2;
	std::string::iterator char1, char2;
	Student swapHelper;
	bool sorted = false;
	std::vector<std::shared_ptr<Student>>::iterator it;
	while (sorted == false)
	{
		sorted = true;
		for (it = vec.begin(); (it + 1) != vec.end(); it++)
		{
			surname1 = (*it)->getSurname();
			surname2 = (*(it+1))->getSurname();
			char1 = surname1.begin();
			char2 = surname2.begin();
			while(true)
			{
				if(*char1>*char2)
				{
					(*it)->SwapData(*((*(it+1)).get()));
					break;
				}
				else if(*char1<*char2)
				{
					break;
				}
				else
				{
					if((char1+1) != surname1.end() && (char2+1) != surname2.end())
					{
						char1++;
						char2++;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
}
void deleteByIndexNumber(std::vector<std::shared_ptr<Student>> &vec)
{
	std::string indexNumber;
	std::cout << "Enter index number: ";
	std::getline(std::cin, indexNumber);
	std::cout << std::endl;
	std::vector<std::shared_ptr<Student>>::iterator it = vec.begin();
	while(true)
	{
		if(it==vec.end())
		{
			std::cout<<"nothing found\n";
			break;
		}
		if ((*it)->getIndexNumber().compare(indexNumber) == 0)
		{
			vec.erase(it);
			break;
		}
		else
			it++;
	}
}
