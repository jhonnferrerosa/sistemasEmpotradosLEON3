#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>

using namespace std;

struct Nodo {
    int num;
    Nodo *der;
    Nodo *izq;
};


int main(int argc, char **argv){
	
	int numero = 6;
	int valor = NULL;
	
	if (numero > valor){
		cout <<"\n si funcionaria el psedoodigo del profe, es mayor el numero";
	}else{
		cout <<"\n no funciona, pues no esta comparando";
	}
	cout <<"\n";
}
