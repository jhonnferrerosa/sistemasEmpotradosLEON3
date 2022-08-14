#include <cstdlib>
#include <iostream>

using namespace std;

void cambio (int &a, int &b);

int main (){
	
	int jhon = 5;
	int ana = 7;
	
	cambio (jhon,ana);
	
	cout <<"\n este es el numero de jhon:   "<<jhon;
	cout <<"\n y este es el Numero de Ana:   "<<ana;
	
	cout <<"\n";
	return 0;
}

void cambio (int &a, int &b){
	int aux = 0;
	aux = a;
	a = b;
	b = aux;
}