#include <ostream>
#include <istream>
#include <iostream>
#include <string>

class Date{

private:
	unsigned short day = 0;
	unsigned short month = 0;
	unsigned int year = 0;

	static short lastDayOfMonth[13];
	static std::string nameOfMonth[13];

public:

	//getters
	unsigned short getDay(){
		return day;
	}

	unsigned short getMonth(){
		return month;
	}

	unsigned int getYear(){
		return year;
	}

	short isLeapYear(){
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}

	short isLeapMonth(){
		return month == 2 && isLeapYear();
	}

	short getLastDayOfMonth(){
		return lastDayOfMonth[month] + isLeapMonth();
	}

	// setters
	Date& setYear(unsigned int year){
		if(year >= 3000) throw std::out_of_range("The year cannot be greater than 3000"); 
		this->year = year;
		return *this;
	}

	Date& setMonth(unsigned short month){
		if(month < 1 || month > 12) throw std::out_of_range("Choose a month between 1 and 12");
		this->month = month;
		return *this;
	}

	Date& setDay(unsigned short day){
		if(day < 1) throw std::out_of_range("Day should be greater or equal to 1");
		if(day > getLastDayOfMonth()) throw std::out_of_range(Date::nameOfMonth[month] + " does not have " + std::to_string(day) + " days");
		this->day = day;
		return *this;
	}

	//empty constructor
	Date(){}

	// constructors
	Date(unsigned int year){
		setYear(year);
	}

	Date(unsigned int year, unsigned short month){
		setYear(year);
		setMonth(month);
	}

	Date(unsigned int year, unsigned short month, unsigned short day){
		setYear(year);
		setMonth(month);
		setDay(day);
	}

	// overloading <<
	friend std::ostream& operator<<(std::ostream& out, Date& d){
		if(d.day) out << std::to_string(d.day);
		if(d.day && d.month) out << " ";
		if(d.month) out << Date::nameOfMonth[d.month];
		if(d.month && d.year) out << " ";
		if(d.year) out << std::to_string(d.year);

		if(!d.day && !d.month && !d.year) out << "unknown date";

		return out;
	}

	//overloading >>
	friend std::istream& operator>>(std::istream& in, Date& d){
		unsigned int year;
		unsigned short month, day;

		in >> day;	d.setDay(day);
		in >> month; d.setMonth(month);
		in >> year; d.setYear(year);

		return in;
	}

};

short Date::lastDayOfMonth[13] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
std::string Date::nameOfMonth[13] = {
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};