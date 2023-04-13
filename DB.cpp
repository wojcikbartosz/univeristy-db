#include "DB.hpp"
#include "Student.hpp"
#include "Employee.hpp"
#include "IHasIndexNumber.hpp"
#include "IHasSalary.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>  
void DB::displayDB()
{
    for (std::shared_ptr<Person> s : Persons)
    {
        std::cout<<"--------------\n";
        s->displayData();
        std::cout<<"--------------\n";
    }
}
void DB::addNewPerson(bool type)
{
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string indexNumberOrSalary_;
    std::string Id_;
    std::string sex_;
    bool correctInputData = true, sexFlag;

    std::cout << "\nEnter name: ";
    std::getline(std::cin, name_);
    std::cout << "\nEnter surname: ";
    std::getline(std::cin, surname_);
    std::cout << "\nEnter address: ";
    std::getline(std::cin, address_);

    std::cout << "\nEnter Id: ";
    do
    {
        correctInputData = true;
        std::getline(std::cin, Id_);
        try
        {
            std::stoll(Id_);
        }
        catch (std::invalid_argument const &ex)
        {
            std::cout << "wrong input, try again\nEnter Id: ";
            correctInputData = false;
        }

    } while (correctInputData == false);

    std::cout << "\nEnter sex [m/f]: ";
    while (true)
    {
        std::getline(std::cin, sex_);
        if (sex_ == "m" || sex_ == "f")
            break;
        std::cout << "wrong input, try again\nEnter sex: ";
    }
    if (sex_ == "m")
        sexFlag = true;
    else
        sexFlag = false;
    if (type == false)
    {

        std::cout << "\nEnter index number: ";
        do
        {
            correctInputData = true;
            std::getline(std::cin, indexNumberOrSalary_);
            try
            {
                std::stoll(indexNumberOrSalary_);
            }
            catch (std::invalid_argument const &ex)
            {
                std::cout << "wrong value, try again\nEnter index number: ";
                correctInputData = false;
            }

        } while (correctInputData == false);
        Persons.push_back(std::make_shared<Student>(name_, surname_, address_, indexNumberOrSalary_, Id_, sexFlag));
    }
    else
    {
        std::cout << "\nEnter salary: ";
        do
        {
            correctInputData = true;
            std::getline(std::cin, indexNumberOrSalary_);
            try
            {
                std::stod(indexNumberOrSalary_);
            }
            catch (std::invalid_argument const &ex)
            {
                std::cout << "wrong value, try again\nEnter salary: ";
                correctInputData = false;
            }

        } while (correctInputData == false);
        Persons.push_back(std::make_shared<Employee>(name_, surname_, address_, indexNumberOrSalary_, Id_, sexFlag));
    }
}
void DB::searchBySurname()
{
    std::string surname;
	std::cout << "Enter surname: ";
	std::getline(std::cin, surname);
	std::cout << std::endl;
	for (std::shared_ptr<Person> person : Persons)
	{
		if (person->getSurname().compare(surname) == 0)
			person->displayData();
		else
			std::cout << "Nothing found\n";
	}
}
void DB::searchById()
{
    std::string Id;
	std::cout << "Enter Id: ";
	std::getline(std::cin, Id);
	std::cout << std::endl;
	for (std::shared_ptr<Person> person : Persons)
	{
		if (person->getId().compare(Id) == 0)
		{
			person->displayData();
			break;
		}
		else
			std::cout << "Nothing found\n";
	}
}
void DB::sortById()
{
    if(Persons.size()<2)
	{
		return;
	}
	bool sorted = false;
	std::vector<std::shared_ptr<Person>>::iterator it;
	while (sorted == false)
	{
		sorted = true;

		for (it = Persons.begin(); (it + 1) != Persons.end(); it++)
		{
			if (std::stoll((*it)->getId()) > std::stoll((*(it + 1))->getId()))
			{
				std::iter_swap(it, it + 1);
				sorted = false;
			}
		}
	}
}
void DB::sortBySurname()
{
    if(Persons.size()<2)
	{
		return;
	}
	std::string surname1, surname2;
	std::string::iterator char1, char2;
	bool sorted = false;
	std::vector<std::shared_ptr<Person>>::iterator it;
	while (sorted == false)
	{
		sorted = true;
		for (it = Persons.begin(); (it + 1) != Persons.end(); it++)
		{
			surname1 = (*it)->getSurname();
			surname2 = (*(it + 1))->getSurname();
			char1 = surname1.begin();
			char2 = surname2.begin();
			while (true)
			{
				if (*char1 > *char2)
				{
					std::iter_swap(it, it + 1);
					sorted = false;
					break;
				}
				else if (*char1 < *char2)
				{
					break;
				}
				else
				{
					if ((char1 + 1) != surname1.end() && (char2 + 1) != surname2.end())
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
void DB::deleteByIndexNumber()
{
    std::string indexNumber;
	std::cout << "Enter index number: ";
	std::getline(std::cin, indexNumber);
	std::cout << std::endl;
	std::vector<std::shared_ptr<Person>>::iterator it = Persons.begin();
	while (true)
	{
		if (it == Persons.end())
		{
			std::cout << "nothing found\n";
			break;
		}
		if (dynamic_cast<IHasIndexNumber *>((*it).get()))
		{
			IHasIndexNumber *student = dynamic_cast<IHasIndexNumber *>((*it).get());
			if (student->getIndexNumber().compare(indexNumber) == 0)
			{
				Persons.erase(it);
				break;
			}
			it++;
		}

		else
			it++;
	}
}
void DB::changeSalaryById()
{
    std::string Id;
	std::cout << "Enter Id: ";
	std::getline(std::cin, Id);
	std::cout << std::endl;
	for (std::shared_ptr<Person> employee : Persons)
	{
		if (employee->getId().compare(Id) == 0)
		{
			if (dynamic_cast<IHasSalary *>(employee.get()))
			{
				bool correctInputData = false;
				std::string salary_;
				std::cout << "enter new salary: ";
				do
				{
					correctInputData = true;
					std::getline(std::cin, salary_);
					try
					{
						std::cout << std::stoll(salary_);
					}
					catch (std::invalid_argument const &ex)
					{
						std::cout << "wrong value, try again\nEnter salary: ";
						correctInputData = false;
					}

				} while (correctInputData == false);
				IHasSalary *employeePtr = dynamic_cast<IHasSalary *>(employee.get());
				employeePtr->setSalary(salary_);
				return;
			}
		}
	}
	std::cout << "Nothing found\n";
}
void DB::sortBySalary()
{
    if(Persons.size()<2)
	{
		return;
	}
	swapEmployeesToTheBeginning();
	std::vector<std::shared_ptr<Person>>::iterator it;
	bool sorted = false;
	while(sorted == false)
	{
		sorted = true;
		for(it=Persons.begin();it!=Persons.end();it++)
		{
			if(dynamic_cast<IHasSalary *>((*it).get()) && dynamic_cast<IHasSalary *>((*(it+1)).get()))
			{
				IHasSalary* employee1, *employee2;
				employee1 = dynamic_cast<IHasSalary *>((*it).get());
				employee2 = dynamic_cast<IHasSalary *>((*(it+1)).get());
				if(std::stod(employee1->getSalary()) > std::stod(employee2->getSalary()))
				{
					std::iter_swap(it,it+1);
				}
			}
		}
	}
}
void DB::swapEmployeesToTheBeginning()
{
    std::vector<std::shared_ptr<Person>>::iterator it1, it2;

	while (true)
	{
		for (it1 = Persons.begin(); it1 != Persons.end(); it1++)
		{
			if (dynamic_cast<IHasSalary *>((*it1).get()) == nullptr)
			{
				for (it2 = it1+1; it2 != Persons.end(); it2++)
				{
					if (dynamic_cast<IHasSalary *>((*it2).get()))
					{
						std::iter_swap(it1, it2);
						break;
					}
					else if(it2+1 == Persons.end())
					{
						return;
					}
				}
			}
		}
	}
}
void DB::generateRandomData(int amount)
{
    srand(time(0));
    std::string names[] = {"Azriel","Gordon","Jean-luc","William","Beverly","Amanda","Liara"};
    std::string surNames[] = {"Odin","Freeman","Picard","Riker","Crusher","Ripley","T'soni"};
    std::string addresses[] = {"Gemini Colony","City 17","NCC-1701-D","Riker's farm","NCC-1701-A","Sevastopol station","SSV Normandy"};
    std::string name, surName, address, id, indexOrSalary;
    bool sex;
    for (int i=0;i<amount;i++)
    {
        name = names[rand()%7];
        surName = surNames[rand()%7];
        address = address[rand()%7];
        id  = std::to_string(rand()%89999999999 + 10000000000);
        sex = rand()%2;
        if((rand() % 2) == 0)
        {
            indexOrSalary = std::to_string(rand() % 899999 + 100000);
            Persons.push_back(std::make_shared<Student>(name, surName, address, indexOrSalary, id, sex));
        }
        else
        {
            indexOrSalary = std::to_string(((double)(rand() % 8000 + 2000))/((double)(rand() % 10 + 1)));
            Persons.push_back(std::make_shared<Employee>(name, surName, address, indexOrSalary, id, sex));
        }
    }
    
}