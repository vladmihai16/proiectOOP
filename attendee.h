#include <fstream>
#include <iostream>
#include <string>
#include "date.h"

class Attendee{

private:
	std::string firstName;
	std::string middleName;
	std::string lastName;
	Date dateOfBirth;

public:
	Attendee(const std::string firstName,
		     const std::string middleName,
		     const std::string lastName,
		     Date dateOfBirth){

		this->firstName = firstName;
		this->middleName = middleName;
		this->lastName = lastName;
		this->dateOfBirth = dateOfBirth;
	}

	void print(){
		std::cout << firstName << "-" << middleName << " " << lastName << " ";
		std::cout << "(";
		dateOfBirth.print();
		std::cout << ")" << std::endl;
	}
};