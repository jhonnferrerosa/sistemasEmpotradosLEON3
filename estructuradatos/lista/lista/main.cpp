#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>

using namespace std;  // este simbolo es el hash #

struct Nodo{
	int num;
	Nodo *sig;
};

struct Lista{
	Nodo *entrada;
	Nodo *salida;
	int longitud;
};

// No puedo distinguir entre funciones y procedimientos en c++, porque no se como pasar por parametro a una lista

Lista* corchetes ();  // esto crea una lista vacia, pero en este programa no se va a utilizar porque trabajare con una sola lista que yo he creado,  voy a hacer la funcion, pero solo como EJEMPLO. 
void  dospuntos (int x, Lista *&l); // añade por zquierda ,  PROCEDIMEINTO
void  resto (Lista *&l);  // elimina el primero   PROCEDIMENTO
void eult (Lista *&l); // elimina el ultimo   PROCEDMIENTO
int prim (Lista *&l);  // ver primero 
int ult (Lista *&l);  // ver ultimo
bool vacia (Lista *&l);  // ver s esta vacia

Lista* corchetesespaciodentro (int x);  // crea una lista unitaria
void  hashh  (int x, Lista *&l);  // añade por derecha  PROCEDMIENTO
Lista* masmas (Lista *&l, Lista *&m);  /// concatenar 2 listas
int longg (Lista *&l); // longitud de la lista

int espaciocorchetes (int x, Lista *&l);  // devuelve el elemento que estaba en la posicion que  le pases por parametro
void insertar (int x, Lista *&l, int y);  // inseerta el elemento en la poscion indicada PROCEDMIENTO
void modificar (int x, Lista *&l, int y);   // modifica el elemrento de la posocion indicada PROCEDIMIENTO
void borrar (int x, Lista *&l);  // borra el elemento de la posicion indicada PROCEDIMIENTO
bool esta (int x, Lista *&l);  // averigua si el elemento que se le pasa esta en la lista.
int buscar (int x, Lista *&l);  // devuelve la posicion en la que esta ese elemento que le paasas por parametro.

void imprimirx (Lista *&l);
void vaciarx (Lista *&l);

void prueba (Lista *&l);

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

