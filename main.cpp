#include <iostream>
#include "DB.hpp"
using namespace std;

int main()
{
	DB dataBase;
	std::cout<<"adding\n";
	dataBase.addNewPerson(false);
	dataBase.addNewPerson(true);
	std::cout<<"----------------------\n";
	dataBase.displayDB();



	

	return 0;
}
