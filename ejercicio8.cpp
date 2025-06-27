#include <iostream>
#include <string>
#include "funciones/grep_simple.h"
using namespace std;

int main() {
    string texto, patron;
    getline(cin, texto);
    getline(cin, patron);
    
    // Llamo a la función que verifica si coinciden
    bool coincide = grepSimple(texto, patron);
    
    cout << (coincide ? "true" : "false") << endl;
    return 0;
}