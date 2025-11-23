/****************************************************
 Nombre del programa: Operaciones Básicas
 Autor: Alan Gastelum
 Fecha: 22 de Noviembre de 2025
*****************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    float num1, num2;

    cout << "Escribe el primer numero: ";
    cin >> num1;

    cout << "Escribe el segundo numero: ";
    cin >> num2;

    float suma = num1 + num2;
    float resta = num1 - num2;
    float multiplicacion = num1 * num2;
    float division = num1 / num2;

    cout << "\nResultados:\n";
    cout << "\nLa suma es: " << suma << endl;
    cout << "La resta es: " << resta << endl;
    cout << "La multiplicacion es: " << multiplicacion << endl;
    cout << "La division es: " << division << endl;
    cout << "\n";

    system("pause");
    return 0;
}