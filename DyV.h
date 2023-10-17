#ifndef DYV_H
#define DYV_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T> class bb{
	public: 

	T BusquedaBinaria(T x, vector<T>& v, int ini, int fin) {
		if(ini > fin){ cout << "No se encuentra en el array\n"; return -1;}
		
		int medio = (ini+fin)/2;
		if(v[medio] == x)return medio;
		else if(v[medio] > x)return BusquedaBinaria(x,v,ini,medio-1);
		else return BusquedaBinaria(x,v,medio+1,fin);
	}

	void print(vector<T> &v, int size){
		for(int i = 0; i < size; i++)cout << v[i] << " ";
	       cout << endl;	
	}
};

#endif
