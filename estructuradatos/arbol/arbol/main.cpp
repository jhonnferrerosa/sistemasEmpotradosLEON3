#include <cstdlib>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <time.h>

using namespace std;

struct Nodo {
    int num;
    Nodo *der;
    Nodo *izq;
};

struct NodoA{
	int num;
	NodoA *sig;
};

struct Lista{
	NodoA *entrada;
	NodoA *salida;
	int longitud;
};

Nodo* arbol_vacio ();
Nodo* crea_arbol (int x, Nodo *&i, Nodo *&d );
int raiz (Nodo *&a);
Nodo *izq (Nodo *&a);
Nodo *der (Nodo *&a);
bool vacio (Nodo *&a);
int altura (Nodo *&a);

Lista *preorden (Nodo *&a);
Lista *inorden (Nodo *&a);
Lista *postorden (Nodo *&a);

void mas(int x, Nodo *&a);
bool esta (int x, Nodo *&a);
int maximo (Nodo *&a);
void borrar (int x, Nodo *&a);


void masm (Nodo *&a); // añadir pero con aleatorio
void imprimir (int x, Nodo *&a);
int maximoNat(int a, int b);
Nodo *igualar_arbol (int x, Nodo *&a);
void imprimirx (Lista *&l);
void  hashh  (int x, Lista *&l);  // añade por derecha  PROCEDMIENTO
Lista* masmas (Lista *&l, Lista *&m);  /// concatenar 2 listas
void  dospuntos (int x, Lista *&l); // añade por zquierda ,  PROCEDIMEINTO

int numhojas (Nodo *&a);
bool potencias (Nodo *&a); // si el numero deo hojas no cuadra con el num de hojas de un completo, bool = false
bool escompleto (Nodo *&a);

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


