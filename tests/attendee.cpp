#include "..\attendee.h"

int main(){
	Attendee at1("Vasile", "Ion", "Popescu");

	at1.setFirstName("Mihai");
	at1.setDateOfBirth(new Date(15, 7, 1980));
	std::cout << at1 << std::endl;

	Attendee at2;
	std::cout << "new attendee [firstName middleName lastName day month year (of birth)]: ";
	std::cin >> at2;

	std::cout << at2 << std::endl;
	std::cout << at2.getAge() << std::endl;

	if(at2 < 18) std::cout << at2.getFullName() << " is a child" << std::endl;
	if(at2 >= 65) std::cout << at2.getFullName() << " is a senior/retiree" << std::endl;

	return 0;
}