
#include <iostream>
#include <cstdlib>

using namespace std;

void modifica (int *&a);

int maximo = 5;

int main (){
	
	int *vector;
	vector = new int [maximo];
	
	int partida = 20;
	for (int i = 0; i < maximo; i++){
		partida++;
		vector[i] = partida;
	}
	
	modifica (vector);
	
	
	for (int j = 0; j < maximo; j++){
		cout <<"+--" <<vector[j];
	}
	
	cout <<"\n";
	return 0;
}


void modifica (int *&a){
	int pasarela = 40;
	
	for (int i = 0;  i < maximo; i++){
		a[i] = pasarela;
		pasarela++;
	}
	
	
}
