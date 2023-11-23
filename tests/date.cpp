#include <iostream>
#include "../date.h"

int main(){
	Date* da = new Date(13, 14, 2000);

	std::cout << "data: " << *da << std::endl;
	return 0;
}