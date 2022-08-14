


#include <cstdlib>
#include <iostream>

using namespace std;

int main (){
	int num = 0;
	int *pos_num;
	int numeros[] = {9,5,6,3,1,2};
	int *pos_numeros;
	
	pos_num = &num;
	
	cout <<"\n este es el numero:   "<<*pos_num;
	cout <<"\n y esta es la direccion de memoria:   "<<pos_num;
	
	pos_numeros = numeros;
	
	for (int i = 0; i < 5; i++){
		cout <<"\n posicion:    "<<pos_numeros <<"  corres ponde al num:   "<<*pos_numeros;
		
		pos_numeros++;
	}
	
	
	
	
	cout <<"\n";
	return 0;
}