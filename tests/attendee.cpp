#include "..\attendee.h"

int main(){
	Attendee* at1 = new Attendee("Vasile", "Ion", "Popescu", new Date(15, 7, 1980));
	at1->print();
	return 0;
}