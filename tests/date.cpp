#include <iostream>
#include "../date.h"

int main(){
	Date currentDate;
	Date birthDate(2004, 3, 23);
	Date futureDate(1, 1, 6);

	std::cout << currentDate << std::endl;
	std::cout << birthDate << std::endl;
	std::cout << birthDate.getYear() << std::endl;
	std::cout << "enter current date: "; std::cin >> currentDate;
	std::cout << currentDate << std::endl;

	std::cout << (currentDate - birthDate).getYear() << std::endl;

	std::cout << (currentDate + futureDate) << std::endl;

	return 0;
}