#include <iostream>
using namespace std;

int main() {
	//Allokiere und initialisiere 8 int-Objekte
	int myArray[] = { 12, 15, 17, 35, 39, 47, 78, 83 };

	//Feldlänge bestimmen
	const int myArrayLength = (int)sizeof(myArray) / sizeof(int);

	//Allokiere und initialisiere neues Array
	int* myArray2 = new int[8];
	for (int i = 0; i < 8; i++) {
		myArray2[i] = i;
	}

	//Ausgabe von allen Feldelementen
	int* p1 = myArray;
	for (int i = 0; i < myArrayLength; i++) {
		cout << "myArray-Element " << i << ": " << *p1 << endl;
		p1++;
		cout << "myArray-Element " << i << ": " << myArray[i] << endl;
		cout << "myArray2-Element " << i << ": " << myArray2[i] << endl;
	}
}


