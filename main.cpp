#include <iostream>
#include "Person.hpp"
#include "maintain.hpp"
using namespace std;

int main()
{
	std::vector<Person*> v;
	addNewStudent(v);
	addNewStudent(v);
	addNewStudent(v);

	displayDB(v);

	//deleteByIndexNumber(v);

	//displayDB(v);
	sortBySurname(v);
	std::cout << "sorted\n";
	displayDB(v);
	freeSpace(v);

	return 0;
}
