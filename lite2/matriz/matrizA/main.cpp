#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

void pedir ();
void sumar (int **a, int **b, int x, int y);
void mostrar (int **a, int x, int y);

int **ma1, **ma2, fil, col;


int main(int argc, char** argv) {
    
    pedir ();
    sumar (ma1,ma2,fil,col);
    mostrar (ma1,fil,col);
    cout <<"\n";
    mostrar (ma2,fil,col);

    return 0;
}

void mostrar (int **a, int x, int y){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cout <<"-" << *(*(a+i)+j);
        }
        cout <<"\n";
    }
}

void sumar (int **a, int **b, int x, int y){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            *(*(ma1+i)+j) = *(*(ma1+i)+j) + *(*(ma2+i)+j);
            
        }
    }
}

void pedir (){
    srand(time(NULL));
    int ale = 0;
    cout <<" ponga cuantas filas:   ";
    cin >>fil; cin.ignore();
    
    cout <<" ahora cuantas columnas:   ";
    cin >>col; cin.ignore();
    
    // reserva de memoria...
    
    ma1 = new int *[fil];
    for (int i = 0; i < fil; i++){
        ma1[i] = new int [col];
    }
    
    for (int j = 0; j < fil; j++){
        for (int k = 0; k < col; k++){
            ale = rand()%20;
            *(*(ma1+j)+k) = ale;
        }
    }
    
    //----------------ahora vamos a por la segunda matriz
    
    ma2 = new int *[fil];
    for (int l = 0; l < fil; l++){
        ma2[l] = new int [col];
    }
    
    for (int m = 0; m < fil; m++){
        for (int n = 0; n < col; n++){
            ale = rand()%20;
            *(*(ma2+m)+n) = ale;
        }
    }
    
    
}
