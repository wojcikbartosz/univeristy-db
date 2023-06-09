#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
class Person
{
protected:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string Id_;
    std::string sex_;

public:
    Person(std::string name, std::string surname, std::string address, std::string Id, std::string sex);
    Person() {}
    virtual ~Person() {}

    virtual void displayData()const = 0;

    std::string getSurname() const;
    std::string getId() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getSex() const;

    void setName(std::string);
    void setSurname(std::string);
    void setAddress(std::string);
    void setId(std::string);
    void setSex(std::string);
};

#endif