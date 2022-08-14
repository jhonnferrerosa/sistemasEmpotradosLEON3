#include <cstdlib>
#include <iostream>
#include <string.h>


// hecer al total de elementos de un array, char* y string (funcion) teniendo en cuante el ultimo element es NULL

using namespace std;

int elementosString (string a); // la clave es ver que el siguiente del Ultimo, es NULL;

int main(int argc, char** argv) {
    
    string frase = "hola";
    
    int total = elementosString (frase);
    cout <<"\n este es el total de elementos:   "<<total;
    
	cout <<"\n";
    return 0;
}

int elementosString (string a){
    int total = 0;
    
    while (a[total] != NULL){
        total++;
    }
    
    return total;
}
