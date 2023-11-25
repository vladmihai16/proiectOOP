#include <iostream>
#include "../date.h"

int main(){
	Date& currentDate = Date::currentDate;
	Date birthDate(23, 3, 2004);
	Date futureDate(6, 1, 1);

	std::cout << currentDate << std::endl;
	std::cout << birthDate << std::endl;
	std::cout << birthDate.getYear() << std::endl;
	// std::cout << "enter current date: "; std::cin >> currentDate;
	std::cout << currentDate << std::endl;

	std::cout << (currentDate - birthDate).getYear() << std::endl;

	std::cout << (currentDate + futureDate) << std::endl;

	return 0;
}