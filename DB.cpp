#include "DB.hpp"

void DB::displayDB()
{
	for (std::shared_ptr<Person> s : Persons)
	{
		s->displayData();
	}
}
void DB::addNewPerson()
{
	std::string name_;
	std::string surname_;
	std::string address_;
	std::string indexNumberOrSalary_;
	std::string Id_;
	std::string sex_;
	std::string type;
	bool correctInputData = true;

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
			if (std::to_string(std::stoll(Id_)).compare(Id_) != 0)
				throw std::invalid_argument("");
		}
		catch (std::invalid_argument const &ex)
		{
			std::cout << "wrong input, try again\nEnter Id: ";
			correctInputData = false;
			continue;
		}
		if (Id_.length() != 11)
		{
			std::cout << "wrong input, try again\nEnter Id: ";
			correctInputData = false;
		}
		else if (checkIdCorrectness(Id_) == false)
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
		std::cout << "wrong input, try again\nEnter sex: [m/f]";
	}
	if (sex_ == "m")
		sex_ = "male";
	else
		sex_ = "female";

	std::cout<<"\nEnter function [e/s] e - employee s - student: ";
	while (true)
	{
		std::getline(std::cin, type);
		if (type == "e" || type == "s")
			break;
		std::cout << "wrong input, try again\nEnter function [e/s]: ";
	}
	if (type == "s")
	{

		std::cout << "\nEnter index number: ";
		do
		{
			correctInputData = true;
			std::getline(std::cin, indexNumberOrSalary_);
			try
			{
				if (std::to_string(std::stoll(indexNumberOrSalary_)).compare(indexNumberOrSalary_) != 0)
					throw std::invalid_argument("");
			}
			catch (std::invalid_argument const &ex)
			{
				std::cout << "wrong value, try again\nEnter index number: ";
				correctInputData = false;
				continue;
			}
			if(indexNumberOrSalary_.length()>6)
			{
				std::cout << "wrong value, try again\nEnter index number: ";
				correctInputData = false;
			}

		} while (correctInputData == false);
		Persons.push_back(std::make_shared<Student>(name_, surname_, address_, Id_, sex_, indexNumberOrSalary_));
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
		Persons.push_back(std::make_shared<Employee>(name_, surname_, address_, Id_, sex_, indexNumberOrSalary_));
	}
}
void DB::searchBySurname()
{
	std::string surname;
	std::cout << "Enter surname: ";
	std::getline(std::cin, surname);
	std::cout << std::endl;
	bool result = false;
	for (std::shared_ptr<Person> person : Persons)
	{
		if (person->getSurname().compare(surname) == 0)
		{
			person->displayData();
			result = true;
		}
	}
	if (result == false)
	{
		std::cout << "nothing found\n";
	}
}
void DB::searchById()
{
	std::string Id;
	std::cout << "Enter Id: ";
	std::getline(std::cin, Id);
	std::cout << std::endl;
	bool result = false;
	for (std::shared_ptr<Person> person : Persons)
	{
		if (person->getId().compare(Id) == 0)
		{
			person->displayData();
			result = true;
			break;
		}
	}
	if (result == false)
	{
		std::cout << "nothing found\n";
	}
}
void DB::sortById()
{
	if (Persons.size() < 2)
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
	if (Persons.size() < 2)
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
	if (Persons.size() < 2)
	{
		return;
	}
	swapEmployeesToTheBeginning();
	std::vector<std::shared_ptr<Person>>::iterator it;
	bool sorted = false;
	while (sorted == false)
	{
		sorted = true;
		for (it = Persons.begin(); it != Persons.end(); it++)
		{
			if (dynamic_cast<IHasSalary *>((*it).get()) && dynamic_cast<IHasSalary *>((*(it + 1)).get()))
			{
				IHasSalary *employee1, *employee2;
				employee1 = dynamic_cast<IHasSalary *>((*it).get());
				employee2 = dynamic_cast<IHasSalary *>((*(it + 1)).get());
				if (std::stod(employee1->getSalary()) > std::stod(employee2->getSalary()))
				{
					std::iter_swap(it, it + 1);
					sorted = false;
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
				for (it2 = it1 + 1; it2 != Persons.end(); it2++)
				{
					if (dynamic_cast<IHasSalary *>((*it2).get()))
					{
						std::iter_swap(it1, it2);
						break;
					}
					else if (it2 + 1 == Persons.end())
					{
						return;
					}
				}
			}
		}
	}
}
void DB::generateRandomData()
{
	srand(static_cast<unsigned int>(time(0)));
	std::string names[] = {"Azriel", "Gordon", "Jean-luc", "William", "Beverly", "Amanda", "Liara"};
	std::string surNames[] = {"Odin", "Freeman", "Picard", "Riker", "Crusher", "Ripley", "T'soni"};
	std::string addresses[] = {"Gemini Colony", "City 17", "NCC-1701-D", "Riker's farm", "NCC-1701-A", "Sevastopol station", "SSV Normandy"};
	std::string name, surName, address, id, indexOrSalary, sex;
	for (int i = 0; i < 10; i++)
	{
		name = names[rand() % 7];
		surName = surNames[rand() % 7];
		address = addresses[rand() % 7];
		id = std::to_string(rand() % 89999999999 + 10000000000);
		if ((rand() % 2) == 0)
		{
			sex = "male";
		}
		else
		{
			sex = "female";
		}
		if ((rand() % 2) == 0)
		{
			indexOrSalary = std::to_string(rand() % 899999 + 100000);
			Persons.push_back(std::make_shared<Student>(name, surName, address, id, sex, indexOrSalary));
		}
		else
		{
			indexOrSalary = std::to_string(((double)(rand() % 8000 + 2000)) / ((double)(rand() % 10 + 1)));
			Persons.push_back(std::make_shared<Employee>(name, surName, address, id, sex, indexOrSalary));
		}
	}
}
bool DB::checkIdCorrectness(std::string const &idNumber)
{
	int sum = 0;
	std::string number;
	for (int i = 0; i < 10; i++)
	{
		number = idNumber[i];
		switch (i % 4)
		{
		case 0:
		{
			sum += std::stoi(number);
			break;
		}
		case 1:
		{
			sum += std::stoi(number) * 3;
			break;
		}
		case 2:
		{
			sum += std::stoi(number) * 7;
			break;
		}
		case 3:
		{
			sum += std::stoi(number) * 9;
			break;
		}
		}
	}
	sum = sum % 10;
	number = idNumber[10];
	if (sum == 0 && stoi(number) == 0)
	{
		return true;
	}
	sum = 10 - sum;
	if (sum == stoi(number))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void DB::saveDbToFile()
{
	std::fstream file;
	file.open("DB",std::ios::out | std::ios::trunc);
	if(!file.is_open())
	{
		std::cout<<"cant open file\n";
		return;
	}
	std::string row = "";
	for(std::shared_ptr<Person> person: Persons)
	{
		row.append(person->getName());
		row.append("|");
		row.append(person->getSurname());
		row.append("|");
		row.append(person->getAddress());
		row.append("|");
		row.append(person->getId());
		row.append("|");
		row.append(person->getSex());
		row.append("|");
		if (dynamic_cast<IHasIndexNumber *>(person.get()))
		{
			IHasIndexNumber *student = dynamic_cast<IHasIndexNumber *>(person.get());
			row.append(student->getIndexNumber());
			row.append("|{STUDENT}");
		}
		else if(dynamic_cast<IHasSalary *>(person.get()))
		{
			IHasSalary *employee = dynamic_cast<IHasSalary *>(person.get());
			row.append(employee->getSalary());
			row.append("|{EMPLOYEE}");
		}
		row.append("|\n");
		file.write(row.c_str(),row.length());
		row.clear();
	}
	file.close();
}
void DB::loadDbFromFile()
{
	std::fstream file;
	file.open("DB",std::ios::in);
	if(!file.is_open())
	{
		std::cout<<"cant open file\n";
		return;
	}
	char row[1024];
	std::string data[7]; 
	int pos = 0;
	while(true)
	{
		for(int i=0;i<7;i++)
		{
			data[i].clear();
		}
		for(int i=0;i<1024;i++)
		{
			row[i] = '\0';
		}
		
		file.getline(row,1024);
		if(file.eof())
			break;
		pos = 0;
		for(int i=0;i<7;i++)
		{
			while(true)
			{
				if(row[pos] == '|')
				{
					pos++;
					break;
				}
				else
				{
					data[i]+=row[pos];
					pos++;
				}
				
			}
			std::cout<<data[i]<<std::endl;
		}
		if(data[6] == "{EMPLOYEE}")
			Persons.push_back(std::make_shared<Employee>(data[0], data[1], data[2], data[3], data[4], data[5]));
		else if(data[6] == "{STUDENT}")
			Persons.push_back(std::make_shared<Student>(data[0], data[1], data[2], data[3], data[4], data[5]));

		
	}
	file.close();
}