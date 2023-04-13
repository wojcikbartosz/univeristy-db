#include "maintain.hpp"

void displayDB(std::vector<std::shared_ptr<Person>> &vec)
{
	for (std::shared_ptr<Person> s : vec)
	{
		s->displayData();
	}
}

void addNewStudent(std::vector<std::shared_ptr<Person>> &vec)
{
	std::string name_;
	std::string surname_;
	std::string address_;
	std::string indexNumber_;
	std::string Id_;
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
		try
		{
			std::cout << std::stoll(indexNumber_);
		}
		catch (std::invalid_argument const &ex)
		{
			std::cout << "wrong value, try again\nEnter index number: ";
			correctInputData = false;
		}

	} while (correctInputData == false);

	std::cout << "\nEnter Id: ";
	do
	{
		correctInputData = true;
		std::getline(std::cin, Id_);
		try
		{
			std::cout << std::stoll(Id_);
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

	std::cout << std::endl;
	vec.push_back(std::make_shared<Student>(name_, surname_, address_, indexNumber_, Id_, sexFlag));
}

void addNewEmployee(std::vector<std::shared_ptr<Person>> &vec)
{
	std::string name_;
	std::string surname_;
	std::string address_;
	std::string salary_;
	std::string Id_;
	std::string sex_;
	bool correctInputData = true, sexFlag;

	std::cout << "Enter name: ";
	std::getline(std::cin, name_);
	std::cout << "\nEnter surname: ";
	std::getline(std::cin, surname_);
	std::cout << "\nEnter address: ";
	std::getline(std::cin, address_);
	std::cout << "\nEnter salary: ";
	do
	{
		correctInputData = true;
		std::getline(std::cin, salary_);
		try
		{
			std::cout << std::stod(salary_);
		}
		catch (std::invalid_argument const &ex)
		{
			std::cout << "wrong value, try again\nEnter salary: ";
			correctInputData = false;
		}

	} while (correctInputData == false);

	std::cout << "\nEnter Id: ";
	do
	{
		correctInputData = true;
		std::getline(std::cin, Id_);
		try
		{
			std::cout << std::stoll(Id_);
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

	std::cout << std::endl;
	vec.push_back(std::make_shared<Employee>(name_, surname_, address_, salary_, Id_, sexFlag));
}

void searchBySurname(std::vector<std::shared_ptr<Person>> &vec)
{
	std::string surname;
	std::cout << "Enter surname: ";
	std::getline(std::cin, surname);
	std::cout << std::endl;
	for (std::shared_ptr<Person> s : vec)
	{
		if (s->getSurname().compare(surname) == 0)
			s->displayData();
		else
			std::cout << "Nothing found\n";
	}
}
void searchById(std::vector<std::shared_ptr<Person>> &vec)
{
	std::string Id;
	std::cout << "Enter Id: ";
	std::getline(std::cin, Id);
	std::cout << std::endl;
	for (std::shared_ptr<Person> s : vec)
	{
		if (s->getId().compare(Id) == 0)
		{
			s->displayData();
			break;
		}
		else
			std::cout << "Nothing found\n";
	}
}

void sortById(std::vector<std::shared_ptr<Person>> &vec)
{
	if(vec.size()<2)
	{
		return;
	}
	bool sorted = false;
	std::vector<std::shared_ptr<Person>>::iterator it;
	while (sorted == false)
	{
		sorted = true;

		for (it = vec.begin(); (it + 1) != vec.end(); it++)
		{
			if (std::stoll((*it)->getId()) > std::stoll((*(it + 1))->getId()))
			{
				std::iter_swap(it, it + 1);
				sorted = false;
			}
		}
	}
}
void sortBySurname(std::vector<std::shared_ptr<Person>> &vec)
{
	if(vec.size()<2)
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
		for (it = vec.begin(); (it + 1) != vec.end(); it++)
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
void deleteByIndexNumber(std::vector<std::shared_ptr<Person>> &vec)
{
	std::string indexNumber;
	std::cout << "Enter index number: ";
	std::getline(std::cin, indexNumber);
	std::cout << std::endl;
	std::vector<std::shared_ptr<Person>>::iterator it = vec.begin();
	while (true)
	{
		if (it == vec.end())
		{
			std::cout << "nothing found\n";
			break;
		}
		if (dynamic_cast<IHasIndexNumber *>((*it).get()))
		{
			IHasIndexNumber *student = dynamic_cast<IHasIndexNumber *>((*it).get());
			if (student->getIndexNumber().compare(indexNumber) == 0)
			{
				vec.erase(it);
				break;
			}
			it++;
		}

		else
			it++;
	}
}
void changeSalaryById(std::vector<std::shared_ptr<Person>> &vec)
{
	std::string Id;
	std::cout << "Enter Id: ";
	std::getline(std::cin, Id);
	std::cout << std::endl;
	for (std::shared_ptr<Person> employee : vec)
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
void swapEmployeesToTheBeginning(std::vector<std::shared_ptr<Person>> &vec)
{
	std::vector<std::shared_ptr<Person>>::iterator it1, it2;

	while (true)
	{
		for (it1 = vec.begin(); it1 != vec.end(); it1++)
		{
			if (dynamic_cast<IHasSalary *>((*it1).get()) == nullptr)
			{
				for (it2 = it1+1; it2 != vec.end(); it2++)
				{
					if (dynamic_cast<IHasSalary *>((*it2).get()))
					{
						std::iter_swap(it1, it2);
						break;
					}
					else if(it2+1 == vec.end())
					{
						return;
					}
				}
			}
		}
	}
}
void sortBySalary(std::vector<std::shared_ptr<Person>> &vec)
{
	if(vec.size()<2)
	{
		return;
	}
	swapEmployeesToTheBeginning(vec);
	std::vector<std::shared_ptr<Person>>::iterator it;
	bool sorted = false;
	while(sorted == false)
	{
		sorted = true;
		for(it=vec.begin();it!=vec.end();it++)
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