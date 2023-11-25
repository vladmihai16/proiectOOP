#include <fstream>
#include <iostream>
#include <ostream>
#include <istream>
#include <string>

class Area{

private:

	std::string name;
	short index;
	char* rows = nullptr;
	short* firstSeats = nullptr;
	short* lastSeats = nullptr;
	short noOfRows = 0;

	static short noOfAreas;

	void allocateRows(short n){
		// allocates new arrays of n size
		char* rowsCopy = (char*) malloc(sizeof (char) * n);
		short* firstSeatsCopy = (short*) malloc(sizeof (short) * n);
		short* lastSeatsCopy = (short*) malloc(sizeof (short) * n);

		// copy data over
		for(int i = 0; i < noOfRows; i++){
			rowsCopy[i] = rows[i];
			firstSeatsCopy[i] = firstSeats[i];
			lastSeatsCopy[i] = lastSeats[i];
		}

		// frees the original arrays
		free(rows); free(firstSeats); free(lastSeats);

		// replaces the original arrays with the new ones
		rows = rowsCopy;
		firstSeats = firstSeatsCopy;
		lastSeats = lastSeatsCopy;

		// updates noOfRows
		noOfRows = n;
	}

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

		allocateRows(noOfRows+1);
		// adds the values on the last positions
		rows[noOfRows-1] = row;
		firstSeats[noOfRows-1] = firstSeat;
		lastSeats[noOfRows-1] = lastSeat;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Area& a){

		out << "area number " << a.index << ": " << a.name << std::endl;

		for(int i = 0; i < a.noOfRows; i++){
			out << a.rows[i] << " ";
			for(int j = a.firstSeats[i]; j <= a.lastSeats[i]; j++){
				out << j << " ";
			}
			out << std::endl;
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Area& a){
		
		std::cout << "number of rows: "; in >> a.noOfRows;

		for(int i = 0; i < a.noOfRows; i++){
			std::cout << "enter row letter, first seat number and last seat number"; 
			in >> a.rows[i] >> a.firstSeats[i] >> a.lastSeats[i];
		}
		return in;
	}

	/*friend std::string operator[](Area& a, char row){

		std::string output 
		for(int i = 0; i < a.noOfRows && row != a.rows[i]; i++);
		if(i < a.noOfRows){
			output += std::to_string(a.rows[i]) + " ";
			for(int j = a.firstSeats[i]; j <= a.lastSeats[i]; j++){
				output += std::to_string(j) + " ";
			}
		}
		return output;
	}*/
	// std::string operator[](Area& a, char row) must be a non-static member function

	// default constructor
	Area(){
		index = ++noOfAreas;
	}

	// copy constructor
	Area(Area& a){
		index = ++noOfAreas;
		name = a.name;
		rows = a.rows;
		firstSeats = a.firstSeats;
		lastSeats = a.lastSeats;
		noOfRows = a.noOfRows;
		allocateRows(noOfRows);
	}

	static short getNoOfAreas(){
		return noOfAreas;
	}
};

short Area::noOfAreas = 0;