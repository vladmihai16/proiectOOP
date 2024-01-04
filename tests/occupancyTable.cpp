#include "../occupancyTable.h"
using namespace std;

int main(){
	Area area;
	OccupancyTable table;

	ifstream fin1("areas.txt");
	while(fin1 >> area){
		OccupancyTable t1(area);
		ofstream fout1("occupancy\\" + t1.getName() + ".txt");
		fout1 << t1;
		fout1.close();
	}

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