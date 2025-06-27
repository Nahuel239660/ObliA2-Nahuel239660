#include <string>
using namespace std;

// Devuelve el palíndromo numérico más grande posible usando todas las cifras de s, o "No" si no se puede
string palindromoMayor(const string& s) {
    int freq[10] = {0};
    for (int i = 0; i < (int)s.length(); i++) freq[s[i]-'0']++;
    int impares = 0, digImpar = -1;
    for (int d = 0; d < 10; d++) {
        if (freq[d] % 2 != 0) {
            impares++;
            digImpar = d;
        }
    }
    if (impares > 1) return "No";
    string mitad = "";
    for (int d = 9; d >= 0; d--) {
        for (int k = 0; k < freq[d]/2; k++) mitad += (char)(d+'0');
    }
    if (mitad.length() > 0 && mitad[0] == '0') return "0";
    string res = mitad;
    if (digImpar != -1) res += (char)(digImpar+'0');
    for (int i = mitad.length()-1; i >= 0; i--) res += mitad[i];
    if (res.length() == 0) res = s;
    return res;
} 