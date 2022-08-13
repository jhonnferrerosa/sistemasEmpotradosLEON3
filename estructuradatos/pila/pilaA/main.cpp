#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include <windows.h>

// las funciones que son x, son creadas

using namespace std;

struct Nodo {
	int numero;
	Nodo *sig;
};

struct Pila {
	Nodo *nodo;
};

// la funcin de pvacia: ->pila.  No la voy a hacer, se va a crear una pila en cuanto se arranque el programa
void apilar (int x, Pila *&p);  //PROCEDIMIENTO
void desapilar (Pila *&p); // PROCEDIMIENTO
int cima (Pila *&p);
bool vacia  (Pila *&p);

void imprimirx (Pila *&p);

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

int main(int argc, char **argv){
	printf("hello world\n");
	
	Pila* p = new Pila ();
	p->nodo = NULL;
	
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
					cout<< "\n ingrese el numero:   ";
					cin >>numero; cin.ignore();
					apilar (numero, p);
				}else{
					if (strcmp(orden, "apilarr") == 0){
						numero = azar(100);
						cout<<"\n este es el numero a insertar que es del azar:  "<<numero;
						apilar (numero, p);
					}else{
						if (strcmp(orden, "desapilar") == 0){
							desapilar(p);
						}else{
							if (strcmp (orden, "cima") == 0){
								int nada = cima(p);
							}else{
								if (strcmp(orden, "vacia?") == 0){
									bool nada = vacia (p);
								}else{
									if (strcmp(orden, "imprimirx") == 0){
										imprimirx (p);
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


void apilar (int x, Pila *&p){  /// las modificaciones de las estructuras de las estructuras deben retornar la estructura princp
	int numero = x;
	Nodo *aux = new Nodo ();
	aux->numero = numero;
	aux->sig = p->nodo;
	
	p->nodo = aux;
}
void desapilar (Pila *&p){
	if (p->nodo == NULL){
		cout <<"\n No se puede desapialr, YA ESTA VACIA";
	}else{
		p->nodo = p->nodo->sig;
	}
	
}
int cima (Pila *&p){
	if (p->nodo == NULL){
		cout <<"\n no hay cima, la pila esta vacia... ";
	}else{
		cout <<"\n esta es la cima:  "<<p->nodo->numero;
	}
}

bool vacia (Pila *&p){
	bool verdad;
	if (p->nodo == NULL){
		cout<< "\n la pila esta VACIA";
		verdad = true;
	}else{
		cout <<"\n la pila contiene elementos";
		verdad = false;
	}
	return verdad;
}

void imprimirx (Pila *&p){
	Nodo *aux = new Nodo ();
	aux = p->nodo;

	cout<<"\n ENTRADA DE DATOS//  ";
	while (aux != NULL){
		cout <<"   +";
		cout <<aux->numero;
		
		aux = aux->sig;
	}
}