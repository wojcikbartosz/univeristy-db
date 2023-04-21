#include <iostream>
#include "DB.hpp"
using namespace std;

int main()
{
	DB dataBase;
	while (true)
	{
		string input;
		size_t option = 0;
		std::cout << "chose option:\n\n";
		std::cout << "1 - display database\n";
		std::cout << "2 - add new person to database\n";
		std::cout << "3 - search person by surname\n";
		std::cout << "4 - search person by id\n";
		std::cout << "5 - sort database by id\n";
		std::cout << "6 - sort database by surname\n";
		std::cout << "7 - sort database by salary\n";
		std::cout << "8 - change salary by id\n";
		std::cout << "9 - delete by index number\n";
		std::cout << "10 - generate random data\n";
		std::cout << "11 - save data to file\n";
		std::cout << "12 - load data from file\n";
		std::cout << "0 - quit program\n\n";
		std::cout << "you input: ";

		std::getline(std::cin, input);
		try
		{
			option = std::stoi(input);
		}
		catch(std::invalid_argument const &ex)
		{
			std::cout << "Wrong input. Try again\n";
			continue;
		}
		switch (option)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			dataBase.displayDB();
			break;
		}
		case 2:
		{
			dataBase.addNewPerson();
			break;
		}
		case 3:
		{
			dataBase.searchBySurname();
			break;
		}
		case 4:
		{
			dataBase.searchById();
			break;
		}
		case 5:
		{
			dataBase.sortById();
			break;
		}
		case 6:
		{
			dataBase.sortBySurname();
			break;
		}
		case 7:
		{
			dataBase.sortBySalary();
			break;
		}
		case 8:
		{
			dataBase.changeSalaryById();
			break;
		}
		case 9:
		{
			dataBase.deleteByIndexNumber();
			break;
		}
		case 10:
		{
			dataBase.generateRandomData();
			break;
		}
		case 11:
		{
			dataBase.saveDbToFile();
			break;
		}
		case 12:
		{
			dataBase.loadDbFromFile();
			break;
		}
		default:
		{
			std::cout << "Wrong input. Try again\n";
			break;
		}
		}
	}

	return 0;
}
