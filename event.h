#include <fstream>
#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include "area.h"
#include "occupancyTable.h"
#include "venue.h"
#include "date.h"

class Event{

private:
	std::string name;
	int id;
	Date date;
	Venue* venue;
	unsigned short noOfAreas;
	OccupancyTable* areas = nullptr;

public:

	// getters
	std::string getName(){
		return name;
	}

	int getId(){
		return id;
	}

	Date getDate(){
		return date;
	}

	Venue* getVenue(){
		return venue;
	}

	unsigned short getNoOfAreas(){
		return noOfAreas;
	}

	OccupancyTable& getArea(unsigned short i){
		if(i >= noOfAreas) throw std::length_error("Area " + std::to_string(i) + " does not exist");
		return areas[i];
	}

	// setters
	Event& setDate(Date& date){
		this->date = date;
		return *this;
	}

	Event& setName(std::string& name){
		this->name = name;
		return *this;
	}

	Event& setNoOfAreas(unsigned short n){
		noOfAreas = n;
		if(areas) delete[] areas;
		areas = new OccupancyTable[noOfAreas];
		return *this;
	}

	Event& setVenue(Venue& venue){
		this->venue = &venue;
		setNoOfAreas(venue.getNoOfAreas());
		for(int i = 0; i < noOfAreas; i++){
			OccupancyTable t(venue.getArea(i));
			areas[i] = t;
		}
		return *this;
	}

	// overload >> for file
	friend std::ifstream& operator>>(std::ifstream& fin, Event& event){
		std::getline(fin, event.name);
		fin >> event.date;
		std::cout << event.name << std::endl;
		std::cout << event.date << std::endl;
		int venueId;
		fin >> venueId;
		std::cout << venueId << std::endl;

		int n;
		fin >> n; 
		std::cout << n << std::endl;
		event.setNoOfAreas(n);
		std::cout << event.noOfAreas << std::endl;

		for(int i = 0; i < event.noOfAreas; i++){
			fin >> event.areas[i];
			std::cout << event.areas[i] << std::endl;
		}

		return fin;
	}

	// overload <<
	friend std::ostream& operator<<(std::ostream& out, Event& event){
		out << event.name << std::endl;
		out << event.date << std::endl;
		out << event.noOfAreas << std::endl;

		for(int i = 0; i < event.noOfAreas; i++){
			out << event.areas[i];
		}
		return out;
	}
};