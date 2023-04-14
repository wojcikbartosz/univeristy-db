#ifndef DB_HPP
#define DB_HPP

#include <vector>
#include "Person.hpp"
#include <memory>


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
    void generateRandomData(int);

    private:
    void swapEmployeesToTheBeginning();
    bool checkIdCorrectness(std::string const &);
};

#endif