#include "../occupancyTable.h"
#include "../area.h"
using namespace std;

int main(){
	OccupancyTable table;

	ifstream fin("occupancy.txt");
	// table.setSize(3, 7);
	// table.setFirstRow('U');
	// table.setFirstColumn(20);
	fin >> table;


	cout << table;

	char row;
	unsigned int seatNumber;
	cout << "row: "; cin >> row;
	cout << "seatNumber: "; cin >> seatNumber;
	// table[row][seatNumber] = 1;
	if(table.occupy(row, seatNumber)){
		cout << "ok" << endl;
	}else{
		cout << "this seat is already taken" << endl;
	}

	cout << table;

	ofstream fout("occupancy.txt");
	fout << table;
	fout.close();

	return 0;
}