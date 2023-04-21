#include <iostream>
#include "DB.hpp"
using namespace std;

int main()
{
	DB dataBase;
	std::cout << "adding\n";
	dataBase.generateRandomData(10);

	dataBase.saveDbToFile();

	return 0;
}
