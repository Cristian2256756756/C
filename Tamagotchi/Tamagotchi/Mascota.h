#pragma once
#include <iostream>                                                   //Para utilizar la entrada y salida
#include <string>                                                     //Libreria para poder utilizar los strings, en nuestro caso para el nombre de la mascota
using namespace std;                                                  //Ahorrarse el std al principio de las frases

class Mascota
{
public:
	Mascota(int hunger = 0, int boredom = 0);                        // Constructor de Mascota con parámetros predeterminados para hambre y aburrimiento
	void Talk();                                                     //Para que la mascota hable
	void Eat(int food = 4);                                          //Para que la mascota coma
	void Play(int fun = 4);                                          //Para que la mascota juegue
	void Anger(int enfado);                                          //Para que la mascota se enfade cuando le robemos los juguetes
	//Mascota& operator=(const Mascota& otraMascota);
	friend ostream& operator<<(ostream& os, const Mascota& mascota); //sobrecarga el operador de inserción para mostrar detalles de la mascota
	string nombre;                                                   //String para poder guardar el nombre de las mascotas creadas

private:
	int m_Hunger;                                                    //Para el hambre de la mascota
	int m_Boredom;                                                   //Para el aburrimiento de la mascota
	int m_anger;                                                     //Para el enfado de la mascota
	int GetMood() const;                                             //Para el animo de la mascota
	void PassTime(int time = 1);                                     //Para que se vaya pasando el tiempo y los valores cambien de manera automatica
};