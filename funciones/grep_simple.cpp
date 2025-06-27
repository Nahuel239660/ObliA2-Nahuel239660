#include <string>
using namespace std;

// Verifica si el texto coincide con el patrón usando programación dinámica
// dp[i][j] = true si texto[0...i-1] coincide con patrón[0...j-1]
bool grepSimple(const string& texto, const string& patron) {
    int n = texto.length(), m = patron.length();
    bool dp[1001][1001] = {false};
    
    // Caso base: texto vacío y patrón vacío coinciden
    dp[0][0] = true;
    
    // Llenar primera fila: texto vacío con patrón
    for (int j = 1; j <= m; j++) {
        if (patron[j-1] == '*') {
            dp[0][j] = dp[0][j-2]; // * puede ser 0 repeticiones
        }
    }
    
    // Llenar la matriz DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (patron[j-1] == '.' || patron[j-1] == texto[i-1]) {
                // Carácter coincide o es .
                dp[i][j] = dp[i-1][j-1];
            } else if (patron[j-1] == '*') {
                // Caso especial: *
                dp[i][j] = dp[i][j-2]; // 0 repeticiones
                if (patron[j-2] == '.' || patron[j-2] == texto[i-1]) {
                    // 1 o más repeticiones
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
        }
    }
    
    return dp[n][m];
} 