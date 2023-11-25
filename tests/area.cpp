#include "../area.h"

int main(){
	Area a1;

	a1.getName();
	a1.setName("VIP");

	a1.addRow('A', 1, 20).addRow('B', 5, 17);
	std::cout << a1;


	return 0;
}