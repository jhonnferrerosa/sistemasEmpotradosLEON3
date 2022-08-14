
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int contadorAle = -1;

int azar (int x){
    int num;
    srand(time(NULL)); // que me proporciona un aleatorio cada vez de un nuevo programa
    if (contadorAle == -1){
        contadorAle = rand()%100; // numero aleatorio cada vez de programa... // solo aplica cuando el contador esta sin tocar
    }else{
        contadorAle++; // crea un numero mas cada vez  que se  ejecuta la funcion   
    }
    srand(contadorAle);
    num = rand()%x;
    
    return num;
}

int main(int argc, char** argv) {
    
    int max = 10;
    
    cout <<"\n  +++ comienza +++";
    
    int a = azar(max);
    cout <<"\n este es el numero:  "<<a;

    
	cout <<"\n";
    return 0;
}


