#include <iostream>
#include "DB.hpp"
using namespace std;

int main()
{
	DB dataBase;
	std::cout<<"adding\n";
	dataBase.generateRandomData(6);
	std::cout<<"----------------------\n";
	dataBase.displayDB();



	

	return 0;
}
