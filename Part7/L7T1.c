// L7T1: Askelanalyysi, tiedostonkäsittely useassa tiedostossa

#include <stdio.h>
#include "L7T1_io.h"

int main() {
    int aLista[10];
    int iRivienMaara = 10;

    printf("Askelanalyysi\n");
    int iSumma = lueAskeleetListaan(aLista, &iRivienMaara);
    if (iSumma == -1) {
        return 1;
    }

    tulostaLista(aLista, iRivienMaara);
    printf("Askelia yhteensä: %d\n", iSumma);
    printf("Kiitos ohjelman käytöstä.");

    return 0;
}