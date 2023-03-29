#include <iostream>
#include "Student.hpp"
using namespace std;

int main() {
	Student student = Student("Bartosz", "Wójcik", "40-749 Katowice Ul. Bielska 30/3", "253505", "98121506798", true);
	student.displayStudent();
	return 0;
}