#include "../tads/ejercicio6.h"
#include <cstring>

// Fusiona dos siluetas ordenadas por x. Elimina alturas duplicadas.
void fusionarSiluetas(Punto* sil1, int n1, Punto* sil2, int n2, Punto* res, int& nRes) {
    int i = 0, j = 0, h1 = 0, h2 = 0;
    nRes = 0;
    while (i < n1 && j < n2) {
        int x1 = sil1[i].x, x2 = sil2[j].x;
        if (x1 < x2) {
            h1 = sil1[i].altura;
            int h = h1 > h2 ? h1 : h2;
            if (nRes == 0 || res[nRes-1].altura != h) {
                res[nRes].x = x1;
                res[nRes].altura = h;
                nRes++;
            }
            i++;
        } else if (x2 < x1) {
            h2 = sil2[j].altura;
            int h = h1 > h2 ? h1 : h2;
            if (nRes == 0 || res[nRes-1].altura != h) {
                res[nRes].x = x2;
                res[nRes].altura = h;
                nRes++;
            }
            j++;
        } else {
            h1 = sil1[i].altura;
            h2 = sil2[j].altura;
            int h = h1 > h2 ? h1 : h2;
            if (nRes == 0 || res[nRes-1].altura != h) {
                res[nRes].x = x1;
                res[nRes].altura = h;
                nRes++;
            }
            i++; j++;
        }
    }
    while (i < n1) {
        h1 = sil1[i].altura;
        int h = h1 > h2 ? h1 : h2;
        if (nRes == 0 || res[nRes-1].altura != h) {
            res[nRes].x = sil1[i].x;
            res[nRes].altura = h;
            nRes++;
        }
        i++;
    }
    while (j < n2) {
        h2 = sil2[j].altura;
        int h = h1 > h2 ? h1 : h2;
        if (nRes == 0 || res[nRes-1].altura != h) {
            res[nRes].x = sil2[j].x;
            res[nRes].altura = h;
            nRes++;
        }
        j++;
    }
}

// Crea la silueta de un solo edificio
void siluetaEdificio(const Edificio& e, Punto* res, int& nRes) {
    res[0].x = e.inicio;
    res[0].altura = e.altura;
    res[1].x = e.fin;
    res[1].altura = 0;
    nRes = 2;
}

// Divide & Conquer para resolver el skyline
void skyline(Edificio* edificios, int ini, int fin, Punto* res, int& nRes) {
    if (ini == fin) {
        siluetaEdificio(edificios[ini], res, nRes);
        return;
    }
    int mid = (ini + fin) / 2;
    Punto sil1[1000], sil2[1000];
    int n1, n2;
    skyline(edificios, ini, mid, sil1, n1);
    skyline(edificios, mid+1, fin, sil2, n2);
    fusionarSiluetas(sil1, n1, sil2, n2, res, nRes);
} 