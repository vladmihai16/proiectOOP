#include <fstream>
#include <iostream>
#include <ostream>
#include <istream>
#include <string>

class Area{

private:

	std::string name;
	char* rows;
	short* firstSeats;
	short* lastSeats;
	short noOfRows = 0;

public:

	//getter
	std::string getName(){
		return name;
	}

	//setter
	Area& setName(std::string name){
		this->name = name;
		return *this;
	}

	Area& addRow(char row, short firstSeat, short lastSeat){
		//makes space for one extra row by copying the arrays over
		char* rowsCopy = (char*) malloc(sizeof (char) * (noOfRows + 1));
		short* firstSeatsCopy = (short*) malloc(sizeof (short) * (noOfRows + 1));
		short* lastSeatsCopy = (short*) malloc(sizeof (short) * (noOfRows + 1));

		for(int i = 0; i < noOfRows; i++){
			rowsCopy[i] = rows[i];
			firstSeatsCopy[i] = firstSeats[i];
			lastSeatsCopy[i] = lastSeats[i];
		}

		// adds the values of the new rows
		rowsCopy[noOfRows] = row;
		firstSeatsCopy[noOfRows] = firstSeat;
		lastSeatsCopy[noOfRows] = lastSeat;

		// replaces the original arrays with the new ones
		rows = rowsCopy;
		firstSeats = firstSeatsCopy;
		lastSeats = lastSeatsCopy;

		// increments the sizes of the new arrays
		noOfRows++;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Area& a){

		for(int i = 0; i < a.noOfRows; i++){
			out << a.rows[i] << " " << a.firstSeats[i] << " " << a.lastSeats[i] << std::endl;
		}

		return out;
	}

	
};