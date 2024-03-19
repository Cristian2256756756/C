// Repas arrays amb el sarró del heroi.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;


int mostrarMenu() {
	int opcio;

	cout << R"(________________                                                     _________      ______       ______                       _____        
___  ____/___  /       ______________ _______________________        ______  /_____ ___  /       ___  /_ _____ ______________ ___(_)       
__  __/   __  /        __  ___/_  __ `/__  ___/__  ___/_  __ \       _  __  / _  _ \__  /        __  __ \_  _ \__  ___/_  __ \__  /        
_  /___   _  /         _(__  ) / /_/ / _  /    _  /    / /_/ /       / /_/ /  /  __/_  /         _  / / //  __/_  /    / /_/ /_  /         
/_____/   /_/          /____/  \__,_/  /_/     /_/     \____/        \__,_/   \___/ /_/          /_/ /_/ \___/ /_/     \____/ /_/    )" << '\n';

	cout << endl;
	cout << "! ! ! !Bienvenido al juego del heroi ! ! ! !" << '\n';
	Sleep(1500);
	cout << endl;
	cout << "1. Guardar objetos en el inventario " << endl;
	cout << "2. Letras" << endl;
	cout << "3. Te encuentras un objeto por el camino, que sera? " << endl;
	cout << endl;
	cout << " Escoge la opcion deseada: ";
	cin >> opcio;
	return opcio;

}

int main()
{

	srand(time(NULL));
	string inventari[10];
	int numeroaleatorio = rand() % 100;
	int cantidad;
	int objetos;
	int nombre;
	int opcion; 

	opcion = mostrarMenu();

	while (opcion!=4) {

		switch (opcion) {
	
		case 1: {

			cout << "Cuantos items quieres introducir? " << '\n';
			cin >> objetos;
			
			if (objetos >= 0 && objetos < 10) {
				cout << "Hazme una lista de todas las armas que quieres añadir en tu inventario: " << '\n';
				cin >> inventari[objetos];

				cout << "Objetos ingresados en el inventario";
			}
			else {
				cout << " r";
			}
			break;
		}
		case 2: {

			cout << " r";
			break;
		}

		case 3: {

			cout << "You find " << numeroaleatorio << " healing potions";
			break;
		}


		}
		opcion = mostrarMenu();

	}
		return 0; 

}
