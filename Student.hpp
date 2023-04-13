#ifndef STUDENT_HPP_
#define STUDENT_HPP_
#include <string>
#include "Person.hpp"
#include "IHasIndexNumber.hpp"
class Student : public Person, public IHasIndexNumber
{

public:
	Student(std::string name, std::string surname, std::string address, std::string indexNumber, std::string Id, bool sex);
	Student() {}
	~Student() override {}

	std::string getIndexNumber() const override;

	void setIndexNumber(std::string indexNumber)override;

	void displayData() const override;
};

#endif /* STUDENT_HPP_ */
