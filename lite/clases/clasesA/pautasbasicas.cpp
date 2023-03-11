
// este sera el archivo de pautas basicas para C++.

//1) la declaracion de TODAS las variables y las variables enumeradas, las voy a hacer en la
//cabezera del script. Esto lo he sacado de Ada.
//2)cuando busque un resultado importante de la ejecucion de un programa, se imprimira por pantalla de la
//siguiente forma: "+++se ha acertado el numero+++, "+++la variable totalIntentos vale: 8+++".
//3) las variables se escriben al principio en minuscula. ejemplo: totalIntentos = 0;
//4) el nommbre de las clases siempre con Mayuscula al principio. ejemplo: Test2.
//5) si tengo alguna duda sobre el script, lo pondre como comentario en la primera linea de este.



#include <iostream>

using namespace std;

int contadorAle = -1;  //esto hace falta, ya que en C++ crear aleatorios, es algo que no es sencillo.

int azar (int x){
	int numero;
	srand(time(NULL));
	if (contadorAle == -1){
		contadorAle = rand()%100;

	}else{
		contadorAle = contadorAle + 1;
	}
	srand (contadorAle);
	numero =rand ()%x;
	return numero;
}

int main() {
	bool verdad = true;
	int numeroMio = 0;
	int numeroAleatorio = 0;
	int totalIntentos = 0;
	int rangoAleatorio = 0;
	bool acertadoAleatorio = false;
	int intentosLlevados = 0;


	cout << "\n--- se ejecuta pautas basicas de C++  ---";
	cout << "\n--- escriba el rango del numero aleatorio:   ";
	cin >> rangoAleatorio;
	cout << "\n ---ahora escriba el numero de intentos que quiere:   ";
	cin >> totalIntentos;

	numeroAleatorio = azar (rangoAleatorio);

	intentosLlevados = 0;

	while (verdad == true){
		intentosLlevados = intentosLlevados + 1;
		cout << "\nescriba el numero:   "; cin >> numeroMio;

		if (numeroMio == numeroAleatorio){
			cout << "\nHas acertado el Numero. ";
			verdad = false;
			acertadoAleatorio = true;
		}else{
			if (numeroMio > numeroAleatorio){
				cout << "\nte has pasado";
			}else{
				cout << "\nte has quedado corto. ";

			}
		}
		if (intentosLlevados >= 10){
			verdad = false;
		}else{
			cout << "\nllevas:   "<<intentosLlevados;
		}
	}
	if (acertadoAleatorio == true){
		cout << "\nhas acertado el numero";
	}else{
		cout << "\nno has acertado el número al final, te has pasado de intentos. ";
	}

	cout << "\n";
	return 0;
}
