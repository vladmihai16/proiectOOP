#include <iostream>
#include "../date.h"

int main(){
	Date date1;
	Date date2(2000, 2, 29);

	std::cout << date1 << std::endl;
	std::cout << date2 << std::endl;
	std::cout << date2.getYear() << std::endl;
	std::cout << "enter the date: "; std::cin >> date1;
	std::cout << date1 << std::endl;

	return 0;
}