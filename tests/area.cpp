#include "../area.h"

int main(){
	Area a1, a2;

	a1.getName();
	a1.setName("VIP");

	a1.addRow('A', 1, 20).addRow('B', 5, 17);
	a2 = a1;
	std::cout << a1 << a2;

	std::cout << "there are " << Area::getNoOfAreas() << " areas in total" << std::endl;

	// a1['B'];

	return 0;
}