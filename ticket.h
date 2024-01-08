#include <fstream>
#include <iostream>
#include <ostream>
#include <istream>
#include <string>

class Ticket{

private:
	unsigned long ID;
	// Event* event;
	Attendee attendee;
	std::string areaName;
	char row;
	int seat;

public:
	// getters
	unsigned long getID(){
		return ID;
	}

	// Event& getEvent(){
	// 	return *event;
	// }

	Attendee& getAttendee(){
		return attendee;
	}

	std::string getAreaName(){
		return areaName;
	}

	char getRow(){
		return row;
	}

	int getSeat(){
		return seat;
	}

	// setters
	Ticket& generateNewID(){
		ID = 1234;
		return *this;
	}

	// Ticket& setEvent(Event& event){
	// 	this->event = &event;
	// 	return *this;
	// }

	Ticket& setAttendee(Attendee attendee){
		this->attendee = attendee;
		return *this;
	}

	Ticket& setAreaName(std::string areaName){
		this->areaName = areaName;
		return *this;
	}

	Ticket& setRow(char row){
		this->row = row;
		return *this;
	}

	Ticket& setSeat(int seat){
		this->seat = seat;
		return *this;
	}

	// default constructor
	Ticket(){}

	// copy constructor
	Ticket(Ticket& other){
		this->ID = other.ID;
		this->attendee = other.attendee;
		this->areaName = other.areaName;
		this->row = other.row;
		this->seat = other.seat;
	}

	// overloading <<
	friend std::ostream& operator<<(std::ostream& out, Ticket& ticket){
		out << "ticket " << ticket.ID << " for ";
		// out << ticket.event;
		out << " [" << ticket.areaName << " ";
		out << ticket.row << "-" << ticket.seat << "] " << ticket.attendee << std::endl;

		return out;
	}

	// overloading << for files
	friend std::ofstream& operator<<(std::ofstream& fout, Ticket& ticket){
		fout << ticket.ID << " ";
		fout << ticket.row << " " << ticket.seat << " ";
		fout << ticket.areaName << std::endl;

		return fout;
	}



};