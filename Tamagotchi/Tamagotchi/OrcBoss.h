#pragma once                        //Directiva para evitar la inclusión múltiple del archivo de encabezado
#include "Orc.h"                    //Incluye el archivo de Orc.h

/// <summary>
/// Clase OrcBoss que hereda de la clase de Orc
/// </summary>
class OrcBoss : public Orc 
{
public:
    OrcBoss();                     //Constuctor de OrcBoss
    virtual void Greet() const;    //Funciona virtual para poder saludar al orco

};            
