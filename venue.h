#include <fstream>
#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include "area.h"

class Venue{

private:

	std::string name;
	std::string address;
	int noOfAreas = 0;
	Area* areas = nullptr;

public:

	// getters
	std::string getName(){
		return name;
	}

	std::string getAddress(){
		return address;
	}

	int getNoOfAreas(){
		return noOfAreas;
	}

	Area getArea(int i){
		if(i < 0 || i >= noOfAreas) throw std::length_error("Area " + std::to_string(i) + " does not exist");	
		return areas[i];
	}

	// setters
	void setName(std::string name){
		this->name = name;
	}

	void setAddress(std::string address){
		this->address = address;
	}

	void setNoOfAreas(int newSize){
		// Area* temp = (Area*) malloc(newSize * sizeof (Area));
		Area* temp = new Area[newSize];
		// Area temp[newSize];

		int overlap = (newSize < noOfAreas ? newSize : noOfAreas);

		for(int i = 0; i < overlap; i++){
			temp[i] = areas[i];
		}
		
		delete[] areas;
		areas = temp;
		noOfAreas = newSize;
	}

	void setArea(int i, Area area){
		areas[i] = area;
	}

	// default constructor
	Venue(){}

	// constructors
	Venue(int noOfAreas){
		setNoOfAreas(noOfAreas);
	}

	Venue(std::string name){
		setName(name);
	}

	Venue(std::string name, int noOfAreas){
		setName(name);
		setNoOfAreas(noOfAreas);
	}

	// destructors
	~Venue(){
		delete[] areas;
	}

	// overloading >>
	friend std::ifstream& operator>>(std::ifstream& fin, Venue& v){
		std::getline(fin, v.name);
		std::getline(fin, v.address);

		int n;
		fin >> n; 
		v.setNoOfAreas(n);

		for(int i = 0; i < v.noOfAreas; i++){
			fin >> v.areas[i];
		}

		return fin;
	}	

	// overloading <<
	friend std::ostream& operator<<(std::ostream& out, Venue& v){
		out << "name: " << v.name << std::endl;
		out << "address: " << v.address << std::endl;
		out << "number of areas: " << v.noOfAreas << std::endl;
		out << "Areas: " << std::endl;
		for(int i = 0; i < v.noOfAreas; i++){
			out << v.areas[i];
		}

		return out;
	}


};