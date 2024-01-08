#include "..\event.h"
using namespace std;

int main(){
	Event event;

	ifstream fin("event.txt");
	fin >> event;
	fin.close();
	cout << event << endl;
	// event.getArea(0).occupy('W', 15);
	Ticket &t = *event.createTicket(0, 'W', 15);
	cin >> (t.getAttendee());
	cout << t;
	cout << event.getArea(0);
	ofstream fout("event.txt");
	fout << event;
	fout.close();

	return 0;
}