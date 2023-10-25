#include <iostream>
#include <vector>

using namespace std;

vector<int> v ={1,4,6};
const int VSIZE = 3;
const int M = 8;
const int NFILAS = 3, NCOL = 9;

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

int min(int a, int b){
    if(a < b)return a;
    else return b;
} 

int devolucion_monedas(vector<int> v, int M, vector<int> &sol){
    int T[NFILAS][NCOL];
    
    ini_T(T);
    
    T[0][0] = 0;

    for(int j = 1; j < M+1; j++){
        if(j >= v[0] && T[0][j-v[0]] != -1)T[0][j] = 1+ T[0][j-v[0]];    
    }   

    for(int i = 1; i < VSIZE; i++){
        T[i][0] = 0;
        for(int j = 1; j < M+1; j++){
            if(j < v[i] || T[i][j-v[i]] == -1)T[i][j] = T[i-1][j];   
            else if(T[i-1][j] != -1)T[i][j] = min(T[i-1][j], 1+T[i][j-v[i]]);  
            else T[i][j] = 1 + T[i][j-v[i]]; 
        }   
    } 

    int i = VSIZE-1;
    int j = M;
    while(i >= 0 && j != 0){
        if(i == 0 || T[i][j] != T[i-1][j]){
            sol[i] = sol[i] + 1;
            j = j - v[i];   
        } else i--;
    } 


    print(T);
    return T[VSIZE-1][M];
} 


int main(){
    vector<int> sol(VSIZE);
    for(int i = 0; i < VSIZE; i++) sol[i] = 0; 

    cout << "Cantidad a devolver: " << M << endl;
    int x = devolucion_monedas(v,M,sol);

    cout << "Monedas mínimas para dar el cambio: " << x << endl;
    cout << "Monedas de 1 euro: " << sol[0] << endl
    << "Monedas de 4 euros: " << sol[1] << endl
    << "Monedas de 6 euros: " << sol[2] << endl;   
    return 0;
} 