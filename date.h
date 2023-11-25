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

	//generic method
	short isLeapMonth(){
		return month == 2 && isLeapYear();
	}

	short getLastDayOfMonth(){
		return lastDayOfMonth[month] + isLeapMonth();
	}

	void checkIfMonthHasDay(unsigned short day){
		if(day > getLastDayOfMonth()){
			throw std::out_of_range(Date::nameOfMonth[month] + " does not have " + std::to_string(day) + " days in " + std::to_string(year));
		}
	}

	// setters
	Date& setYear(unsigned int year){
		if(year >= 3000) throw std::out_of_range("The year cannot be greater than 3000"); 
		this->year = year;
		checkIfMonthHasDay(day);
		return *this;
	}

	Date& setMonth(unsigned short month){
		if(month < 1 || month > 12) throw std::out_of_range("Choose a month between 1 and 12");
		this->month = month;
		checkIfMonthHasDay(day);
		return *this;
	}

	Date& setDay(unsigned short day){
		if(day < 1) throw std::out_of_range("Day should be greater or equal to 1");
		checkIfMonthHasDay(day);
		this->day = day;
		return *this;
	}

	//empty constructor
	Date(){}

	// constructors
	Date(unsigned int year){
		setYear(year);
	}

	Date(unsigned short month, unsigned int year){
		setYear(year);
		setMonth(month);
	}

	Date(unsigned short day, unsigned short month, unsigned int year){
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

	// overloading -
	friend Date& operator-(Date& d1, Date& d2){
		Date* d = new Date();


		d->year = d1.year - d2.year;
		d->month = d1.month - d2.month;

		if(d->month < 0){
			d->year--;
			d->month += 12;
		}

		d->day = d1.day - d2.day;
		if(d->day < 0){
			d->month--;
			d->day += d->getLastDayOfMonth();
		}
		return *d;
	}

	// overloading +
	friend Date& operator+(Date& d1, Date& d2){
		Date* d = new Date();

		d->year = d1.year + d2.year;
		d->month = d1.month + d2.month;

		if(d->month > 12){
			d->year++;
			d->month -= 12;
		}

		d->day = d1.day + d2.day;
		if(d->day > d->getLastDayOfMonth()){
			d->month++;
			d->day -= d->getLastDayOfMonth();
			d->day++;
		}
		return *d;
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