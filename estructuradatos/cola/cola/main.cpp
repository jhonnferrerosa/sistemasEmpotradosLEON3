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

struct Cola {
	Nodo *entrada;
	Nodo *salida;
};

void anadir (int x, Cola *&c); // PROCEDIMIENTO
void eliminar (Cola *&c);  //PROCEDIMIENTO
int primero (Cola *&c);
bool vacia (Cola *&c);
void imprimirx (Cola *&c);


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
	
	Cola *c = new Cola ();
	c->entrada = NULL;
	c->salida = NULL;
	
	bool verdad = true;
	char orden[20];
	int auxnumero = 0;
	
	while (verdad == true){
		cout <<"\n escriba la orden:   ";
		cin.getline(orden, 20, '\n');
		
		if (strcmp (orden, "ls") == 0){
			cout <<"\n este es el listado de ordenes:  anadir, anadirr, eliminar, primero, vacia,  salir, imprimirx";
		}else{
			if (strcmp(orden, "salir") == 0){
				cout<<"\n se  va sa salir del programa";
				verdad = false;
			}else{
				if (strcmp (orden, "imprimirx") == 0){
					imprimirx (c);
				}else{
					if (strcmp(orden, "anadir") == 0){
						cout<< "\n escriba el numero a insertar:  ";
						cin>> auxnumero; cin.ignore();
						anadir (auxnumero, c);
					}else{
						if (strcmp(orden, "anadirr") == 0){
							auxnumero = azar(100);
							anadir (auxnumero, c);
						}else{
							if (strcmp (orden, "eliminar") == 0){
								eliminar (c);
							}else{
								if (strcmp (orden, "primero") == 0){
									int nada = primero (c);
								}else{
									if (strcmp(orden, "vacia?") == 0){
										bool nada = vacia (c);
									}else{
										cout <<"\n no se ha enrtendido la orden...";
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<"\n";
	return 0;
}

void anadir (int x, Cola *&c){
	Nodo *aux = new Nodo ();
	aux->numero = x;
	aux->sig = NULL;
	
	if (c->salida == NULL){
		c->salida = aux;
	}else{
		c->entrada->sig = aux;
	}
	c->entrada = aux;
}
void eliminar (Cola *&c){
	if (c->salida == NULL){
		cout <<"\n y esta vacia la Cola...(?)";
	}else{
		if (c->salida->sig == NULL){ //si se vacia el ultimo,  los dos Nodos queden en NULL
			c->salida = c->salida->sig;
			c->entrada = c->entrada->sig;
			cout <<"\n se ha restado (-)";
		}else{
			c->salida = c->salida->sig;
			cout <<"\n se ha restado (-)";
		}
	}
}

int primero (Cola *&c){
	int x = 0;
	if (c->salida == NULL){
		cout<< "\n la cola esta vacia, no hay primero...";
	}else{
		x = c->salida->numero;
		cout <<"\n este es el primero de la cola:  "<<x;
	}
	return x;
}

bool vacia (Cola *&c){
	bool verdad = true;
	if (c->salida == NULL){
		cout<< "\n SI esta vacia...";
	}else{
		cout<<"\n la cola tiene elementos";
		verdad = false;
	}
	return verdad;
}

void imprimirx (Cola *&c){
	Nodo *aux = new Nodo ();
	
	aux  = c->salida;
	
	bool verdad = true;
	
	while ( aux != NULL){
		cout <<"   ---" <<aux->numero;
		aux = aux->sig;
	}
	cout <<"\\\\\  ENTRADA DE DATOS";
}