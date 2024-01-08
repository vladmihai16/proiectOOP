#include "..\event.h"
using namespace std;

int main(){
	Event e;

	ifstream fin("event.txt");
	fin >> e;
	fin.close();
	cout << e << endl;
	ofstream fout("event.txt");
	fout << e;
	fout.close();

	return 0;
}