int main(int argc, char** argv) {

    cout << "\n hooola";
    Nodo *arbol = NULL;
	Nodo *arbolaux = NULL;
	
	Lista *lista = new Lista ();  
	lista->entrada = NULL;
	lista->salida = NULL;
	lista->longitud = 0;
	
	
	char palabra[20];
	int numero = 0;
	bool verdad = true;
	bool verdadaux = true;
	
	while (verdad == true){
		cout <<"\n ponga la orden:   ";
		cin.getline (palabra,20,'\n');
		
		if (strcmp(palabra,"mas") == 0){
			cout<< "\n escriba el numero:  ";
			cin>> numero; cin.ignore();
			mas (numero,arbol);
			imprimir (0,arbol);
		}else{
			if (strcmp(palabra, "salir") == 0){
				cout<<"\n se ha salido del programa...";
				break;
				
			}else{
				if (strcmp (palabra, "imp") == 0){
					imprimir (0,arbol);
				}else{
					if (strcmp (palabra, "ls") == 0){
						cout<< "\n este es el listado de las ordenes:    ls, mas(), masm, masmx,  imp, esta(), salir, ,maximo, borrar(), raiz, vacio, altura, igualar_arbol, inorden, postorden, preorden, numhojas";
						cout <<"\n escompleto";
					}else{
						if (strcmp(palabra, "esta") == 0){
							cout<< "\n escriba el numero que BUSCA:   ";
							int numerobusca = 0;
							cin>> numerobusca; cin.ignore();
							verdadaux = esta (numerobusca, arbol);
						}else{
								if (strcmp(palabra, "masm") == 0){
									masm(arbol);
								}else{
									if (strcmp(palabra, "masmx") == 0){
										mas (50,arbol);
										mas (70,arbol);
										mas (20,arbol);
										mas (10,arbol);
										mas (30,arbol);
										mas (60,arbol);
										mas (80,arbol);
										mas (90,arbol);
										mas (5,arbol);
										mas (15,arbol);
										mas (100,arbol);
										mas (85,arbol);
										mas (65,arbol);
										mas (55,arbol);
										mas (13,arbol);
										mas (58,arbol);
									}else{
										if (strcmp (palabra, "maximo") == 0){
											numero = maximo (arbol);
											cout <<"\n este es el valor maximo del arbol:  "<<numero;
										}else{
											if (strcmp (palabra, "borrar") == 0){
												cout <<"\n escriba el elemento que va a borrar:   ";
												cin>> numero; cin.ignore();
												borrar (numero, arbol);
												cout <<"\n";
												imprimir (0, arbol);
											}else{
												if (strcmp (palabra, "raiz") == 0){
													numero = raiz (arbol);
													cout <<"\n esta es la raiz del arbol:   "<<numero;
												}else{
													if (strcmp (palabra, "vacio") == 0){
														verdadaux = vacio (arbol);
														cout <<"\n esta es la respuesta de si esta vacio:  "<<verdadaux;
													}else{
														if (strcmp (palabra, "altura") == 0){
															numero = altura (arbol);
															cout <<"\n esta es la altura del arbol:   "<<numero;
														}else{
															if (strcmp (palabra, "igualar_arbol") == 0){
																cout <<"\n escriba el elmento del cual quiere hacer un nuevo arbol:   ";
																cin>> numero; cin.ignore();
																arbolaux = igualar_arbol(numero, arbol);
																cout <<"\n se va a imprimir el arbolmauxiliar:   \n";
																imprimir (0, arbolaux);
															}else{
																if (strcmp(palabra, "inorden") == 0){
																	lista = inorden (arbol);
																	imprimirx (lista);
																}else{
																	if (strcmp (palabra, "preorden") == 0){
																		lista = preorden (arbol);
																		imprimirx (lista);
																	}else{
																		if (strcmp (palabra, "postorden") == 0){
																			lista = postorden (arbol);
																			imprimirx (lista);
																		}else{
																			if (strcmp (palabra, "numhojas") == 0){
																				numero = numhojas (arbol);
																				cout <<"\n este es el numero de hojas que tiene:  "<<numero;
																			}else{
																				if (strcmp(palabra, "escompleto") == 0){
																					verdadaux = escompleto (arbol);
																					cout <<"\n resultado de si es completo:   "<<verdadaux;
																				}else{
																					cout<< "\n no se ha entendido la orden... ";
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
		
	
	
	
    
    int contador = 0;
    cout <<"\n";
    imprimir (contador,arbol);
    

    cout <<"\n+++++++++++++++++++ fin del programa  ++++++++++++++++++++++++";
    cout << "\n";
    return 0;
}

Nodo *arbol_vacio(){
	Nodo *arbol = new Nodo ();
	arbol = NULL;
	return arbol;
}

Nodo *crea_arbol (int x, Nodo *&i, Nodo *&d){
	Nodo *arbol = new Nodo ();
	arbol->num = x;
	arbol->der = d;
	arbol->izq = i;
	return arbol;
}

int raiz (Nodo *&a){
	if (a == NULL){
		cout <<"\n error arbol vacio";
		return NULL;
	}
	return a->num;
}

Nodo *der(Nodo *&a){
	if (a == NULL){
		cout <<"\n error arbol vacio";
		return NULL;
	}
	return a->der;
}

Nodo* izq (Nodo *&a){
	if (a == NULL){
		cout <<"\n error arbol vacio";
	}
	return a->izq;
}

bool  vacio (Nodo *&a){
	bool verdad = true;
	if (a != NULL){
		verdad =false;
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
				alt = 1 + maximoNat(altura(a->izq), altura(a->der));
			}
		}
	}
}
int maximoNat (int a, int b){
	if (a > b){
		return a;
	}else{

		return b;
	}
}
void imprimir (int x, Nodo *&a){    
    if (a == NULL){
        return; 
    }else{
        imprimir (x+1,a->der);
        for (int i = 0; i < x; i++){
            cout <<"       ";
        }
        cout <<a->num;
        cout <<"\n";
        imprimir (x+1, a->izq);
    }
    
}

bool esta (int x, Nodo *&a){
    bool verdad;
    if (a == NULL){
        cout <<"\n el Numero No esta...";
		verdad = false;
    }else{
        if (x == a->num){
            cout <<"\n si esta,   ehhhhhh???";
			verdad = true;
        }else{
            if (x > a->num){
                verdad = esta (x,a->der);
            }else{
                verdad = esta (x, a->izq);
            }
        }
    }
	return verdad;
}
void mas (int x, Nodo *&a){
    
    if (a == NULL){
        a = new Nodo ();
        a->num = x;
        a->izq = NULL;
        a->der = NULL;
    }else{
        if (x > a->num){
            mas (x,a->der);
        }else{
            if (x < a->num){
                mas (x, a->izq);
            }else{
                cout <<"\n ese Numero ya esta en el arbol";
            }
        }
    }
}

void masm (Nodo *&a){
    
	int x = azar (100);
    if (a == NULL){
        a = new Nodo ();
        a->num = x;
        a->izq = NULL;
        a->der = NULL;
    }else{
        if (x > a->num){
            mas (x,a->der);
        }else{
            if (x < a->num){
                mas (x, a->izq);
            }else{
                cout <<"\n ese Numero ya esta en el arbol";
            }
        }
    }
}

int maximo (Nodo *&a){
	if (a == NULL){
		cout <<"\n el arbol esta vacio...";
		return 0;
	}else{
		if (a->der == NULL){
			return a->num;
		}else{
			return maximo (a->der);
		}
	}
}

void borrar (int x, Nodo *&a){
	cout <<"\n se va a borrar:  "<<x;
	if (a == NULL){
		cout <<"\n error arbol vacio... ";
	}else{
		if (x == a->num){ // lo ha encontrado 
		cout <<"\n lo he encontrado";
			if ((a->der == NULL) && (a->izq == NULL)){
				a = NULL;
				//cout <<"\n se ha borrado la hoja";
			}else{
				if (a->izq == NULL){
					a = a->der;
				}else{
					if (a->der == NULL){
						a = a->izq;
					}else{
						int m = maximo (a->izq);
						//cout <<"\n este es el maximo:   "<<m;
						borrar (m, a->izq);
						a->num = m;
					}
				}
			}
		}else{  // si no lo he encontrado, sigo buscando
			if (x < a->num){
				borrar (x, a->izq);
			}else{
				borrar (x, a->der);
			}
		}
	}
}

Nodo *igualar_arbol (int x, Nodo *&a){ // esta funcion lo que haces es que una vez haya encontrado un elemento que se le pase porparametro, cree un arbol de este. 
	Nodo *aux = new Nodo ();
	if (a == NULL){
		return NULL;
	}else{
		if (x == a->num){
			aux = a;
		}else{
			if (x > a->num){
				aux = igualar_arbol (x, a->der);
			}else{
				aux = igualar_arbol (x, a->izq);
			}
		}
	}
	return aux;
}

Lista *preorden (Nodo *&a){
	Lista *l = new Lista ();
	l->entrada = NULL;
	l->salida = NULL;
	l->longitud = 0;
	if (a == NULL){
		return l;
	}else{
		dospuntos (a->num, l);
		Lista *laux = new Lista (); laux->entrada = NULL; laux->salida = NULL; laux->longitud = 0;
		laux = preorden (a->izq);
		l = masmas (l, laux);
		laux = new Lista (); laux->entrada = NULL; laux->salida = NULL; laux->longitud = 0;
		laux = preorden (a->der);
		l = masmas (l, laux);
	}
	return l;
}
Lista *inorden (Nodo *&a){
	Lista *l = new Lista ();
	l->entrada = NULL;
	l->salida = NULL;
	l->longitud = 0;
	if (a == NULL){
		return l;
	}else{
		l = inorden (a->izq);
		hashh (a->num, l);
		//cout <<"\n valor insertado:   "<<l->entrada->num;
		Lista *laux = new Lista (); laux->entrada = NULL; laux->salida = NULL; laux->longitud = 0;
		laux = inorden (a->der);
		l = masmas (l, laux); // veo que las funciones no aceptan valores que no son previamene declarados
	}
	return l;
}
Lista *postorden (Nodo *&a){
	Lista *l = new Lista ();
	l->entrada = NULL;
	l->salida = NULL;
	l->longitud = 0;
	if (a == NULL){
		return l;
	}else{
		l = postorden (a->izq);
		Lista *laux = new Lista (); laux->entrada = NULL; laux->salida = NULL; l->longitud = 0;
		laux = postorden (a->der);
		l = masmas (l, laux);
		hashh (a->num, l);
	}
	return l;
}

void imprimirx (Lista *&l){  // imprime la lista
	NodoA *aux = new NodoA ();
	aux = l->salida;
	cout <<"\n";
	while (aux != NULL){
		cout <<"   ---" <<aux->num;
		aux = aux->sig;
	}
	cout <<"\n ademas esta es su longitud:  "<<l->longitud;
}

void hashh (int x, Lista *&l){  // añade elementos por la derecha
	//cout <<"\n se va a inserter:  "<<x;
	NodoA *aux = new NodoA ();
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

void dospuntos (int x, Lista *&l){ // se añade por la izquierda de la lista
	NodoA *aux = new NodoA ();
	aux->num = x;
	aux->sig = l->salida;
	l->salida = aux;
	if (l->entrada == NULL){ // en el caso de que sea el primer elemento a insertar
		l->entrada = l->salida;
		//cout <<"\n +++ ojo la entrada de la lista es nula... y se aplica que es la salida";
	}
	l->longitud++;
}

int numhojas (Nodo *&a){ // cuenta el numero de hojas de un arbol
	int total = 0;
	
	if (a == NULL){
		total = 0;
	}else{
		if ((a->izq == NULL) && (a->der == NULL)){
			total = 1;
		}else{
			total = total + numhojas(a->izq) + numhojas(a->der);
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