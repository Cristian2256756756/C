#include "Mascota.h"                                                       //Incluye el archivo de OrcBoss.h
#include <iostream>                                                        //Para utilizar la entrada y salida

using namespace std;

/// <summary>
/// Funcion para poder alimentar a la mascota
/// </summary>
/// <param name="platComido"></param>
void Mascota::Eat(int platComido) {

    cout << "Tu mascota esta comiendo" << endl;
	m_Hunger += platComido;                                              //Cojeremos el m_Hunger, que lo declaramos en el privado del .h y me pondremos un += a platComido, para que vaya sumando
    PassTime();                                                          //Para que con el tiempo jugando y pulsando botones vaya variando
}


/// <summary>
/// Funciona para poder jugar con tu mascota y subirle el estado de animo
/// Diferentes if else donde tendra un cout o otro
/// por cada valor concreto
/// </summary>
/// <param name="tiempoJuego"></param>
void Mascota::Play(int tiempoJuego ) {

    m_Boredom += tiempoJuego;                                            //Cojeremos el m_Boredom, que lo declaramos en el privado del .h y me pondremos un += a tiempoJuego, para que vaya sumando        
    cout << "Jugando con tu mascota" << endl;

    if (m_Boredom < 0) {
        m_Boredom = 0;
    }

    if (GetMood() > 10) { 
        cout << "¡Tu mascota está muy feliz!" << endl;
    }
    else if (GetMood() > 6) {
        cout << "Tu mascota está contenta." << endl;
    }
    else {
        cout << "Tu mascota se divirtió un poco." << endl;
    }
    PassTime();                                                        //Para que con el tiempo jugando y pulsando botones vaya variando
}


/// <summary>
/// Funcion para la opcion de enfado de la mascota
/// Diferentes if else donde tendra un cout o otro
/// por cada valor concreto
/// </summary>
/// <param name="enfado"></param>
void Mascota::Anger(int enfado) {
    m_anger += enfado;                                                //Cojeremos el m_anger, que lo declaramos en el privado del .h y me pondremos un += a enfado, para que vaya sumando

    if (m_anger < 0) {
        m_anger = 0;
    }

    if (m_anger > 7) {
        cout << "¡Tu mascota está muy enfadada!" << endl;
    }
    else if (m_anger > 4) {
        cout << "Tu mascota está un poco enfadada." << endl;
    }
    else {
        cout << "Tu mascota no está demasiado enfadada." << endl;
    }
    PassTime();                                                       //Para que con el tiempo jugando y pulsando botones vaya variando
}


/// <summary>
/// Funcion para el aburrimiento de la mascota
/// Diferentes if else donde tendra un cout o otro
/// por cada valor concreto
/// </summary>
void Mascota::Talk() {
   
    cout << "Tu mascota te escucha detalladamente" << endl;

    if (m_Hunger > 7) {
        cout << "Estoy muy hambriento.";
    }
    else if (m_Hunger > 4) {
        cout << "Tengo hambre.";
    }
    else {
        cout << "Estoy bien alimentado.";
    }
    if (m_Boredom > 7) {
        cout << " Estoy muy aburrido.";
    }
    else if (m_Boredom > 4) {
        cout << " Estoy un poco aburrido.";
    }
    else {
        cout << " Estoy bien entretenido.";
    }
    cout << endl;

    PassTime();                                                       //Para que con el tiempo jugando y pulsando botones vaya variando
}


/// <summary>
/// Funcion para que se vaya variando el valor de las variable con el tiempo jugando
/// </summary>
/// <param name="tiempo"></param>
void Mascota::PassTime(int tiempo)
{
    m_Hunger += tiempo;                                             //Cojeremos el m_Hunger, que lo declaramos en el privado del .h y me pondremos un += al integer de tiempo, para que vaya sumando
    m_Boredom += tiempo;                                            //Cojeremos el m_Boredom, que lo declaramos en el privado del .h y me pondremos un += al integer de tiempo, para que vaya sumando
    m_anger += tiempo;                                              //Cojeremos el m_anger, que lo declaramos en el privado del .h y me pondremos un += al integer de tiempo, para que vaya sumando
}


Mascota::Mascota(int hunger, int boredom) : m_Hunger(hunger), m_Boredom(boredom) { m_anger = 10; }

inline int Mascota::GetMood() const
{
	return (m_Hunger + m_Boredom);
}


