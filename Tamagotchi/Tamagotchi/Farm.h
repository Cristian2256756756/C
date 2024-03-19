#pragma once                           // Directiva para evitar la inclusión múltiple del archivo de encabezado
#include "Mascota.h"                   // Incluye el archivo de encabezado "Mascota.h"
#include <vector>                      // Incluye la librería de vector

/// <summary>
/// 
/// </summary>
class Farm
{
public:
    Farm(int spaces = 1);             // Constructor de Farm con parámetro opcional para el espacio
    void Add(Mascota* nuevaMascota);  // Método para agregar una nueva mascota
    void RollCall() const;            // Método para mostrar las mascotas en la granja

private:
    int m_spaces;                     // Variable para almacenar el número de espacios
    vector<Mascota*> m_mascotas;      // Vector para almacenar punteros a las mascotas
};
