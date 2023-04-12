#ifndef MAINTAIN_HPP_
#define MAINTAIN_HPP_
#include <vector>
#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"
#include "IHasIndexNumber.hpp"
#include "IHasSalary.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>



void displayDB(std::vector<Person*> &);
void addNewStudent(std::vector<Person*> &);
void addNewEmployee(std::vector<Person*> &);
void searchBySurname(std::vector<Person*> &);
void searchByPesel(std::vector<Person*> &);
void sortByPesel(std::vector<Person*> &);
void sortBySurname(std::vector<Person*> &);
void deleteByIndexNumber(std::vector<Person*> &);
void freeSpace(std::vector<Person*> &);

#endif /* STUDENT_HPP_ */
