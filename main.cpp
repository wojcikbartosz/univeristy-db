#include <iostream>
#include "Student.hpp"
#include "maintain.hpp"
using namespace std;

int main() {
	std::vector<std::shared_ptr<Student>> v;
	addNewStudents(v);

	displayDB(v);

	searchBySurename(v);
	std::cout<<"end\n";


	return 0;
}
