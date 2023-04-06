#ifndef STUDENT_HPP_
#define STUDENT_HPP_
#include <string>

class Student
{
private:
	std::string name_;
	std::string surname_;
	std::string address_;
	std::string indexNumber_;
	std::string pesel_;
	bool sex_;

public:
	Student(std::string name, std::string surname, std::string address, std::string indexNumber, std::string pesel, bool sex);

	void displayStudent();

	std::string getSurname() const;
	std::string getPesel() const;
	void setPesel(std::string);
};

#endif /* STUDENT_HPP_ */
