#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>

using namespace std;

struct Nodo{
	int numero;
	Nodo *sig;
};
struct Pila {
	Nodo *nodo;
};
struct Cola{
		Nodo *entrada;
		Nodo *salida;
};
struct Lista{
	Nodo *entrada;
	Nodo *salida;
	int longitud;
};

void imprimirp (Pila *&a);
void imprimirc (Cola *&a);
void imprimirl (Lista *&a); 

void apilar (int x, Pila *&a);
void encolar  (int x, Cola *&a);
void  dospuntos  (int x, Lista *&a); 
void hashh (int x, Lista *&a);


int main(int argc, char **argv)
{
	printf("hello world\n");
	
	
	Pila *p = new Pila ();
	p->nodo = NULL;
	
	Cola *c = new Cola ();
	c->entrada = NULL;
	c->salida = NULL;
	
	Lista *l = new Lista ();
	l->entrada = NULL;
	l->salida = NULL;
	l->longitud = 0;
	
	apilar (4,p);
	apilar (5,p);
	apilar (6,p);
	apilar (7,p);
	imprimirp (p);
	
	encolar (4,c);
	encolar (5,c);
	encolar (6,c);
	encolar (7,c);
	imprimirc (c);
	
	dospuntos (4, l);
	dospuntos (5, l);
	dospuntos (6, l);
	dospuntos (7, l);
	hashh(8,l);
	imprimirl (l);
	
	cout <<"\n";
	return 0;
}

void apilar (int x, Pila *&a){
	Nodo *aux = new Nodo ();
	aux->numero = x;
	aux->sig = a->nodo;
	a->nodo = aux;
}
void encolar  (int x, Cola *&a){
	Nodo *aux = new Nodo ();
	aux->numero = x;
	aux->sig = NULL;
	
	if (a->salida == NULL){
		a->salida = aux;
	}else{
		a->entrada->sig = aux;
	}
	a->entrada = aux;
}

void  dospuntos  (int x, Lista *&a){
	Nodo *aux = new Nodo ();
	aux->numero = x;
	aux->sig = a->salida;
	a->salida = aux;
	
	if (a->entrada == NULL){
		a->entrada = a->salida;
		//cout <<"\n ojo porque la entrada de la lista estaba vacia, y se aplica que es igual a la salida";
	}
	a->longitud++;
}

void hashh (int x, Lista *&a){
	Nodo *aux = new Nodo ();
	aux->numero = x;
	aux->sig = NULL;
	if (a->salida == NULL){
		a->salida = aux;
	}else{
		a->entrada->sig = aux;
	}
	a->entrada = aux;
}
void imprimirp (Pila *&a){
	Nodo *aux = new Nodo ();
	aux = a->nodo;
	cout <<"\n (pila) ENTRADA DATOS////";
	while (aux != NULL){
		cout <<"   ---"<<aux->numero;
		aux = aux->sig;
	}
}
void imprimirc (Cola *&a){
	Nodo *aux = new Nodo ();
	aux = a->salida;
	cout <<"\n";
	while (aux != NULL){
		cout <<"   ---"<<aux->numero;
		aux = aux->sig;
	}
	cout <<"   ////ENTRADA DE DATOS (cola)";
}
void imprimirl (Lista *&a){
	Nodo *aux = new Nodo ();
	aux = a->salida;
	cout <<"\n (lista) principio de la lasita ///";
	while (aux != NULL){
		cout <<"   ---" <<aux->numero;
		aux = aux->sig;
	}
	cout <<"\n ademas esta es su longitud:   "<<a->longitud;	
}