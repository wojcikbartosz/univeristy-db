#include <iostream>
#include "DB.hpp"
using namespace std;

int main()
{
	DB dataBase;
	std::cout << "adding\n";
	dataBase.generateRandomData(10);

	dataBase.displayDB();

	std::cout << "--------------------- sorted by id------------------\n";

	dataBase.sortById();
	dataBase.displayDB();

	std::cout << "--------------------- sorted by surname------------------\n";

	dataBase.sortBySurname();
	dataBase.displayDB();

	std::cout << "--------------------- sorted by salary------------------\n";

	dataBase.sortBySalary();
	dataBase.displayDB();

	std::cout << "--------------------- search by id------------------\n";

	dataBase.searchById();

	std::cout << "--------------------- search by surname------------------\n";

	dataBase.searchBySurname();

	std::cout << "--------------------- changing salary------------------\n";

	dataBase.changeSalaryById();
	dataBase.displayDB();

	std::cout << "--------------------- deleting by index------------------\n";

	dataBase.deleteByIndexNumber();
	dataBase.displayDB();

	return 0;
}
