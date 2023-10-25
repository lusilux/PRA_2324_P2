#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int PESO = 15;
const int N = 3;
const int NFILAS = 4, NCOL = 16;

void ini_T(int T[][NCOL]){
    for(int i = 0; i < NFILAS; i++){
        for(int j = 0; j < NCOL; j++){
            T[i][j] = -1;  
        } 
    } 
}

void print(int T[][NCOL]){
    for(int i = 0; i < NFILAS; i++){
        for(int j = 0; j < NCOL; j++){
            cout << T[i][j] << " ";
        } 
        cout << endl;
    } 
}

int beneficio_mochila(vector<int> &p, vector<int> &b, vector<int> &sol){
    int T[NFILAS][NCOL];
    
    ini_T(T);

    for(int j = 0; j < PESO+1; j++){
        T[0][j] = 0;  
        T[j][0] = 0;  
    }   


    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < PESO+1; j++){
            int aux = j-p[i-1]; 
            if(j-p[i-1] < 0) T[i][j] = T[i-1][j];    
            else T[i][j] = max(T[i-1][j],b[i-1] + T[i-1][aux]); 
        }   
    } 

    int j = PESO;
    for(int i = N; i > 0; i--)if(T[i][j] != T[i-1][j])sol[i] = 1;


    print(T);
    return T[N][PESO];
} 


int main(){
    vector<int> sol(N);
    for(int i = 0; i < N; i++) sol[i] = 0; 

    vector<int> pesos = {9,6,5};
    vector<int> beneficios = {38,40,24};
    cout << "Matriz: " << endl;
    int max_benef = beneficio_mochila(pesos,beneficios, sol);
    cout << "Máximo beneficio: " << max_benef << endl;

    for(int k = 0; k < N; k++)cout << "Se usa el elemento " << k << sol[k] << "vez" << endl; 
    

    return 0;
} 