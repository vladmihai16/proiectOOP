#include "../area.h"
using namespace std;

int main(){
	ifstream fin("areas.txt");
	Area a1, a2;

	while(fin >> a1){
		cout << a1;
	}
	fin.close();

	a2 = a1;
	cout << "a2 = " <<a2;

	cout << "area: "; cin >> a2;
	ofstream fout("areas.txt", ofstream::app);
	fout << a2;
	fout.close();

	return 0;
}