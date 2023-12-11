#include "../venue.h"
using namespace std;

int main(){

	Venue v1, v2("Allianz Arena");

	ifstream fin("venue.txt");
	fin >> v1;
	cout << v1 << endl;
	cout << v2 << endl;

	fin.close();


	return 0;
}