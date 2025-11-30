/****************************************************
 Nombre del programa: Cálculo del RFC
 Autor: Alan Gastelum
 Fecha: 28/11/2025
*****************************************************/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// ****************************************************
// * Diccionario de palabras NO permitidas
// ****************************************************
const vector<string> palabrasProhibidas = {
    "PEDO", "POPO", "PENE", "LOCO", "CACA", "PUTO", "MAMO", "CULO", "QULO",
    "TETA", "JOTO", "VERG", "KAKA", "CAGO", "CAGA", "FETO", "PUTA", "RUIN",
    "COGE", "COJE", "KULO", "MION", "PITO", "VAGO", "VAGA", "SENO"
};

// ****************************************************
// * Función para convertir una cadena COMPLETA a MAYÚSCULAS
// ****************************************************
string convertirMayusculas(const string& texto) {
    string resultado = texto;
    for (char& c : resultado) {
        c = toupper(c);
    }
    return resultado;
}

// ****************************************************
// * Verificar y modificar palabras prohibidas del diccionario
// ****************************************************
string corregirRFC(const string& rfc) {
    for (const string& palabra : palabrasProhibidas) {
        if (rfc == palabra) {
            return rfc.substr(0, 3) + "X";  // Reemplaza la última letra por 'X'
        }
    }
    return rfc;
}

// ****************************************************
// * Función para obtener la primera vocal interna de una cadena
// ****************************************************
char obtenerPrimeraVocalInterna(const string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = toupper(str[i]);  // Conversión a MAYÚSCULA
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return c;
        }
    }
    return 'X'; // Si no encuentra una vocal interna, se usa una X
}

// ****************************************************
// * Función principal para calcular el RFC del empleado
// ****************************************************
string calcularRFC(
    const string& nombre,
    const string& apellidoPaterno,
    const string& apellidoMaterno,
    const string& fechaNacimiento)
{
    //*** Se declara la variable donde guardaremos el RFC
    string rfc;

    // *** Se obtiene la letra inicial y la primera vocal interna del apellido paterno ***
    char letraInicial = apellidoPaterno[0];
    char primeraVocal = obtenerPrimeraVocalInterna(apellidoPaterno);

    // *** Se obtiene la inicial del apellido materno o se usa una X si no existe ***
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';

    // *** Se obtiene la inicial del primer nombre ***
    char inicialNombre = nombre[0];

    // *** Se obtiene año, mes y día de nacimiento***
    string anio = fechaNacimiento.substr(2, 2);
    string mes = fechaNacimiento.substr(5, 2);
    string dia = fechaNacimiento.substr(8, 2);

    // *** Se construye el RFC sumando el texto de la información proporcionada ***
    rfc += letraInicial;
    rfc += primeraVocal;
    rfc += inicialApellidoMaterno;
    rfc += inicialNombre;

    // *** Se ejecuta la comparación de malas palabras en el diccionario y se sustituye con una X ***
    rfc = corregirRFC(rfc);

    // *** Realizar la corrección y se continúa creando el RFC ***
    rfc += anio;
    rfc += mes;
    rfc += dia;

    return rfc;
}

// ****************************************************
// * MAIN
// ****************************************************
int main() {

    string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;

    cout << "Introduce tu nombre: ";
    getline(cin, nombre);

    cout << "Introduce tu apellido paterno: ";
    getline(cin, apellidoPaterno);

    cout << "Introduce tu apellido materno (si no cuentas con apellido materno presiona ENTER): ";
    getline(cin, apellidoMaterno);

    cout << "Introduce tu fecha de nacimiento en el formato (YYYY-MM-DD): ";
    getline(cin, fechaNacimiento);

    // Convertir entradas a MAYÚSCULAS
    nombre = convertirMayusculas(nombre);
    apellidoPaterno = convertirMayusculas(apellidoPaterno);
    apellidoMaterno = convertirMayusculas(apellidoMaterno);

    // Calcular RFC
    string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);

    cout << "\nRFC: " << rfc << endl;

    system("pause");
    return 0;
}