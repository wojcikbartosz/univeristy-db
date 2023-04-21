#ifndef DB_HPP
#define DB_HPP

#include <vector>
#include "Person.hpp"
#include <memory>
#include "Student.hpp"
#include "Employee.hpp"
#include "IHasIndexNumber.hpp"
#include "IHasSalary.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
#include <fstream> 


class DB
{
    private:
    std::vector<std::shared_ptr<Person>> Persons;

    public:
    void displayDB();
    void addNewPerson();
    void searchBySurname();
    void searchById();
    void sortById();
    void sortBySurname();
    void deleteByIndexNumber();
    void changeSalaryById();
    void sortBySalary();
    void generateRandomData();
    void saveDbToFile();
    void loadDbFromFile();

    private:
    void swapEmployeesToTheBeginning();
    bool checkIdCorrectness(std::string const &);
};

#endif