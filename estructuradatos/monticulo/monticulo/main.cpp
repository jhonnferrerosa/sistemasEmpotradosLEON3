#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>

// el hijo izquierdo es 2*i+1
// el hijo derecho es 2*1+2

// padre = (i-1)/2

using namespace std;  // este simbolo es el hash #

struct Nodo {
    int num;
    Nodo *der;
    Nodo *izq;
};

void imprimir (int *&a);
int* mas (int *&a, int b, int c); // monticulo, maximo, numero, es necesario que se le pase el maximo,para que sepa cuando no hay que meter

int hijoizq (int *&a, int posicion);
int hijoder (int *&a, int posicion);
int padre (int *&a, int posicion);

int longitud (int *&a);

int *borrartodo (int *&a);
int *borrar (int *&a); /// inserta la posicion en la que se va a borrar+

int *reflotar(int *&a, int posicion);

void masa(int x, Nodo *&a);
void imprimirx (int x, Nodo *&a);
bool escompleto (Nodo *&a);
int altura (Nodo *&a);

int numhojas(Nodo *&a);
bool potencias (Nodo *&a); // si el numero deo hojas no cuadra con el num de hojas de un completo, bool = false

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
	
	int maximo = 20;
	bool verdad = true;
	int numero = 0;
	char orden[20];
	int *monticulo;
	monticulo = new int [maximo];;
	int dimension = 0;
	Nodo *arbol = NULL;
	int contador = 0;
	
	for (int i = 0; i <= maximo; i++){ // de esta manera, como las funciones no van a meter valores en el elemento que sobrepasa el array, entonces ese elemento
		monticulo[i] = NULL;  // que sobrepasa siempre es NULL.  
	}
	
	while (verdad == true){
		cout <<"\n escriba la orden:  ";
		cin.getline(orden, 20, '\n');
		if (strcmp (orden, "salir") == 0){
			verdad = false;
		}else{
			if (strcmp (orden, "ls") == 0){
				cout <<"\n este es el listado de ordenes que hay: salir, mas, imprimir, hijoizq, hijoder, padre, masm, masmx";
				cout <<"\n borrartodo, longitud, borrar, reflotar, imprimirx";
			}else{
				if (strcmp (orden, "mas") == 0){
					cout <<"\n escriba el numero a insertar:   ";
					cin>> numero; cin.ignore();
					monticulo = mas (monticulo, maximo, numero);
					dimension = longitud (monticulo);
					monticulo = reflotar (monticulo, dimension-1);
				}else{
					if (strcmp (orden, "imprimir") == 0){
						imprimir (monticulo);
					}else{
						if (strcmp (orden, "masm") == 0){
							numero = azar (100);
							monticulo = mas (monticulo, maximo, numero);
							dimension = longitud (monticulo);
							monticulo = reflotar (monticulo, dimension-1);
						}else{
							if (strcmp (orden, "hijoizq") == 0){
								cout <<"\n escriba la posicion del que quiere buscarle el hijoizq:   ";
								cin >> numero; cin.ignore();
								numero = hijoizq (monticulo, numero);
								cout <<"\n esta es la posicion de su hijo zquierdo:  "<<numero;
							}else{
								if (strcmp (orden, "hijoder") == 0){
									cout <<"\n escriba la posicion del que quiere buscarle el hijder:   ";
									cin >>numero; cin.ignore();
									numero = hijoder (monticulo,  numero);
									cout <<"\n esta es la posicion de su hijo derecho:  "<<numero;
								}else{
									if (strcmp(orden, "padre") ==  0){
										cout <<"\n escriba la posicion del valor al que desea buscar el padre:   ";
										cin>> numero; cin.ignore();
										numero = padre (monticulo,  numero);
										cout <<"\n esta es la posicion de su padre:   "<<numero;
									}else{
										if (strcmp (orden, "masmx") == 0){
											monticulo = mas (monticulo, maximo, 13);
											dimension = longitud (monticulo);
											monticulo = reflotar (monticulo, dimension-1);
											
											monticulo = mas (monticulo, maximo, 21);
											dimension = longitud (monticulo);
											monticulo = reflotar (monticulo, dimension-1);
											
											monticulo = mas (monticulo, maximo, 16);
											dimension = longitud (monticulo);
											monticulo = reflotar (monticulo, dimension-1);
											
											monticulo = mas (monticulo, maximo, 24);
											dimension = longitud (monticulo);
											monticulo = reflotar (monticulo, dimension-1);
											
											monticulo = mas (monticulo, maximo, 31);
											dimension = longitud (monticulo);
											monticulo = reflotar (monticulo, dimension-1);

											monticulo = mas (monticulo, maximo, 19);
											dimension = longitud (monticulo);
											monticulo = reflotar (monticulo, dimension-1);
											
											monticulo = mas (monticulo, maximo, 68);
											dimension = longitud (monticulo);
											monticulo = reflotar (monticulo, dimension-1);
											
											monticulo = mas (monticulo, maximo, 65);
											dimension = longitud (monticulo);
											monticulo = reflotar (monticulo, dimension-1);
											
											monticulo = mas (monticulo, maximo, 26);
											dimension = longitud (monticulo);
											monticulo = reflotar (monticulo, dimension-1);
											
											monticulo = mas (monticulo, maximo, 32);
											dimension = longitud (monticulo);
											monticulo = reflotar (monticulo, dimension-1);
										}else{
											if (strcmp (orden, "borrartodo") == 0){
												monticulo = borrartodo (monticulo);
											}else{
												if (strcmp (orden, "longitud") == 0){
													numero = longitud (monticulo);
													cout <<"\n esta es la longitud de monticulo:  "<<numero;
												}else{
													if (strcmp (orden, "borrar") == 0){
														monticulo = borrar (monticulo);
													}else{
														if (strcmp (orden, "reflotar") == 0){
															cout <<"\n inserte la POSICION que desea reflotar:   ";
															cin >>numero; cin.ignore();
															monticulo = reflotar (monticulo, numero);
														}else{
															if (strcmp (orden, "imprimirx") == 0){ // tienes que crear un arbol nuevo e insertarle por orden todos los valores del monticulo 
																contador = 0;
																while (monticulo[contador] != NULL){ // en cuanto llege al NULL, ese es el final 
																	masa(monticulo[contador], arbol);
																	contador++;
																}
																cout <<"\n";
																imprimirx(0,arbol);
																arbol = NULL;   // una vez que  se ha impreso, puedo borrarlo, para que cuando tenga que volver a rellenar ya este vacio
															}else{
																cout <<"\n No se ha entendido la orden... ";
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	cout <<"\n ------------- se FINALIZO el programa ---------------";
	printf("\n");
	return 0;
}

void imprimir(int *&a){
	int contador = 0;
	if (a[0] == NULL){
		cout <<" ...  el monticulo esta vacio... ";
	}
	while (a[contador] != NULL){
		cout <<"   ---" <<a[contador];
		contador++;
	}
}

int* mas (int *&a, int b, int c){
	int contador = 0;
	while (a[contador] != NULL){
		contador++;
	}
	
	if (contador >= b){
		cout <<"\n No se va a insertar, no cabe mas";
		return a;
	}else{
		//
		cout <<"\n se va a insertar en la posicion:   "<<contador;
		a[contador] = c;
	}
	
	return a;
}

int hijoizq (int *&a, int posicion){ // monticulo, maximo, posicion
	int valor = 0;
	valor = 2*posicion+1;
	int longitudmonticulo = longitud (a);
	if (valor >= longitudmonticulo) {
		cout <<"\n ese hijo no existe, el monticulo es mas pequeno...";
		return NULL;;
	}
	return valor;
}

int hijoder (int *&a, int posicion){
	int valor = 0;
	valor = 2*posicion+2;
	int longitudmonticulo = longitud (a);
	if (valor >= longitudmonticulo){
		cout <<"\n ese valor  no existe, el monticulo es mas pequeno...";
		return NULL;;
	}
	return valor;
}

int padre (int *&a, int posicion){
	int valor = 0;
	int longitudmonticulo = longitud (a);
	if (posicion  >= longitudmonticulo){
		cout <<"\n ese valor  no existe, el monticulo es mas pequeno...";
		return NULL;
	}
	valor = (posicion-1)/2;
	return valor;
}

int longitud (int *&a){
	int total = 0;
	while (a[total] != NULL){
		total++;
	}
	return total;
}

int *borrartodo (int *&a){
	int longitudmonticulo = longitud (a);
	cout <<"\n esta es la longitud del monticulo:   "<<longitudmonticulo;
	for (int i = 0; i < longitudmonticulo; i++){
		a[i] = NULL;
		cout <<"\n se ha hecho NULL la posicon:  "<<i;
	}
	return a;
}

int *borrar (int *&a){
	int l = longitud (a);
	if (a[0] == NULL){
		cout <<"\n no se puede borrar, porque el monticulo ya esta vacio ";
	}else{
		int l = longitud (a);
		a[l-1] = NULL;
	}
	return a;
}

int *reflotar (int *&a, int posicion){ // estamos hablando de posicion
	int longitudmonticulo = longitud (a);
	if (posicion >= longitudmonticulo){
		cout <<"\n no se puede reflotar ese valor, el monticulo es mas pequeno";
		return a;
	}

	int valorprincipal = a[posicion];
	bool verdad = true;
	while (verdad == true){
		int papa = padre (a, posicion); // este valor va a cambiar, viendo los diferentes padres que puede tener
		int valorpapa = a[papa];
		if (valorprincipal < valorpapa){
			a[posicion] = valorpapa;
			a[papa] = valorprincipal;
			posicion = papa;  // para actualizar la nueva posicion en la que esta mi valor
		}else{
			//cout <<"\n no se reflota";
			verdad = false;
		}
	}
	return a;
}

void masa (int x, Nodo *&a){   ///////ME QUEDO EN QUE NO SE ME IMPRIME EL MONTICULO COMO SI FUERA UN ARBOL ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //cout <<"\n se inserta en arbol:  "<<x;
	Nodo *aux = new Nodo ();
    if (a == NULL){
		//cout <<"\n se va a inseter en el centro:   "<<x;
        aux->num = x;
        aux->izq = NULL;;
        aux->der = NULL;
		a = aux;
    }else{
        if (a->izq == NULL){
			//cout <<"\n se va a inseter en el izquierdo:   "<<x;
			masa(x, a->izq);
        }else{
            if (a->der == NULL){
				///cout <<"\n se va a inseter en el derecho:   "<<x;
				masa (x, a->der);
            }else{
				if (escompleto(a) == true){
					masa (x, a->izq);
				}else{
					if (((altura(a->izq) > altura (a->der)) && (escompleto (a->izq )== false))){
						masa(x, a->izq);
					}else{
						masa (x, a->der);
					}
				}
            }
        }
    }
}


void imprimirx (int x, Nodo *&a){    
    if (a == NULL){
        return; 
    }else{
        imprimirx (x+1,a->der);
        for (int i = 0; i < x; i++){
            cout <<"       ";
        }
        cout <<a->num;
        cout <<"\n";
        imprimirx (x+1, a->izq);
    }
}


bool escompleto (Nodo *&a){
		bool verdad = true;
		
		if ((a->izq != NULL) && (a->der == NULL)){
			verdad = false;
		}else{
			if ((altura (a->izq) == altura (a->der)) && (potencias(a) == true)){  // entonces es completo
				verdad = true;
			}else{
				verdad = false;
			}
		}
		return verdad;
}

int altura (Nodo *&a){
	int alt = 0;
	
	if (a == NULL){
		return NULL;
	}
	
	if ((a->der == NULL) && (a->izq == NULL)){
			return alt;
	}else{
		if (a->der == NULL){
			alt = 1 + altura (a->izq);
		}else{
			if (a->izq == NULL){
				alt = 1 + altura (a->der);
			}else{
				alt = 1 + max(altura(a->izq), altura(a->der));
			}
		}
	}
}

int numhojas (Nodo *&a){ // cuenta el numero de hojas de un arbol
	int total = 0;
	
	if (a == NULL){
		total = 0;
	}else{
		if ((a->izq == NULL) && (a->der == NULL)){
			total = 1;
		}else{
			total = total + numhojas(a->izq) +  numhojas(a->der);
		}
	}
	return total;
}
bool potencias (Nodo *&a){  // si el numero deo hojas no cuadra con el num de hojas de un completo, bool = false
	int numero = numhojas (a); // espero que esta linea funcione. 
	bool verdad = true; // hacer que de momento ese numero cuadre con la potencia de 2. 
	int modulo = 0;
	if (numero == 0){
		verdad = false;
	}else{
		while (numero >= 2){
			modulo = numero % 2;
			if (modulo != 0){
				verdad = false;
				break;
			}
			numero = numero /2;
		}
	}
	return verdad;
}