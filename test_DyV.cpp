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

	cout << "BUSQUEDA BINARIA PRUEBAS" << endl << endl;

	clase1.print(a,size);
	int x = clase1.BusquedaBinaria(3,a,0,size-1);
	cout << "Elemento 3 tipo int encontrado en pos " << x << endl;

	clase2.print(b,size);
	int y = clase2.BusquedaBinaria(4.5,b,0,size-1);
	cout << "Elemento 4.5 tipo double encontrado en pos " << y << endl;

	clase3.print(c,size);
	int z = clase3.BusquedaBinaria('d',c,0,size-1);
	cout << "Elemento d tipo char encontrado en pos " << z << endl;

	cout << endl <<"BUSQUEDA BINARIA A LA INVERSA" << endl << endl;
	vector<int> a_inv ={6,5,4,3,2,1};
	clase1.print(a_inv,size);
	x = clase1.BusquedaBinaria_INV(3,a_inv,0,size-1);
	cout << "Elemento 3 tipo int encontrado en pos " << x << endl;

	cout << "QUICKSORT PRUEBA" << endl << endl;
	vector<int>vect ={6,4,2,3,8,9};
	cout << "vector a ordenar:" << endl;
	clase1.print(vect,size);
	clase1.quickSort(vect,0,size-1);
	cout << "vector ordenado: " << endl;
	clase1.print(vect,size); 


	return 0;
}
