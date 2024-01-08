#include <fstream>
#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include "area.h"
#include "occupancyTable.h"
#include "venue.h"
#include "date.h"
#include "attendee.h"
#include "ticket.h"

class Event{

private:
	std::string name;
	int id;
	Date date;
	Venue* venue;
	unsigned short noOfAreas = 0;
	OccupancyTable* areas = nullptr;
	unsigned short noOfTickets = 0;
	Ticket* tickets = nullptr;

	unsigned int min(unsigned int a, unsigned int b){
		return (a < b) ? a : b;
	}

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

	unsigned short getNoOfTickets(){
		return noOfTickets;
	}

	Ticket& getTicket(unsigned short i){
		if(i >= noOfTickets) throw std::length_error("Ticket " + std::to_string(i) + " does not exist");
		return tickets[i];
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

	Event& setNoOfTickets(unsigned short newSize){
		Ticket* temp = new Ticket[newSize];
		int n = min(noOfTickets, newSize);
		for(int i = 0; i < n; i++){
			temp[i] = tickets[i];
		}
		if(tickets) delete[] tickets;
		tickets = temp;
		noOfTickets = newSize;

		return *this;
	}

	// overload >> for file
	friend std::ifstream& operator>>(std::ifstream& fin, Event& event){
		std::getline(fin, event.name);
		fin >> event.date;
		// std::cout << event.name << std::endl;
		// std::cout << event.date << std::endl;
		int venueId;
		fin >> venueId;
		// std::cout << venueId << std::endl;

		int n;
		fin >> n; 
		// std::cout << n << std::endl;
		event.setNoOfAreas(n);
		// std::cout << event.noOfAreas << std::endl;

		for(int i = 0; i < event.noOfAreas; i++){
			fin >> event.areas[i];
			// std::cout << event.areas[i] << std::endl;
		}

		return fin;
	}

	// overload <<
	friend std::ostream& operator<<(std::ostream& out, Event& event){
		out << event.name << std::endl;
		out << event.date << std::endl;

		return out;
	}

	// overload << for file
	friend std::ofstream& operator<<(std::ofstream& fout, Event& event){
		fout << event.name << std::endl;
		fout << event.date << std::endl;
		fout << 1 << std::endl;

		fout << event.noOfAreas << std::endl;
		for(int i = 0; i < event.noOfAreas; i++){	
			fout << event.areas[i];
		}

		fout << event.noOfTickets << std::endl;
		for(int i = 0; i < event.noOfTickets; i++){
			fout << event.tickets[i] << std::endl;
		}

		return fout;
	}

	Ticket* createTicket(unsigned short areaIndex, char row, int seatNumber){
		OccupancyTable &area = getArea(areaIndex);
		if(area.occupy(row, seatNumber)){
			setNoOfTickets(noOfTickets+1);
			Ticket t;
			t.generateNewID();
			t.setAreaName(area.getName());
			t.setRow(row);
			t.setSeat(seatNumber);
			tickets[noOfTickets-1] = t;
			return &tickets[noOfTickets-1];
		}
		return nullptr;
	}
};