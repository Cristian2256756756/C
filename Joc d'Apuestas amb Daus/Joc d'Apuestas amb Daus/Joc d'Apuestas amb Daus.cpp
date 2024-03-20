#include <iostream>
#include <cstdlib>                                                                   //LLibreria para el random
#include <ctime>                                                                     //LLibreria para el tiempo 

using namespace std;

void processaAposta(int aposta, int sumaDaus, int& saldo);                           //Declaramos una funcion para poder calcular las apeustas 
int llancaDau();                                                                     //Declaramos una funcio int para poder lanzar el dado                         

int main()
{
	int opcion;                                                                      //Variable para poder escoger las diferentes opcioens que es dado
    int saldoInicial = 100;                                                          //Variable con la que empezamos el saldo inicial
    int saldo = saldoInicial;                               
    srand(static_cast<unsigned int>(time(0)));                                       //El generador de numero aleatroio 

    cout << R"(                                                                    
           _                  _ _                       _                              _           _                          
      | |                | ( )                     | |                            | |         | |                         
      | | ___   ___    __| |/  __ _ _ __   ___  ___| |_ ___  ___    __ _ _ __ ___ | |__     __| | __ _ _   _ ___          
  _   | |/ _ \ / __|  / _` |  / _` | '_ \ / _ \/ __| __/ _ \/ __|  / _` | '_ ` _ \| '_ \   / _` |/ _` | | | / __|         
 | |__| | (_) | (__  | (_| | | (_| | |_) | (_) \__ \ ||  __/\__ \ | (_| | | | | | | |_) | | (_| | (_| | |_| \__ \         
  \____/ \___/ \___|  \__,_|  \__,_| .__/ \___/|___/\__\___||___/  \__,_|_| |_| |_|_.__/   \__,_|\__,_|\__,_|___/         
                                   | |                                                                                    
                                   |_|                                                                                    
    )" << '\n';                                                                      //Un codigo ASCII para poder decorar 
	cout << "Bienvenido al juego de las apuestas";
	cout << "";

    while (saldo > 0) {                                                              //Bucle donde el juego no se acabe hasta que escribas 0
        cout << "Saldo actual: " << saldo << " €\n";                                 //Opciones que nos saldria por pantalla
        cout << "Opcio 1 - Place Bet\n";
        cout << "Opcio 2 - Exit\n";

        int opcio;                                                                  //Creamos la variabl de opcion 
        cout << "Selecciona una opcio: ";
        cin >> opcio;                                                               //Introducimos manualmente la opcion deseada

        if (opcio == 1) {                                                          //Si la opcion es igual a 1
            int aposta;
            cout << "Introdueix la quantitat que vols apostar: ";
            cin >> aposta;

            if (aposta > saldo) {
                cout << "No pots apostar més del que tens. Torna-ho a provar.\n";
                continue;
            }

            int sumaDaus = llancaDau() + llancaDau();
            cout << "Resultat del llançament dels daus: " << sumaDaus << endl;

            processaAposta(aposta, sumaDaus, saldo);
        }
        else if (opcio == 2) {
            cout << "Gràcies per jugar! Has sortit del joc.\n";
            break;
        }
        else {
            cout << "Opció no vàlida. Torna-ho a provar.\n";
        }
    }

    cout << "Has quedat sense diners. Fins aviat!\n";

    return 0;
}



int llancaDau() {
    return rand() % 20 + 1;
}

void processaAposta(int aposta, int sumaDaus, int& saldo) {
    if (aposta == sumaDaus) {
        saldo += 10 * aposta;
        cout << "Has guanyat 10 vegades la teva aposta!\n";
    }
    else if (abs(aposta - sumaDaus) <= 1) {
        saldo += 2 * aposta;
        cout << "Has guanyat 2 vegades la teva aposta!\n";
    }
    else if (abs(aposta - sumaDaus) <= 2) {
        saldo += aposta;
        cout << "Has guanyat 1 vegada la teva aposta!\n";
    }
    else {
        saldo -= aposta;
        cout << "Has perdut la teva aposta.\n";
    }
}





