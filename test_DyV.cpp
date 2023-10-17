#include "DyV.h"
#include <iostream>
#include <vector>


int main() {
	bb<int> clase1;
	bb<double> clase2;
	bb<char> clase3;
	vector<int> a = {1,2,3,4,5,6};
	vector<double> b = {1.2,2.3,3.4,4.5,5.6,6.7};
	vector<char> c = {'a','b','c','d','e','f'};

	int size = 6;

	clase1.print(a,size);
	int x = clase1.BusquedaBinaria(3,a,0,size-1);
	cout << "Elemento 3 tipo int encontrado en pos " << x << endl;

	clase2.print(b,size);
	int y = clase2.BusquedaBinaria(4.5,b,0,size-1);
	cout << "Elemento 4.5 tipo double encontrado en pos " << y << endl;

	clase3.print(c,size);
	int z = clase3.BusquedaBinaria('d',c,0,size-1);
	cout << "Elemento d tipo char encontrado en pos " << z << endl;

	return 0;
}
