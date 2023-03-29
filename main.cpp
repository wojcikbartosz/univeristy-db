#include <iostream>
#include "Student.hpp"
#include "maintain.hpp"
using namespace std;

int main() {
	std::vector<std::shared_ptr<Student>> v;
	addNewStudents(v);
	addNewStudents(v);
	addNewStudents(v);

	displayDB(v);

	sortByPesel(v);
	std::cout<<"sorted\n";
	displayDB(v);

	return 0;
}
