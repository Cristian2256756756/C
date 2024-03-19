#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

typedef struct _GifHeader
{
                                                                                                  // Header
    BYTE Signature[3];                                                                           /* Header Signature (always "GIF") */
    BYTE Version[3];                                                                             /* GIF format version("87a" or "89a") */
                                                                                                    // Logical Screen Descriptor
    WORD ScreenWidth;                                                                             /* Width of Display Screen in Pixels */
    WORD ScreenHeight;                                                                          /* Height of Display Screen in Pixels */
    BYTE Packed;                                                                                  /* Screen and Color Map Information */
    BYTE BackgroundColor;                                                                           /* Background Color Index */
    BYTE AspectRatio;                                                                             /* Pixel Aspect Ratio */
} GIFHEAD;

int main() {
    string nombre;
    cout << "GIF File Reader" << endl;
    cout << "Enter the file name: ";
    getline(cin, nombre);
    ifstream fichero(nombre.c_str(), ios::binary);
    if (fichero.fail()) {
        cout << "File not found" << endl;
        return  1;
    }

    char signature[4];                                                                          // 4 to include the null terminator
    char version[4];                                                                            // 4 to include the null terminator
    unsigned short screenWidth;
    unsigned short screenHeight;
    BYTE packed;
    BYTE backgroundColor;
    BYTE aspectRatio;

                                                                                                 // Read the GIF signature
    fichero.read(signature, 3);
    signature[3] = '\0';                                                                            // Null-terminate the string

                                                                                                 // Read the version
    fichero.read(version, 3);
    version[3] = '\0';                                                                           // Null-terminate the string                                                                              
    fichero.seekg(4, ios::cur);                                                                 // Skip the global color table flag and background color index
    fichero.read(reinterpret_cast<char*>(&screenWidth), 2);                                     // Read the screen width
    fichero.read(reinterpret_cast<char*>(&screenHeight), 2);                                    // Read the screen height
    fichero.read(reinterpret_cast<char*>(&packed), 1);
    fichero.read(reinterpret_cast<char*>(&backgroundColor), 1);
    fichero.read(reinterpret_cast<char*>(&aspectRatio), 1);

    cout << "Signature: " << signature << endl;
    cout << "Version: " << version << endl;
    cout << "Screen Width: " << screenWidth << endl;
    cout << "Screen Height: " << screenHeight << endl;
    cout << "Packed: " << static_cast<int>(packed) << endl;
    cout << "Background Color Index: " << static_cast<int>(backgroundColor) << endl;
    cout << "Aspect Ratio: " << static_cast<int>(aspectRatio) << endl;

                                                                                                // Get the color count (based on the number of bits in Packed field)
    int colorCount = 1 << ((packed & 0x07) + 1);
    cout << "Color Count: " << colorCount << endl;

                                                                                                // Copy the content to a new file
    cout << "Do you want to duplicate the file? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the new file name: ";
        string newFileName;
        cin.ignore();                                                                           // Ignore the newline character left in the buffer
        getline(cin, newFileName);

        ofstream newFile(newFileName.c_str(), ios::binary);

                                                                                                // Read the entire content of the original file and write it to the new file
        vector<char> buffer(4096, 0);                                                           // 4 KB buffer
        while (!fichero.eof()) {
            fichero.read(buffer.data(), buffer.size());
            newFile.write(buffer.data(), fichero.gcount());
        }

        newFile.close();
        cout << "File duplicated successfully." << endl;
    }

    fichero.close();
    return  0;
}
