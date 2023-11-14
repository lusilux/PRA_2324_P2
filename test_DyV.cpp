#include "DyV.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>

using namespace std;

int main() {
	srand(time(NULL));
	bb<int> clase1;
	bb<double> clase2;
	bb<char> clase3;

	vector<int> a = {1,2,3,4,5,6};
	vector<double> b = {1.2,2.3,3.4,4.5,5.6,6.7};
	vector<char> c = {'a','b','c','d','e','f'};

	int size = 6;

	cout << "**************************" << endl;
	cout << " BUSQUEDA BINARIA PRUEBAS " << endl;
	cout << "**************************" << endl << endl;

	cout << "**Vector de int:" << endl;
	clase1.print(a,size);
	int x = clase1.BusquedaBinaria(3,a,0,size-1);
	cout << "Elemento 3 encontrado en posicion " << x << endl << endl;

	cout << "**Vector de double:" << endl;
	clase2.print(b,size);
	int y = clase2.BusquedaBinaria(4.5,b,0,size-1);
	cout << "Elemento 4.5 encontrado en posicion " << y << endl << endl;

	cout << "**Vector de char:" << endl;
	clase3.print(c,size);
	int z = clase3.BusquedaBinaria('d',c,0,size-1);
	cout << "Elemento 'd' encontrado en posicion " << z << endl << endl;

	cout << "*******************************" << endl;
	cout << " BUSQUEDA BINARIA A LA INVERSA " << endl;
	cout << "*******************************" << endl << endl;

	cout << "**Vector:" << endl;
	vector<int> a_inv ={6,5,4,3,2,1};
	clase1.print(a_inv,size);
	x = clase1.BusquedaBinaria_INV(3,a_inv,0,size-1);
	cout << "Elemento 3 encontrado en posicion " << x << endl << endl;

	cout << "******************" << endl;
	cout << " QUICKSORT PRUEBA " << endl;
	cout << "******************" << endl << endl;

	cout << "**QuickSort con pivote en ultimo elemento" << endl;

	vector<int>vect ={6,4,2,3,8,9};
	
	cout << "**Vector a ordenar:" << endl;
	clase1.print(vect,size);
	auto start = chrono::system_clock::now();
	clase1.quickSort_fin(vect,0,size-1);
	auto end = chrono::system_clock::now();
	chrono::duration<float, std::milli> duration = end - start;
	cout << "**Vector ordenado: " << endl;
	clase1.print(vect,size); 
	cout << "Duración: " << duration.count() << "s" << endl;

	cout <<endl << "**QuickSort con pivote en primer elemento" << endl;

	vect ={6,4,2,3,8,9};
	
	cout << "**Vector a ordenar:" << endl;
	clase1.print(vect,size);
	start = chrono::system_clock::now();
	clase1.quickSort_ini(vect,0,size-1);
	end = chrono::system_clock::now();
	duration = end - start;
	cout << "**Vector ordenado: " << endl;
	clase1.print(vect,size); 
	cout << "Duración: " << duration.count() << "s" << endl;

	cout <<endl << "**QuickSort con pivote en elemento mitad" << endl;

	vect ={6,4,2,3,8,9};
	//vect ={9,9,2,3,1,5};
	
	cout << "**Vector a ordenar:" << endl;
	clase1.print(vect,size);
	start = chrono::system_clock::now();
	clase1.quickSort_mid(vect,0,size-1);
	end = chrono::system_clock::now();
	duration = end - start;
	cout << "**Vector ordenado: " << endl;
	clase1.print(vect,size); 
	cout << "Duración: " << duration.count() << "s" << endl;

	cout <<endl << "**QuickSort con pivote en elemento aleatorio" << endl;

	vect ={6,4,2,3,8,9};
	//vect ={9,9,2,3,1,5};
	
	cout << "**Vector a ordenar:" << endl;
	clase1.print(vect,size);
	start = chrono::system_clock::now();
	clase1.quickSort_rand(vect,0,size-1);
	end = chrono::system_clock::now();
	duration = end - start;
	cout << "**Vector ordenado: " << endl;
	clase1.print(vect,size); 
	cout << "Duración: " << duration.count() << "s" << endl;


	return 0;
}
