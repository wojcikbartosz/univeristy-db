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
	Student()
	{}
	void displayStudent()const;

	void SwapData(Student&);





	std::string getSurname() const;
	std::string getPesel() const;
	std::string getName() const;
	std::string getaddress() const;
	std::string getIndexNumber() const;
	bool getSex() const;
	void setName(std::string);
	void setSurname(std::string);
	void setAddress(std::string);
	void setIndexNumber(std::string);
	void setPesel(std::string);
	void setSex(bool);
};

#endif /* STUDENT_HPP_ */
