#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>

// las funciones que son x, son creadas

using namespace std;

struct Nodo {
	int numero;
	Nodo *sig;
};

void apilar (Nodo *&a);
void apilarr (Nodo *&a);
void desapilar (Nodo *&a);
int cima (Nodo *&a);
bool vacia  (Nodo *&a);
void imprimirx (Nodo *&a);

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

//cout<< "\n no se ha entendido la orden...";
int main(int argc, char **argv){
	printf("hello world\n");
	
	Nodo *pila = NULL;;
	
	bool verdad = true;
	char orden[20];
	int numero = 0;
	
	while (verdad == true){
		cout<< "\n escriba la orden:    ";
		cin.getline(orden,20,'\n');
		
		if (strcmp(orden, "salir") == 0){
			verdad = false;
			cout<< "\n se va a salir de programa";
		}else{
			if (strcmp(orden, "ls") == 0){
				cout<< "\n este es el listado de las ordenes:   apilar, apilarr, desapilar, cima, vacia?, salir, imprimirx";
			}else{
				if (strcmp(orden, "apilar")== 0){
					apilar (pila);
				}else{
					if (strcmp(orden, "apilarr") == 0){
						apilarr (pila);
					}else{
						if (strcmp(orden, "desapilar") == 0){
							desapilar(pila);
						}else{
							if (strcmp (orden, "cima") == 0){
								int nada = cima(pila);
							}else{
								if (strcmp(orden, "vacia?") == 0){
									bool nada = vacia (pila);
								}else{
									if (strcmp(orden, "imprimirx") == 0){
										imprimirx (pila);
									}else{
										cout<< "\n no se ha entendido la orden...";
									}
										
								}
							}
						}
					}
				}
			}
		}
	}
	cout <<"\n";
	return 0;
}

void apilar (Nodo *&a){
	int numero = 0;
	cout<< ("\n escriba el numero que ingresa:  ");
	cin >> numero; cin.ignore();
	Nodo *aux = new Nodo ();
	aux->numero = numero;
	aux->sig = a;
	
	a = aux;
}

void apilarr (Nodo *&a){
	int numero = azar(100);
	Nodo *aux = new Nodo ();
	aux->numero = numero;
	aux->sig = a;
	
	a = aux;
}

void desapilar (Nodo *&a){
	a = a->sig;	
}

int cima (Nodo *&a){
	cout <<"\n esta es la cima:  "<<a->numero;
	return a->numero;
}

bool vacia (Nodo *&a){
	bool verdad;
	if (a == NULL){
		cout<< "\n la pila esta VACIA";
		verdad = true;
	}else{
		cout <<"\n la pila contiene elementos";
		verdad = false;
	}
	return verdad;
}


void imprimirx (Nodo *&a){
	Nodo *aux = new Nodo ();
	aux = a;

	cout<<"\n ENTRADA DE DATOS//  ";
	while (aux != NULL){
		cout <<"   +";
		cout <<aux->numero;
		
		aux = aux->sig;
	}
	
}

