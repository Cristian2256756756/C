#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct Serie {
    string titulo;
    int numEpisodios;
    int numPersonajes;
};
/// <summary>
/// Funcion para poder 
/// </summary>
/// <param name="archivo"></param>
void agregarSerie(fstream& archivo) {
    Serie serieLeida;

    cout << " Introduce el titulo de la serie" << endl;
    cin >> serieLeida.titulo;
    cout << " Cuantos episodios tiene?" << endl;
    cin >> serieLeida.numEpisodios;
    cout << " Cuantos personajes tiene?" << endl;
    cin >> serieLeida.numPersonajes;

     archivo.write((char*)&serieLeida, sizeof(serieLeida));
}
/// <summary>
/// Funcion para poder 
/// </summary>
/// <param name="serie"></param>
void mostrarSerie(const Serie& serie) {
    cout << "Titulo: " << serie.titulo << endl;
    cout << "Episodios: " << serie.numEpisodios << endl;
    cout << "Personajes: " << serie.numPersonajes << endl;
    cout << "---------------------------" << endl;
}

int main() {

    int opcion;
    const char* nombreArchivo = "archivo_binario.dat";
    fstream archivo(nombreArchivo, ios::in | ios::out | ios::binary | ios::trunc);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para lectura/escritura." << endl;
        return 1;
    }
    Serie serieLeida;

    do {
        cout << "1. *Agregar Serie*" << endl;
        cout << "2. *Series*" << endl;
        cout << "3. *Borrar Serie*" << endl;
        cout << "0. *Salir del programa*" << endl;

        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
                case 1: 
                    archivo.seekp(0, ios::end); 
                    agregarSerie(archivo);
                    cout << "Serie agregada exitosamente." << endl;
                    cout << endl;
                    break;
                case 2:  
                    archivo.seekg(0, ios::beg); 
                    while (archivo.read(reinterpret_cast<char*>(&serieLeida), sizeof(Serie))) {
                     mostrarSerie(serieLeida);
                        }
                    break;
                case 3: 
                    cout << "Que serie quiere borrar?";
                    break;
                case 0:
                    cout << "Saliendo del programa";
                    break;
                default:
                    cerr << "Opcion no valida." << endl;
                    break;
        }

    } while (opcion != 0);


    archivo.close();

    return 0;
}
