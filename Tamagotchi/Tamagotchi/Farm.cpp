#include "Farm.h"                                                                                    //Incluimos el .h del Farm   para que pueda coger todos los datos y variables del documento y sea mas facil de llegar
#include <iostream>                                                                                  //Incluimos la libreria de iostream para poder hacer las entradas y salidas
#include <string>                                                                                    //
#include <ctime>

using namespace std;

Farm::Farm(int spaces) : m_spaces(spaces) {}                              
/// <summary>
/// Funcion principal de la granja para poder añadir mascotas nuevas 
/// </summary>
/// <param name="nuevaMascota">Public class del .h</param>
void Farm::Add(Mascota* nuevaMascota)
{
    string nombreMascota;                                                                             //Crearemos una variable tipo string para poder guardar el nombre de la mascota nueva que queremos hacer

    cout << "............................................................" << endl;                  //Preguntas al usuario de que nombre querra tener
    cout << "Para poder empezar a jugar, necesito que crees tus tres mascota iniciales" << endl;
    cout << "............................................................" << endl;
    cout << "Que nombre quieres ponerle a la mascota?" << endl;
    cin >> nombreMascota;

    nuevaMascota->nombre = nombreMascota;                                                             //Escogeremos el parametro de nuevaMascota para poder introducirlo en mascota.nombre dentro del operador y le igualaremos el nombre que pongamos por pantalla

    if (m_mascotas.size() < m_spaces)                                                                 //Bucle principal para poder cojer el tamaño de las mascota y su espacio en la array
    {
        m_mascotas.push_back(nuevaMascota);                                                           //Haremos el pushback para poder introducir la variable privada en nuevaMascota
        cout << "Se ha añadido una nueva mascota a la granja en la dirección: " << nuevaMascota << endl;   
        cout << R"( 
          .^._.^.
          | . . |
         (  ---  )
         .'     '. Hola buenas tardes
         |/     \|
          \ /-\ /
           V   V
        )" << '\n';
        cout << nombreMascota << endl;     
    }
    else                                                                                             //Cuando lleguemos al maximo de tres mascotas, si intentamos hacer otra mascota mas, nos saldra este error
    {
        cout << "No hay espacio suficiente en la granja para añadir más mascotas." << endl;
    }
}
/// <summary>
/// Funcion donde reproduciremos por pantalla los datos de cada mascota
/// </summary>
void Farm::RollCall() const
{
    cout << "Mascotas en la granja:" << endl;                                                       //Un simple cout R para que sea mas bonito
    cout << R"( 
                      /^--^\     /^--^\     /^--^\
                      \____/     \____/     \____/
                     /      \   /      \   /      \
                    |        | |        | |        |
                     \__  __/   \__  __/   \__  __/
|^|^|^|^|^|^|^|^|^|^|^|^\ \^|^|^|^/ /^|^|^|^|^\ \^|^|^|^|^|^|^|^|^|^|^|^|
| | | | | | | | | | | | |\ \| | |/ /| | | | | | \ \ | | | | | | | | | | |
| | | | | | | | | | | | / / | | |\ \| | | | | |/ /| | | | | | | | | | | |
| | | | | | | | | | | | \/| | | | \/| | | | | |\/ | | | | | | | | | | | |
#########################################################################
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
        )" << '\n';
    cout << endl;
    for (const auto& mascota : m_mascotas)                                                            //Bucle principal donde coje las constantes de la mascota, de m_mascotas
    { 
      cout << *mascota << " (Direccion: " << mascota << ")" << endl;                                  //Y imprime por pantalla la dirrecion de ellas.
    }
}
