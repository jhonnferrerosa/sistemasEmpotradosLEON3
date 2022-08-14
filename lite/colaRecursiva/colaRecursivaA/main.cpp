
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

struct Persona{
    
};


struct Nodo{
    int num;
    Nodo *sig;
};

void mas (int x, Nodo *&a);
void menos (Nodo *&a);
void imprimir (Nodo *&a);
void vaciar (Nodo *&a);

int main(int argc, char** argv) {
    
    Nodo *cola;
    
    
    bool verdad = true;
    char pala[20];
    int numero = 0;
    
    
    
    while (verdad == true){
        cout <<"\n ponga la Orde:  ";
        cin.getline(pala,20,'\n');
        
        if (strcmp (pala, "mas") == 0){
            cout <<"introduzca el Numero:  ";
            cin >>numero; cin.ignore();
            mas (numero, cola);
        }else{
            if (strcmp (pala, "menos") == 0){
                menos (cola);
            }else{
                if (strcmp (pala, "imprimir") == 0){
                    imprimir (cola);
                }else{
                    if (strcmp (pala,"vaciar") == 0){
                        vaciar (cola);
                    }else{
                        verdad = false;
                    }
                }
            }
        }
    }
    
    cout <<"\n  +++ FIN del programa ++++";

    return 0;
}

void vaciar (Nodo *&a){
    
    while (a != NULL){
        a = a->sig;
    }
    cout <<"\n Se ha Vaciado !!!";
}

void imprimir (Nodo *&a){
    Nodo *aux = new Nodo ();
    aux = a;
    cout <<"\n";
    while (aux != NULL){
        cout <<aux->num <<"---";
        aux = aux->sig;
    }
    
}

void menos (Nodo *&a){
    a = a->sig;
    cout <<"\n se ha quitado...  ";
}

void mas (int x, Nodo *&a){
    Nodo *aux = new Nodo ();
    aux->num = x;
    
    if (a == NULL){
        a = aux;
    }else{
        mas (x, a->sig);
    }
}
