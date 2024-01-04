#include <fstream>
#include <iostream>
#include <string>
#include "date.h"
#include "menu.h"

int main(){
	Menu *menu = new Menu();

	do{
		menu->print();
	}while(menu->hasOption());

	return 0;
}