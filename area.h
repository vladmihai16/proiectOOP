#include <fstream>
#include <iostream>
#include <ostream>
#include <istream>
#include <string>

class Area{

private:

	std::string name;
	int noOfRows = 0;
	char firstRow = 'A';
	int noOfColumns = 0;
	int firstColumn = 0;

public:

	//getters
	std::string getName(){
		return name + " area";
	}

	int getNoOfRows(){
		return noOfRows;
	}

	int getNoOfColumns(){
		return noOfColumns;
	}

	char getFirstRow(){
		return firstRow;
	}

	int getFirstColumn(){
		return firstColumn;
	}

	//setters
	Area& setName(std::string name){
		this->name = name;
		return *this;
	}

	Area& setNoOfRows(int noOfRows){
		this->noOfRows = noOfRows;
		return *this;
	}

	Area& setNoOfColumns(int noOfColumns){
		this->noOfColumns = noOfColumns;
		return *this;
	}

	Area& setFirstRow(const char firstRow){
		this->firstRow = firstRow;
		return *this;
	}

	Area& setFirstColumn(int firstColumn){
		this->firstColumn = firstColumn;
		return *this;
	}

	// overload << for CLI
	friend std::ostream& operator<<(std::ostream& out, Area& a){

		out << a.getName() << ": " << std::endl;

		for(int rowNumber = 0; rowNumber < a.noOfRows; rowNumber++){
			for(int seatNumber = 0; seatNumber < a.noOfColumns; seatNumber++){
				out << "[";
				out << (char) (a.firstRow + rowNumber) << "-";
				out << (a.firstColumn + seatNumber);
				out << "]\t";
			}
			out << std::endl;
		}

		return out;
	}

	// overload << for file
	friend std::ofstream& operator<<(std::ofstream& out, Area& a){

		out << a.noOfRows  << " ";
		out << a.noOfColumns  << " ";
		out << a.firstRow  << " ";
		out << a.firstColumn  << " ";
		out << a.name << std::endl;

		return out;
	}

	friend std::istream& operator>>(std::istream& in, Area& a){
		
		in >> a.noOfRows;
		in >> a.noOfColumns;
		in >> a.firstRow;
		in >> a.firstColumn;
		in >> a.name;
	
		return in;
	}

	// default constructor
	Area(){}

	// copy constructor
	Area(Area& other){
		this->name = other.name;
		this->noOfRows = other.noOfRows;
		this->noOfColumns = other.noOfColumns;	
		this->firstRow = other.firstRow;
		this->firstColumn = other.firstColumn;
	}
};