#include "OrcBoss.h"                    //Incluye el archivo de OrcBoss.h
#include <iostream>                     //Para utilizar la entrada y salida

using namespace std;                    //Ahorrarse el std al principio de las frases

OrcBoss::OrcBoss() {}                  //Constructor de OrcBoss

/// <summary>
/// Implementaremos la funcion de saludar al OrcBoss
/// </summary>
void OrcBoss::Greet() const
{
    cout << "El orco gruñe de vuelta con cara de enfado" << endl;     //Cuando lo saludemos, que nos salga este mensaje por pantalla
}