/****************************************************
 Nombre del programa: Mayor de Edad
 Autor: Alan Gastelum
 Fecha: 17 de Noviembre de 2025
*****************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    system("color 0A");
    string nombre;
    int edad;

    cout << "Ingresa tu nombre: ";
    getline(cin, nombre);

    cout << "\nIngresa tu edad: ";
    cin >> edad;

    cout << "\n";

    if (edad >= 18) {
        cout << "Bienvenido " << nombre << ", eres mayor de edad.\n\n";
    }
    else {
        cout << "Bienvenido " << nombre << ", eres menor de edad.\n\n";
    }

    system("pause");
    return 0;
}
