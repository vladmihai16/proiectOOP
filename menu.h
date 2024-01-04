#include <iostream>

class Menu{

private:

	int option;

public:
	void print(){
		std::cout << "1. First entry" << std::endl; 
		std::cout << "2. Second entry" << std::endl; 
		std::cout << "0. Exit" << std::endl; 
	}

	int hasOption(){
		std::cin >> option;

		return option;
	}
};

