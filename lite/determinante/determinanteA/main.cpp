
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int contadorAle = -1;
int azar (int x);

void pedir ();
void imprimir (int a, int **b);
int suma (int a, int **b);
int determinante (int a, int **b);

int sumaVector (int a, int *b);

int grado;
int **matriz;

int main (){
	cout <<"\n  comienza el programa";
	
	
	 pedir();
	 imprimir (grado, matriz);
	 int total = 0;
	 total = suma (grado, matriz);
	 cout <<"\n esta es la suma de todos los elementos:   "<<total;
	 
	 int deter = 0;
	 deter = determinante (grado, matriz);
	 cout <<"\n este es el valor del determinante:   "<<deter;
	
	cout <<"\n";
	return 0;
}

int sumaVector (int a, int *b){
    int total = 0;
    
    for (int i = 0; i < a; i++){
        total = total + b[i];
    }
    return total;
}

int determinante (int a, int **b){
    int total = 0;
    int fila = 0;
    int columna = 0;
    int *v;
    v = new int [a]; // creado vector que recibe cada uno de los producos hechos, los cuales luego se suman
    for (int l = 0; l < a; l++){
        v[l] = 0;
    }
    int ladoA = 0;
    int ladoB = 0;
    
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            v[i] = v[i] + *(*(b+fila)+columna);
            
            fila++;
            columna++;
            
            if (fila == a){
                fila = 0;
            }
          
        }
        fila = i;
        columna = 0;
    }
    
    //cout <<"\n  --"<<v[0] <<"--" <<v[1] <<"--" <<v[2];
    
    ladoA = sumaVector (a,v);
    for (int k = 0; k < a; k++){
        v[k] = 0; 
    } // se inicializa a cero el vector otra vez
    
    fila = a-1;
    columna = a-1;
    
    for (int n = 0; n < a; n++){
        for (int m = 0; m < a; m++){
            v[n] = v[n] + *(*(b+fila)+columna);
            fila--;
            columna--;
            
            if (fila == -1){
                fila = a-1;
            }
            
        }
        fila = a-n-1;
        columna = a-1;
    }
    
    //cout <<"\n  --"<<v[0] <<"--" <<v[1] <<"--" <<v[2];
    //cout <<"\n valor del Lado B:  "<<ladoB;
    ladoB = sumaVector (a,v);
    total = ladoA - ladoB;
    
    return total;
}

int suma (int a, int **b){
	int total = 0;
	
	for (int i = 0; i < a; i++){
		for (int j = 0; j < a; j++){
			total = total + *(*(b+i)+j);
		}
	}
	
	return total;
}

void imprimir (int a, int **b){
	
	cout <<"\n";
	for (int i = 0; i < a; i++){
		for (int j = 0; j < a; j++){
			cout <<" / " <<*(*(b+i)+j);
		}
		cout <<"\n";
	}
	
	cout <<"\n se ha imperso (/)";
}

void pedir(){
	cout <<"\n ponga el grado del daterminante:   ";
	cin >>grado; cin.ignore ();
	
	matriz = new int *[grado];
	
	for (int i = 0; i < grado; i++){
		matriz[i] = new int [grado];
	}
	
	for (int i = 0; i < grado; i++){
		for (int j = 0; j < grado; j++){
			*(*(matriz+i)+j) = azar (100);
		}
	}
	cout <<"\n se han insertado los datos (+)";
}

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