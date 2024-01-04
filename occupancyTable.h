#include <fstream>
#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include "area.h"

class OccupancyTable{

private:

	std::string name;
	int noOfRows = 0;
	char firstRow = 'A';
	int noOfColumns = 0;
	int firstColumn = 0;
	int** seats = nullptr;

public:

	// getters
	std::string getName(){
		return name;
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

	// setters
	OccupancyTable& setName(std::string name){
		this->name = name;
		return *this;
	}

	OccupancyTable& setSize(int h, int w){
		if(seats != nullptr) throw std::exception();
		seats = new int*[h];
		for(int i = 0; i < h; i++){
			seats[i] = new int[w];
			for(int j = 0; j < w; j++){
				seats[i][j] = 0; // sets each seat as empty
			}
		}
		noOfRows = h;
		noOfColumns = w;
		return *this;
	}

	OccupancyTable& setFirstRow(char firstRow){
		this->firstRow = firstRow;
		return *this;
	}

	OccupancyTable& setFirstColumn(int firstColumn){
		this->firstColumn = firstColumn;
		return *this;
	}

	bool occupy(char rowLetter, int seatNumber){
		int i = rowLetter - firstRow;
		int j = seatNumber - firstColumn;
		if(seats[i][j] == 0){
			seats[i][j] = 1;
			return true;
		}else{
			return false;
		}
	}

	bool isOccupied(char rowLetter, int seatNumber){
		int i = rowLetter - firstRow;
		int j = seatNumber - firstColumn;
		return seats[i][j];
	}

	void free(char rowLetter, int seatNumber){
		int i = rowLetter - firstRow;
		int j = seatNumber - firstColumn;
		seats[i][j] = 0;
	}

	OccupancyTable(){
		setSize(0, 0);
	}

	//copy constructor
	OccupancyTable(OccupancyTable& table){
		setSize(table.getNoOfRows(), table.getNoOfColumns());
		setFirstRow(table.getFirstRow());
		setFirstColumn(table.getFirstColumn());
		setName(table.getName());
	}

	OccupancyTable(Area& area){
		setSize(area.getNoOfRows(), area.getNoOfColumns());
		setFirstRow(area.getFirstRow());
		setFirstColumn(area.getFirstColumn());
		setName(area.getName());
	}

	// overloading <<
	friend std::ostream& operator<<(std::ostream& out, OccupancyTable& table){

		out << table.getName() << ": " << std::endl;

		std::string prefix = "\e[90;40m[", suffix = "]\e[0m";
		for(int i = 0; i < table.noOfRows; i++){
			for(int j = 0; j < table.noOfColumns; j++){
				if(table.seats[i][j] == 0){ // the seat is empty
					out << "[" << (char)(table.firstRow + i) << "-";
					out << (table.firstColumn + j) << "]" << "\t";
				}else{
					out << prefix << (char)(table.firstRow + i) << "-";
					out << (table.firstColumn + j) << suffix << "\t";
				}
			}
			out << std::endl;
		}
		return out;
	}

	// overloading << for files
	friend std::ofstream& operator<<(std::ofstream& fout, OccupancyTable& table){
		fout << table.noOfRows << " ";
		fout << table.noOfColumns << " ";
		fout << table.firstRow << " ";
		fout << table.firstColumn << " ";
		fout << table.name << std::endl;

		for(int i = 0; i < table.noOfRows; i++){
			for(int j = 0; j < table.noOfColumns; j++){
				fout << table.seats[i][j] << " ";
			}
			fout << std::endl;
		}
		return fout;
	}

	// overloading >> for files
	friend std::ifstream& operator>>(std::ifstream& fin, OccupancyTable& table){
		int noOfRows, noOfColumns;
		fin >> noOfRows;
		fin >> noOfColumns;

		table.setSize(noOfRows, noOfColumns);

		fin >> table.firstRow;
		fin >> table.firstColumn;
		std::getline(fin, table.name);

		for(int i = 0; i < table.noOfRows; i++){
			for(int j = 0; j < table.noOfColumns; j++){
				fin >> table.seats[i][j];
			}
		}

		return fin;
	}


};