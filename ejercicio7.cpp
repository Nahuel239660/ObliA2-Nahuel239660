// ejercicio7.cpp
// Entrada/salida y llamado a la función de palíndromo mayor
#include <iostream>
#include <string>
#include "funciones/palindromo_mayor.h"
using namespace std;

int main() {
    string num;
    cin >> num;
    // Llamo a la función que construye el palíndromo más grande
    string res = palindromoMayor(num);
    cout << res << endl;
    return 0;
}