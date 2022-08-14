#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;
void dormir ();

int main(int argc, char *argv[]){
    
    cout <<"\n ponga  cuantas veces quiere dormir:   ";
    int a = 0;
    cin >>a; cin.ignore();
    
    int contador = 0;
    for (int i = 0; i < a; i++){
        cout <<"\n este es el contador:  "<<contador;
        contador = contador + 2;
        dormir();
    }
    
	cout <<"\n";
    return 0;
}

void dormir (){
    
    try{
        Sleep (3000);
    }catch (int){
        
    }
    
}
