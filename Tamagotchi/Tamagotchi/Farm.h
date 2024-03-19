#pragma once                           // Directiva para evitar la inclusi�n m�ltiple del archivo de encabezado
#include "Mascota.h"                   // Incluye el archivo de encabezado "Mascota.h"
#include <vector>                      // Incluye la librer�a de vector

/// <summary>
/// 
/// </summary>
class Farm
{
public:
    Farm(int spaces = 1);             // Constructor de Farm con par�metro opcional para el espacio
    void Add(Mascota* nuevaMascota);  // M�todo para agregar una nueva mascota
    void RollCall() const;            // M�todo para mostrar las mascotas en la granja

private:
    int m_spaces;                     // Variable para almacenar el n�mero de espacios
    vector<Mascota*> m_mascotas;      // Vector para almacenar punteros a las mascotas
};
