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

	T BusquedaBinaria_INV(T x, vector<T>& v, int ini, int fin){
		if(ini > fin){ cout << "No se encuentra en el array\n"; return -1;}
		
		int medio = (ini+fin)/2;
		if(v[medio] == x)return medio;
		else if(v[medio] > x)return BusquedaBinaria_INV(x,v,medio+1,fin);
		else return BusquedaBinaria_INV(x,v,ini,medio-1);
	}

	void print(vector<T> &v, int size){
		for(int i = 0; i < size; i++)cout << v[i] << " ";
	       cout << endl;	
	}

	void swap(vector<T> &a, int x, int y){
		int aux = a[x];
		a[x] = a[y];
		a[y] = aux;
	}

	int partition(vector<T> &a, int ini, int fin){
		int p = a[ini];
		int i = ini;
		int j = fin;
	
		do{
			for(int k = 0; a[i] <= p && i < fin;k++)i++;
			for(int k = 0; a[j] >= p && j > ini; k++)j--;
			swap(a,i,j);
		}while(i<j);
		swap(a,i,j);
		swap(a,ini,j);
		return j;
	}

	void quickSort(vector<T> &a, int ini, int fin){
		int tam = fin - ini + 1;
		if(tam > 1){
			int s = partition(a,ini,fin);
			//print_arr(a,tam);
			quickSort(a,ini,s);
			quickSort(a,s+1,fin);
		}else return;
	}
};

#endif
