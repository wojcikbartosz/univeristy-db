#ifndef MAINTAIN_HPP_
#define MAINTAIN_HPP_
#include <vector>
#include "Student.hpp"
#include <iostream>
#include <string>
#include <memory>

void displayDB(std::vector<std::shared_ptr<Student>>&);
void addNewStudents(std::vector<std::shared_ptr<Student>>&);
void searchBySurename(std::vector<std::shared_ptr<Student>>&);


#endif /* STUDENT_HPP_ */