#include "..\event.h"
using namespace std;

int main(){
	Event e;

	ifstream fin("event.txt");
	fin >> e;
	fin.close();
	cout << e << endl;

	return 0;
}