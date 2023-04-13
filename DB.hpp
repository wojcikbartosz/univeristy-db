#ifndef DB_HPP
#define DB_HPP

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

class DB
{
    private:
    std::vector<std::shared_ptr<Person>> Persons;

    public:
    void displayDB();
    void addNewPerson(bool);
    void searchBySurname();
    void searchById();
    void sortById();
    void sortBySurname();
    void deleteByIndexNumber();
    void changeSalaryById();
    void sortBySalary();

    private:
    void swapEmployeesToTheBeginning();
};

#endif