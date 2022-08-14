#include <cstdlib>
#include <iostream>

//cabezera, metodos , mainn

using namespace std;


class Persona{
private:
    int edad;
    string nombre;
public:
    Persona (int a, string b);
    
    void leer ();
    void saltar ();
        
};
// constructor
Persona::Persona (int a, string b){
    edad = a;
    nombre = b;
}

//metodos
void Persona::leer (){
    cout <<"\n  soy:  "<<nombre  <<"   y esta  es mi edad:   "<<edad <<"  y estoy LEYENDO";
}

void Persona::saltar(){
    cout <<"\n "<<nombre <<"   , " <<edad <<"  edad, Salta";
}


int main(int argc, char** argv) {

    cout <<"\n se crea una persona...";
    Persona p = Persona (20,"ana");
    p.saltar();
    p.leer();
    
    
    cout <<"\n  se crea una persona...";
    Persona q = Persona (22,"sara");
    q.leer();
    q.saltar();
    
    
    return 0;
}

