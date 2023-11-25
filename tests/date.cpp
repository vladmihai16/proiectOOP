#include <iostream>
#include "../date.h"

int main(){
	Date date1;
	Date date2(2000, 2, 29);

	std::cout << date2 << date1 << std::endl;
	std::cout << date2.getYear();
	return 0;
}