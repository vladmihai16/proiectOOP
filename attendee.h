#include <fstream>
#include <iostream>
#include <ostream>
#include <istream>
#include <string>
// #include "date.h"

class Attendee{

private:
	std::string firstName;
	std::string middleName;
	std::string lastName;
	Date dateOfBirth;

public:

	// getters
	std::string getFirstName(){
		return firstName;
	}

	std::string getMiddleName(){
		return middleName;
	}

	std::string getLastName(){
		return lastName;
	}
	
	Date getDateOfBirth(){
		return dateOfBirth;
	}

	short getAge(){
		return (Date::currentDate - dateOfBirth).getYear();
	}

	std::string getFullName(){
		return firstName + "-" + middleName + " " + lastName; 
	}

	//setters
	Attendee& setFirstName(std::string firstName){
		this->firstName = firstName;
		return *this;
	}

	Attendee& setMiddleName(std::string middleName){
		this->middleName = middleName;
		return *this;
	}

	Attendee& setLastName(std::string lastName){
		this->lastName = lastName;
		return *this;
	}

	Attendee& setDateOfBirth(Date& dateOfBirth){
		this->dateOfBirth = dateOfBirth;
		return *this;
	}

	Attendee& setDateOfBirth(Date* dateOfBirth){
		setDateOfBirth(*dateOfBirth);
		return *this;
	}

	// constructors

	Attendee(){}

	Attendee(std::string fName,
		     std::string mName,
		     std::string lName)
		   : firstName(fName), middleName(mName), lastName(lName) {}

	Attendee(std::string firstName,
		     std::string middleName,
		     std::string lastName,
		     Date& dateOfBirth){

		setFirstName(firstName);
		setMiddleName(middleName);
		setLastName(lastName);
		setDateOfBirth(dateOfBirth);
	}

	// overloading <<
	friend std::ostream& operator<<(std::ostream& out, Attendee& at){
		out << at.firstName << "-";
		out << at.middleName << "\t"; 
		out << at.lastName << "\t"; 
		out << "(" << at.dateOfBirth  << ")" << std::endl;

		return out;
	}

	// overloading << for files
	friend std::ofstream& operator<<(std::ofstream& fout, Attendee& at){
		fout << at.firstName << " ";
		fout << at.middleName << " "; 
		fout << at.lastName << " "; 
		fout << at.dateOfBirth;

		return fout;
	}

	// overloading >>
	friend std::istream& operator>>(std::istream& in, Attendee& at){
		std::cout << "Attendee" << std::endl; 
		std::cout << "first name: "; in >> at.firstName;
		std::cout << "middle name: "; in >> at.middleName;
		std::cout << "last name: "; in >> at.lastName;
		std::cout << "date of birth: "; in >> at.dateOfBirth;
		return in;
	}

	// overloading >> for files
	friend std::ifstream& operator>>(std::ifstream& fin, Attendee& at){
		fin >> at.firstName >> at.middleName >> at.lastName >> at.dateOfBirth;
		return fin;
	}
	
	//overloading <
	friend bool operator<(Attendee& at, int age){
		return at.getAge() < age;
	}

	//overloading >=
	friend bool operator>=(Attendee& at, int age){
		return at.getAge() >= age;
	}
};