#include <cstdlib>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <time.h>

using namespace std;

struct Arbol;

struct Bosque{
	int longitud;
	Arbol *inicio;
};


struct Arbol {
	int elemento;
	Arbol *primerhijo;
	Arbol *siguiente;
};

Arbol* mas (int x, Bosque *&b);  // devuelve arbol, creando un nuevo arbol con el elementos que le pasemos y como bosque el bosque que le pasemos
void anadir_arbol (Arbol *&a, Bosque *&b); // devuelve bosque con el arbol que le pasemos

void imprimir (Arbol *&a);
void imprimirbosque (Bosque *&b);

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
	
	Arbol *arbol = new Arbol ();
	arbol->elemento = 9000;
	arbol->siguiente = NULL;
	arbol->primerhijo = NULL;
	
	Bosque *bosque = new Bosque ();
	bosque = NULL;
	
	Arbol *auxarbol = new Arbol ();
	auxarbol->elemento = 5000;
	auxarbol->siguiente = NULL;
	auxarbol->primerhijo = NULL;
	arbol->siguiente = auxarbol;	
	
	Arbol *auxarbol1 = new Arbol ();
	auxarbol1->elemento = 6000;
	auxarbol1->siguiente = NULL;
	auxarbol1->primerhijo = NULL;
	arbol->siguiente->siguiente = auxarbol1;	
	
	Arbol *auxarbol2 = new Arbol ();
	auxarbol2->elemento = 7000;
	auxarbol2->siguiente = NULL;
	auxarbol2->primerhijo = NULL;
	arbol->siguiente->siguiente->siguiente = auxarbol2;
	
	
	Arbol *auxarbol3 = new Arbol ();
	auxarbol3->elemento = 8000;
	auxarbol3->siguiente = NULL;
	auxarbol3->primerhijo = NULL;
	arbol->siguiente->siguiente->siguiente->siguiente = auxarbol3;
	
	Arbol *auxiliar = new Arbol (); // este arbol sera el que se utilize para la creacion de nuevos bosques
	auxiliar->elemento = 500;
	auxiliar->primerhijo = NULL;
	auxiliar->siguiente  = NULL;
	
	Arbol *aux1 = new Arbol ();
	aux1->elemento = 600;
	aux1->primerhijo = NULL;
	aux1->siguiente = NULL;
	auxiliar->siguiente = aux1;	
	
	Arbol *aux2 = new Arbol ();
	aux2->elemento = 600;
	aux2->primerhijo = NULL;
	aux2->siguiente = NULL;
	auxiliar->siguiente->siguiente = aux2;
	
	Arbol *aux3 = new Arbol ();
	aux3->elemento = 600;
	aux3->primerhijo = NULL;
	aux3->siguiente = NULL;
	auxiliar->siguiente->siguiente->siguiente = aux3;	
	
	Arbol *aux4 = new Arbol ();
	aux4->elemento = 600;
	aux4->primerhijo = NULL;
	aux4->siguiente = NULL;
	auxiliar->siguiente->siguiente->siguiente->siguiente = aux4;
	
	arbol->primerhijo = auxiliar;
	
	
	bool verdad = true;
	int numero = 0;
	char orden[20];
	int numeroSacado = 0;
	int auxnumero;
	bool auxbool;
	int auxnumero2;
	
	
	
	while (verdad == true){
		cout <<"\n escriba la orden:  ";
		cin.getline(orden, 20, '\n');
		
		if (strcmp (orden, "ls") == 0){
			cout <<"\n este es el listado de ordenes: salir, mas, imp1, imp2,  anadir_arbol";
		}else{
			if (strcmp (orden, "salir") == 0){
				verdad = false;
			}else{
				if (strcmp (orden, "mas") == 0){
					cout <<"\n escriba el numero a insertar:  ";
					cin>> auxnumero; cin.ignore();
					arbol = mas (auxnumero, bosque);
				}else{
					if (strcmp (orden, "imp1") == 0){
						imprimir (arbol);
					}else{
						if (strcmp (orden, "anadir_arbol") == 0){
							cout<<"\n escriba el numero a insertar:  ";
							cin>> auxnumero; cin.ignore();
							auxarbol->elemento = auxnumero;
							auxarbol->primerhijo = NULL;
							auxarbol->siguiente = NULL;
							anadir_arbol (auxarbol, bosque);
						}else{
							if (strcmp (orden, "imp2") == 0){
								imprimir (auxiliar);
							}else{
								cout <<"\n no se ha entendid la orden...";
							}
						}
					}
				}
			}
		}
	}
	
    cout <<"\n+++++++++++++++++++ fin del programa  ++++++++++++++++++++++++";
    cout << "\n";
	return 0;
}

Arbol* mas (int x, Bosque *&b){  // se inserta un arbol por arriba
	Bosque *aux = new Bosque ();
	aux->inicio = NULL;
	aux->longitud = 0;
	if (b == NULL){
		b = aux;
	}
	Arbol *a = new Arbol ();
	a->elemento = x;
	a->primerhijo = NULL;;
	a->siguiente = NULL;
	return a;
	
}

//¿como se añade un solo hermano????

void imprimir (Arbol *&a){
	cout <<"\n se va a imprimir ";
	Arbol *aux = new Arbol ();
	aux = a;
	if (aux == NULL){ // si este arbol es NULO, acaba aqui la funcion. 
		return;
	}
	
	cout <<"\n +++" <<a->elemento;
	while (aux->siguiente != NULL){
		cout <<"   ---"<<aux->siguiente->elemento;
		aux->siguiente = aux->siguiente->siguiente;
	}
	
	cout <<"\n";
	aux = aux->primerhijo;
	if (aux == NULL){
		return;
	}else{
		imprimir (aux);
	}


	cout <<"\n se ha impreso (*)";
}


void imprimirbosque (Bosque *&b){
	if (b == NULL){
		cout <<"\n el bosque no tiene nada, no se imprime";
	}else{
		imprimir (b->inicio);
	}
}

void anadir_arbol (Arbol *&a, Bosque *&b){
	a->siguiente = b->inicio;
	b->inicio = a;
	b->longitud++;
}