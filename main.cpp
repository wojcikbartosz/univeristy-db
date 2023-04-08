#include <iostream>
#include "Student.hpp"
#include "maintain.hpp"
using namespace std;

int main()
{
	std::vector<std::shared_ptr<Student>> v;
	addNewStudents(v);
	addNewStudents(v);
	addNewStudents(v);

	displayDB(v);

	deleteByIndexNumber(v);

	displayDB(v);
	/*sortBySurname(v);
	std::cout << "sorted\n";
	displayDB(v);*/

	return 0;
}