int main (){
	cout <<"------------lista-----------";
	
	
	Lista *lista = new Lista (); // esta lista es NULL??
	lista->entrada = NULL;
	lista->salida = NULL;
	lista->longitud  = 0;
	
	bool verdad = true;
	int numero = 0;
	char orden[20];
	int numeroSacado = 0;
	int auxnumero;
	bool auxbool;
	int auxnumero2;
	
	// la clave de esto es que se crea un nodo nuevo cada vez que se va a insertar un 
	// dato nuevo, de manera que este nuevo nodo apunta a mi lista que ya tengo 
	// y hago que mi lista actual que ya tengo apunte a este nodo, y asi es como 
	// se hace la union
	Lista *auxlista = new Lista ();
	auxlista->entrada = NULL;
	auxlista->salida = NULL;
	auxlista->longitud = 4;
	
	
	Nodo *auxnodo1 = new Nodo ();	
	auxnodo1->num = 6;  // he sumado uno por derecha
	auxnodo1->sig = NULL;
	auxlista->salida = auxnodo1;
	auxlista->entrada = auxlista->salida; // solo una vez, ya que esta vacia
	
	Nodo *auxnodo2 = new Nodo ();
	auxnodo2->num = 7;  // he sumado uno por derecha
	auxnodo2->sig = auxlista->salida;
	auxlista->salida = auxnodo2;	
	
	Nodo *auxnodo3 = new Nodo ();
	auxnodo3->num = 8;  // he sumado uno por derecha
	auxnodo3->sig = auxlista->salida;
	auxlista->salida = auxnodo3;
	
	Nodo *auxnodo4 = new Nodo ();
	auxnodo4->num = 9;  // he sumado uno por derecha
	auxnodo4->sig = auxlista->salida;
	auxlista->salida = auxnodo4;
	
	//cout <<"\n No se ha entendido la orden...";
	while (verdad == true){
		cout <<"\n escriba la Orden:   ";
		cin.getline (orden,20,'\n');
		
		if (strcmp (orden,"ls") == 0){
			cout <<"Este es el listado de ordenes que hay: salir, hashh, hashhh, esta?, resto, eult, longg";
			cout <<"\n prim, ult, dospuntos, vacia? imprimirx, imprimiry, masmas";
			cout <<"\n espaciocorchetes, insertar, modificar, borrar, buscar, prueba";
		}else{
			if (strcmp (orden, "salir") == 0){
				verdad = false;
			}else{
				if (strcmp (orden, "hashh") == 0){
					cout<<"\n ponga el numero a insertar:   ";
					cin>> auxnumero; cin.ignore();
					hashh (auxnumero, *&lista);
				}else{
					if (strcmp (orden, "hashhh") == 0){
						auxnumero = azar (100);
						hashh (auxnumero,*& lista);
					}else{
						if (strcmp (orden, "imprimirx") == 0){
							imprimirx (*&lista);
						}else{
							if (strcmp (orden, "longg") == 0){
								auxnumero = longg(*&lista);
								cout <<"\n esta es la longitud de la lista:   "<<auxnumero;
							}else{
								if (strcmp (orden, "esta?") == 0){
									cout <<"\n escriba el numero que busca:   ";
									cin>> auxnumero; cin.ignore();
									auxbool = esta (auxnumero, *&lista);
									cout <<"\n la respuesta de si esta es:    "<<auxbool;
								}else{
									if (strcmp (orden, "resto") == 0){
										resto (*&lista);
									}else{
										if (strcmp (orden, "longg") == 0){
											auxnumero = longg (*&lista);
											cout <<"\n esta es la longitud de la lista:   "<<auxnumero;
										}else{
											if (strcmp (orden, "prim") == 0){
												auxnumero = prim(*&lista);
												cout <<"\n este es el primero de la lista:   "<<auxnumero;
											}else{
												if (strcmp (orden, "ult") == 0){
													auxnumero = ult(*&lista);
													cout <<"\n este es el ultimo de la lista:   "<<auxnumero;
												}else{
													if (strcmp(orden, "dospuntos") == 0){
														cout<<"\n ponga el numero a insertar:   ";
														cin>> auxnumero; cin.ignore();
														dospuntos (auxnumero, *&lista);
													}else{
														if (strcmp (orden, "vacia?") == 0){
															auxbool = vacia (*&lista);
															cout <<"\n esta es la respuesta de si esta vacia:    "<<auxbool;;
														}else{
															if (strcmp (orden, "eult") == 0){
																eult(*&lista);
															}else{
																if (strcmp (orden, "imprimiry") == 0){
																	imprimirx (auxlista);
																}else{
																	if (strcmp (orden, "masmas") == 0){
																		lista = masmas (lista,auxlista);
																	}else{
																		if (strcmp (orden, "espaciocorchetes") == 0){
																			cout <<"\n ponga la posicion que va a localizar:   ";
																			cin>> auxnumero; cin.ignore();
																			if (auxnumero > longg (*&lista)){
																				cout <<"\n esa posicion No existe, la lista es mas pequena...";
																			}else{
																				auxnumero = espaciocorchetes (auxnumero, lista);
																				cout <<"\n este es el valor que se ha sacado:   "<<auxnumero;
																			}
																		}else{
																			if (strcmp(orden, "insertar") == 0){
																				cout <<"\n ponga el elemento a insertar:   ";
																				cin>> auxnumero; cin.ignore();
																				cout <<"\n ahora ponga la Posicion a insertar:   ";
																				cin>> auxnumero2; cin.ignore();
																				if (auxnumero2 > longg (*&lista)){
																					cout <<"\n esa posicion No existe, la lista es mas pequena...";
																				}else{
																					insertar (auxnumero, *&lista, auxnumero2);
																				}
																			}else{
																				if (strcmp (orden, "modificar") == 0){
																					cout <<"\n ponga el elemento nuevo:   ";
																					cin>> auxnumero; cin.ignore();
																					cout <<"\n ahora ponga la Posicion a insertar:   ";
																					cin>> auxnumero2; cin.ignore();
																					if (auxnumero2 > longg (*&lista)){
																						cout <<"\n esa posicion No existe, la lista es mas pequena...";
																					}else{
																						modificar (auxnumero, *&lista, auxnumero2);
																					}
																				}else{
																					if (strcmp (orden, "borrar") == 0){
																						cout <<"\n ponga la posicion que va a borrar:   ";
																						cin>> auxnumero; cin.ignore();
																						if (auxnumero > longg (*&lista)){
																							cout <<"\n esa posicion No existe, la lista es mas pequena...";
																						}else{
																							borrar (auxnumero,*&lista);
																						}
																					}else{
																						if (strcmp (orden, "buscar") == 0){ // elemento es valor propio en si
																							cout <<"\n escriba el elemento que va a buscar (no posicion):   ";
																							cin>> auxnumero; cin.ignore();
																							auxnumero = buscar (auxnumero, lista);
																							cout <<"\n esta es la posicion en la que esta:   "<<auxnumero;
																						}else{
																							if (strcmp (orden, "prueba") == 0){
																								prueba (*&lista);
																							}else{
																								cout <<"\n No se ha entendido la orden...";
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
								}
							}
						}
					}
				}
			}
		}
	}
	
	cout <<"-------------------------fin del programa-----------------";
	cout <<"\n";
	return 0;
}
void imprimirx (Lista *&l){  // imprime la lista
	Nodo *aux = new Nodo ();
	aux = l->salida;
	cout <<"\n";
	while (aux != NULL){
		cout <<"   ---" <<aux->num;
		aux = aux->sig;
	}
	cout <<"\n ademas esta es su longitud:  "<<l->longitud;
}
Lista* corchetes (){  // esto crea una lista vacia
	Lista *prueba;
	prueba->entrada = NULL;
	prueba->salida = NULL;
	prueba->longitud = 0;
	return prueba;
}
void dospuntos (int x, Lista *&l){ // se añade por la izquierda de la lista
	Nodo *aux = new Nodo ();
	aux->num = x;
	aux->sig = l->salida;
	l->salida = aux;
	if (l->entrada == NULL){ // en el caso de que sea el primer elemento a insertar
		l->entrada = l->salida;
		cout <<"\n +++ ojo la entrada de la lista es nula... y se aplica que es la salida";
	}
	l->longitud++;
}
void resto  (Lista *&l){  // elimina el primero de la lista
	if (l->salida == NULL){  // en el caso de que este vacio
		cout <<"\n No se puede ELIMINAR por la izquierda, porque ya esta vacia";
	}else{
		l->salida = l->salida->sig;
		l->longitud--;
	}
	cout <<"\n se ha restado (+)";
}
void eult (Lista *&l){// elimina el ultimo
	Nodo *aux = new Nodo ();
	if (vacia (l) == 1){ // el caso en el que esta vacia
		cout <<"\n no se va a eliminar el ultimo, ya que esta vacia";
	}else{  
		l->longitud--;
		aux = l->salida;
		if (aux->sig == NULL){ // el caso en el que tenga solo 1
			l->salida = NULL;
			l->entrada = l->salida;
		}else{ // el caso en el que hay varios
			while (aux->sig->sig != NULL){
				aux = aux->sig;
			}
			aux->sig = NULL;
			l->entrada = aux;
		}
	}
}   
int prim (Lista *&l){
	int auxnumero = 0;
	if (l->salida == NULL){ // en el caso de que sea Nulo
		cout <<"\n no hay elementos en la lista";
		return NULL;
	}else{
		auxnumero = l->salida->num;
		return auxnumero;
	}
}
int ult (Lista *&l){
	int auxnumero = 0;
	if (l->salida == NULL){ // en el caso de que sea Nulo
		cout <<"\n no hay elementos en la lista";
		return NULL;
	}else{
		auxnumero = l->entrada->num;
		return auxnumero;
	}
}
bool vacia (Lista *&l){// ver s esta vacia
	bool verdad = false;
	if (l->salida == NULL){
		verdad = true;
	}
	return verdad;
}
//------------------------------------------------------------------------------------------------------------------------

Lista* corchetesespaciodentro (int x){  // crea una lista unitaria
	Lista *prueba = new Lista ();
	prueba->entrada = NULL;
	prueba->salida = NULL;
	prueba->longitud = 0;
	
	Nodo *aux = new Nodo ();
	aux->num = x;
	aux->sig = NULL;
	
	prueba->entrada = aux;
	prueba->salida = aux;
	prueba->longitud = 1;

	return prueba;
}
void hashh (int x, Lista *&l){  // añade elementos por la derecha
	Nodo *aux = new Nodo ();
	aux->num = x;
	aux->sig = NULL;
	
	if (l->salida == NULL){
		l->salida = aux;
	}else{
		l->entrada->sig = aux;
	}
	l->entrada = aux;
	l->longitud++;
}

Lista* masmas (Lista *&l, Lista *&m){ // el siguiente si ya el nodo es NULL, No existe
	if (l->salida == NULL){ // en el caso de que esta vacio
		l->salida = m->salida;
		l->entrada = m->entrada;
	}else{
		if (m->salida == NULL){
			// no se hace nada
		}else{
			l->entrada->sig = m->salida;
			l->entrada = m->entrada;
		}
	}
	l->longitud = l->longitud + m->longitud;
	return l;
}
int longg (Lista *&l){
	return l->longitud;
}
//--------------------------------------------------------.------------

int espaciocorchetes (int x, Lista *&l){ // devuelve el elemento que estaba en la posicion que  le pases por parametro
	int contador = 1;
	Nodo *aux = new Nodo ();
	aux = l->salida;
	while (contador < x){
		aux = aux->sig;
		contador++;
	}
	return aux->num;
}
void insertar (int x, Lista *&l, int y){// inseerta el elemento en la poscion indicada PROCEDMIENTO. (elemento,lista,natural)
	int contador = 1;	
	Nodo *aux = new Nodo ();
	Nodo *auxnuevo = new Nodo ();
	auxnuevo->num = x;
	auxnuevo->sig = NULL;
	aux = l->salida;
	if (y == 1){ // es como un añadir por la izquierda
		auxnuevo->sig = l->salida;
		l->salida = auxnuevo;
	}else{
		while (contador < y-1){
		aux = aux->sig;
		contador++;
		}
		auxnuevo->sig = aux->sig;
		aux->sig = auxnuevo;
	}
	l->longitud++;
}
void modificar (int x, Lista *&l, int y){// modifica el elemrento de la posocion indicada PROCEDIMIENTO
	int contador = 1;
	Nodo *aux  = new Nodo ();
	
	aux = l->salida;
	
	while (contador < y){
		aux = aux->sig;
		contador++;
	}
	aux->num = x;
}
void borrar (int x, Lista *&l){// borra el elemento de la posicion indicada PROCEDIMIENTO
	int contador = 1;
	Nodo *aux = new Nodo ();
	aux = l->salida;
	if (l->longitud == 1){
		l->salida = NULL;
		l->entrada = NULL;
	}else{
		if (x == 1){ // para el caso en el que se borra el primero
			l->salida = l->salida->sig;
			if (l->salida == NULL){
				l->entrada = NULL;
			}
		}else{
			while (contador < x-1){
				aux = aux->sig;
				contador++;
			}
			aux->sig = aux->sig->sig;
		}
	  }
	   l->longitud--;
}


bool esta (int x, Lista *&l){  // averigua si el elemento que se le pasa esta en la lista.
	bool verdad = false;
	Nodo *aux = new Nodo ();
	aux = l->salida;
	
	while (aux != NULL){
		if (aux->num == x){
			verdad = true;
		}
		aux = aux->sig;
	}
	return verdad;
}
int buscar (int x, Lista *&l){// devuelve la posicion en la que esta ese elemento que le paasas por parametro
	Nodo *aux = new Nodo ();
	aux = l->salida;
	int posicion = NULL;
	int contador = 1;
	if (esta (x,l) == 0){
		cout << "\n ESE ELEMENTO NO ESTA EN LA LISTA";
	}else{
		while (aux != NULL){
			if (x == aux->num){
				posicion = contador;
			}
			contador++;
			aux = aux->sig;
		}
	}
	return posicion;
}

void prueba (Lista *&l){
	if (vacia (l) == 1){
		cout <<"\n esto ya esta vacio... ";
	}else{
		if (l->salida->sig == NULL){
			l->salida;
			l->entrada;
		}else{
			Nodo *aux = new Nodo ();
			aux = NULL;
			aux  = l->salida;
			while (aux->sig->sig != NULL){
				aux = aux->sig;
			}
			aux->sig = NULL;
			l->entrada = aux;
			
		}
		l->longitud--;
	}
	cout <<"\n se ha borrado el ultimo ??";
}