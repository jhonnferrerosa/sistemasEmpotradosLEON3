#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
#include <windows.h>

// ya que se supone que no vas a trabajar mas con  c++, hazlo todo a partir de este programa con Nodos

using namespace std;     /////  plila.Nodo->persona  ///  los datos a los que se accede desntro de los Nodos,  se hace  con flechas

class Persona{
private:
	int edad;
	string nombre;
public:

	Persona (){
		nombre = "vacio";
		edad = 0;
	}

	void setEdad (int x){
		edad = x;
	}
	
	void setNombre(string y){
		nombre = y;
	}
	
	int getEdad (){
		return edad;
	}
	
	string getNombre(){
		return nombre;
	}
};

struct Nodo {
	Persona per;
	Nodo *sig;
};

class Pila{ // lo  que es la clase pila en si,  solo puede cotener los Nodos, pues sera lo que se va a modifiacar dentro de las funciones
public:
	Nodo *enlace;
	int numero;
public:
	Pila (){
		enlace = NULL;
		numero = -1;
	}
	
};

void mas (int x, Pila &a);
void menos (Pila &a);
void imprimir (Pila &a);
void vaciar (Pila &a);


int main(){
	
	Pila clientes = Pila();
	
	
	char palabra[20];
	int numero = 0;
	bool verdad = true;
	
	while (verdad == true){
		cout <<"\n escriba la orden:     ";
		cin.getline (palabra, 20, '\n');
		
		if (strcmp (palabra, "mas") == 0){
			 cout <<"ponga el numero que desea:     ";
			 cin >> numero; cin.ignore();
			 mas (numero, clientes);
		}else{
			if (strcmp (palabra, "menos") == 0){
				menos (clientes);
			}else{
				if (strcmp (palabra, "imprimir") == 0){
					imprimir (clientes);
				}else{
					if (strcmp (palabra, "vaciar") == 0){
						vaciar (clientes);
					}else{
						if (strcmp (palabra, "salir") == 0){
							verdad = false;
						}else{
							cout <<"\n   No se ha entendido la Orden.....";
						}
					}
				}
			}
		}
	}
	
	
	cout <<"\n";
	return 0;
}

void vaciar (Pila &a){
	
	if (a.enlace == NULL){
		cout <<"\n  ya esta vacio, No  se puede vaciar.";
		return;
	}else{
		
		while (a.enlace != NULL){
			a.enlace = a.enlace->sig;
		}
		cout <<"\n se ha vaciado.";
	}
}

void imprimir (Pila &a){
	if (a.enlace == NULL){
		cout <<"\n  no se imprime, los  clientes,  ya estan  vacios";
		return;
	}else{
		Nodo *aux = new Nodo ();
		aux = a.enlace;
		
		cout <<"\n";
		while (aux != NULL){
			cout <<"     +"<<aux->per.getEdad();
			aux = aux->sig;
			try{
				Sleep (200);
			}catch (int z){}
		}
		cout <<"\n  se ha impreso";
	}
}

void menos (Pila &a){
	
	if (a.enlace == NULL){
		cout <<"\n los  clientes,  ya estan vacios....";
		return;
	}else{
		a.enlace = a.enlace->sig;
		cout <<"\n se ha restado";
	}
}

void mas (int x, Pila &a){
	Nodo *aux = new Nodo ();
	aux->per.setEdad(x);
	aux->sig = a.enlace;
	
	a.enlace = aux;
	cout <<"\n se ha sumado (+)";
}