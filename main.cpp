#include <iostream>
#include "Person.hpp"
#include "maintain.hpp"
using namespace std;

int main()
{
	std::vector<std::shared_ptr<Person>> v;
	//addNewStudent(v);
	addNewEmployee(v);
	//addNewStudent(v);
	//addNewEmployee(v);
	//addNewEmployee(v);
	

	displayDB(v);

	//deleteByIndexNumber(v);
	//changeSalaryById(v);
	sortBySalary(v);
	std::cout<<"-----------------------------\n";
	displayDB(v);
	/*sortBySurname(v);
	std::cout << "sorted\n";
	displayDB(v);*/

	return 0;
}
