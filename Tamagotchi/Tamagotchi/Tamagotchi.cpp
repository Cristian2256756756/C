#include <iostream>                                                                    //Incluimos la libreria de iostream para poder hacer las entradas y salidas
#include "Mascota.h"                                                                   //Incluimos el .h de Mascota.h para que pueda coger todos los datos y variables del documento y sea mas facil de llegar
#include "Farm.h"                                                                      //Incluimos el .h del Farm   para que pueda coger todos los datos y variables del documento y sea mas facil de llegar
#include "OrcBoss.h"                                                                   //Incluimos el .h del OrcBoss  para que pueda coger todos los datos y variables del documento y sea mas facil de llegar

using namespace std;    

ostream& operator<<(ostream& os, const Mascota& mascota);                              //Guardaremos en operadores los datos necesarios de las constantes de Mascota

int main()                                                                             //El main principal donde ejecutara el codigo
{
	Mascota miMascota;                                                                 //Creamos una variable llamada miMascota para poder guardar el nombre de la primera mascota al inciar el juego
	Mascota* pMiMascota;                                                               //Creamos una variable llamada pMimascota para cuando queramos crear una nueva mascota

	cout << R"(   _______       __  __          _____  ____ _______ _____ _    _ _____ 
 |__   __|/\   |  \/  |   /\   / ____|/ __ \__   __/ ____| |  | |_   _|
    | |  /  \  | \  / |  /  \ | |  __| |  | | | | | |    | |__| | | |  
    | | / /\ \ | |\/| | / /\ \| | |_ | |  | | | | | |    |  __  | | |  
    | |/ ____ \| |  | |/ ____ \ |__| | |__| | | | | |____| |  | |_| |_ 
    |_/_/    \_\_|  |_/_/    \_\_____|\____/  |_|  \_____|_|  |_|_____|
                                                                       
        )" << '\n';
	cout << "!!!Bienvenido al juego de tu mascota!!!!" << endl;

	Farm granja(3);                                                                   //Creamos la variable de granja para poder guardas las mascotas, en mi caso he querido un limite de 3 mascotas                       
	int opcion, valor;                                                                //Creamos la variable de integer y valor para poder introducir la opcion deseada mas tarde cuando salga el menu 
	OrcBoss* jefeOrc = nullptr;                                                       //Declara un puntero llamado jefeOrc del tipo OrcBoss y no apuntara a ningun objeto de tipo OrcBoss

	do                                                                                // Hacemos un do while(bucle), para que vaya haciendo todo esto
	{
		cout << "***********************************" << endl;                        //Menu que nos saldra con las opciones que podemos escoger
		cout << "0 - Salir" << endl;
		cout << "1 - Prestar atencion a tus mascota" << endl;
		cout << "2 - Alimentar a tus mascota" << endl;
		cout << "3 - Jugar con tus mascota" << endl;
		cout << "4 - Robar sus juguetes" << endl;
		cout << "5 - Detalles mascotas" << endl;
		cout << "6 - Crea una nueva mascota" << endl;
		cout << "7 - Saluda a tu orco" << endl;
		cout << "***********************************" << endl; 

		cout << "Introduce la opcion deseada " << endl;
		cin >> opcion;                                                               //Aqui guardaremos en el sistema la opcion que hemos deseado y dependiendo de que pongamos abrirá un switch casa.

		switch (opcion)                                                              //Hacemos un switch case para poder introducir nuestras funciones para cada opcion que deseamos hacer 
		{
		case 0:                                                                      //El case 0 es para poder salir del programa y se cierre el bucle infinito
			cout << "Saliendo del programa.\n";
			break;
		case 1:                                                                      //En el primer caso, tenemos la opcion de hablar con la mascota y pode subirle el animo
			miMascota.Talk();
			break;
		case 2:                                                                      //El segundo caso, es para poder alimentar tu mascota y subirle el hambre
			miMascota.Eat(); 
			break;
		case 3:                                                                      //El tercer caso, es para poder jugar con tu mascota y subirle el animo 
			miMascota.Play();
			break;
		case 4:                                                                      //El cuarto caso, es para poder enfadar a tu mascota a traves de robandole sus juguetes. 
			miMascota.Anger(10);
			break; 
		case 5:                                                                      //El quinto caso, es para poder reproducir los detalles de cada mascota a traves de los operadores
			granja.RollCall();
			break;
		case 6:
			cout << "Que valor quieres poner a la mascota?" << endl;                 //Un simple cout para pedir al usuario que valores quiere poner a la mascota
			cin >> valor;
			pMiMascota = new Mascota(valor,6);                                       //Cada vez que creemos una mascota diferente, le pondremos nosotros los valores iniciales
			granja.Add(pMiMascota);                                                  //Y se añadira en el array de la granja. 
			break;
		case 7:                                                                      //El septimo caso es para poder saludar al orco que nos encontramos por el camino
			jefeOrc = new OrcBoss();                                                 // Inicialización solo en el caso 7
			jefeOrc->Greet();                                                        // Llamamos al método Greet
			break;
		default:
			cout << "\nLo siento, pero" << opcion << "no es valida \n";
		}	

	} while (opcion != 0);                                                          //Haga todo esto sin parar hasta que introduzcamos un 0 y parara el programa

	return 0; 
}


/// <summary>
/// Operador para poder imprimir por pantalla los datos necesarios
/// de cada mascota. 
/// </summary>
/// <param name="os">Operadores</param>
/// <param name="mascota">Variable que le asociamos a la mascota</param>
/// <returns></returns>
ostream& operator<<(ostream& os, const Mascota& mascota)
{
	os << "Nombre: " << mascota.nombre << ", Hambre: " << mascota.m_Hunger << ", Aburrimiento: " << mascota.m_Boredom << ", Rabia: " << mascota.m_anger;  //Operadores para que pueda regresar los datos de nombre, hambre, aburrimiento y rabia.
	return os;
}


