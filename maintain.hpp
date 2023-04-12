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



void displayDB(std::vector<std::shared_ptr<Person>> &);
void addNewStudent(std::vector<std::shared_ptr<Person>> &);
void addNewEmployee(std::vector<std::shared_ptr<Person>> &);
void searchBySurname(std::vector<std::shared_ptr<Person>> &);
void searchByPesel(std::vector<std::shared_ptr<Person>> &);
void sortByPesel(std::vector<std::shared_ptr<Person>> &);
void sortBySurname(std::vector<std::shared_ptr<Person>> &);
void deleteByIndexNumber(std::vector<std::shared_ptr<Person>> &);

#endif /* STUDENT_HPP_ */
