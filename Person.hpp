#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
class Person
{
protected:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string pesel_;
    bool sex_;

public:
    Person(std::string name, std::string surname, std::string address, std::string pesel, bool sex);
    Person() {}
    virtual ~Person() {}

    virtual void displayData()const = 0;

    std::string getSurname() const;
    std::string getPesel() const;
    std::string getName() const;
    std::string getAddress() const;
    bool getSex() const;

    void setName(std::string);
    void setSurname(std::string);
    void setAddress(std::string);
    void setPesel(std::string);
    void setSex(bool);
};

#endif