#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <ctime>

enum class EventType{Movie, Sports, Concert};
enum class TicketType{Child, Student, Adult, Elder};
enum class Discounts{Adult = 0, Child = 50, Student = 40, Elder = 30};

class Event{
private: //objects
	std::string name = "placeholder";
	std::string city = "placeholder";
	std::string venue = "placeholder";
	std::string date = "1/01/1970";
	std::string time = "00:00";
	char* seatType = nullptr;
	int lengthOfSeatType = 0;
	char* takenSeatsNormal = nullptr;
	char* takenSeatsVIP = nullptr;
	int noOfRows = 0;
	int noOfColumns = 0;
	int price = 0;

	//static attribnutes
	static const int MIN_AGE = 1;
	static const int MIN_CITY_LENGTH = 2;
	static const int MIN_NAME_LENGTH = 2;
	static const int MIN_VENUE_LENGTH = 2;
	static const int MIN_ROWS = 1;
	static const int MIN_COLUMNS = 1;
	static const int MAX_DATE_SIZE = 10;
	static const int MIN_PRICE = 1;

public: 
	void setEventType(EventType type){
		this->type = type;
	}

	void setCity(std::string newCity){
		if(newCity.size() < Event::MIN_CITY_LENGTH) {
			throw std::exception("City name is too short!");
		}
		this->city = newCity;
	}

	void setName(std::string newName){
		if(newName.size() < Event::MIN_NAME_LENGTH) {
			throw std::exception("Name is too short!");
		}
		this->name = newName;
	}

	void setDate(std::string newDate){
		if(newDate.size() != Event::DATE_SIZE) {
			throw std::exception("Date format is not valid!");
		}
	}

	void setNoOfRows(int newNumber){
		if(newNumber >= MIN_ROWS){
			this->noOfRows = newNumber;
		}
		else{
			throw std::exception("Number of rows is too small!");
		}
	}

	void setNoOfColumns(int newNumber){
		if(newNumber >= MIN_COLUMNS){
			this->noOfColumns = newNumber;
		}
		else{
			throw std::exception("not valid Number of Columns at the Venue!");
		}	
	}

	void settakenSeatsNormal(int newSeat){
		if(newSeat > this->noOfColumns * this->noOfRows || newSeat <= 0 || this-> takenSeatsNormal[newSeat] == 'O') {
			throw std::exception("Seat number is not valid!");
		}
		this->takenSeatsNormal[newSeat] = 'O';
	}
	void settakenSeatsVIP(int newSeat)\{
		if(newSeat > this->noOfColumns * this->noOfRows || newSeat <= 0 || this->takenSeatsVIP[newSeat] == 'O') {
			throw std::exception("Seat number is not valid!");
		}
		this->takenSeatsVIP[newSeat] = 'O';
	}

	void setPrice(int newPrice){
		if(newPrice < MIN_PRICE){
			throw std::exception("Price is too small");
		}
		this->price = newPrice;
	}

	//getters

};

int main(){
	return 0;
}
