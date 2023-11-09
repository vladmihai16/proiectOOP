#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <ctime>

enum class EventType{Movie, Sports, Concert}
enum class TicketType{Child, Student, Adult, Elder}
enum class Discounts{Adult = 0, Child = 50, Student = 40, Elder = 30}

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
	static const int MIN_NAME_LENGTH = 2;
	static const int MIN_CITY_LENGTH = 2;
	static const int MIN_VENUE_LENGTH = 2;
	static const int MIN_ROWS = 1;
	static const int MIN_COLUMNS = 1;
	static const int MAX_DATE_SIZE = 10;

public: 
	void set EventType{EventType type}{
		this->type = type;
	}


}